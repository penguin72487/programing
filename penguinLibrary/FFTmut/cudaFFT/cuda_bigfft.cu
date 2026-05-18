// cuda_bigfft.cu
#include <cuda_runtime.h>
#include <cufft.h>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdint>
#include <cassert>
#ifdef ENABLE_TIMING
    #include <chrono>
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto durat = duration_cast<nanoseconds>(stop - start);
#endif

using std::uint32_t;
using std::uint64_t;
using std::int64_t;

#define CUDA_CHECK(call) do {                                 \
    cudaError_t _e = (call);                                  \
    if (_e != cudaSuccess) {                                  \
        std::cerr << "CUDA error: " << cudaGetErrorString(_e)  \
                  << " @ " << __FILE__ << ":" << __LINE__      \
                  << std::endl;                                \
        std::exit(1);                                         \
    }                                                         \
} while(0)

#define CUFFT_CHECK(call) do {                                \
    cufftResult _r = (call);                                  \
    if (_r != CUFFT_SUCCESS) {                                \
        std::cerr << "cuFFT error: " << int(_r)               \
                  << " @ " << __FILE__ << ":" << __LINE__      \
                  << std::endl;                                \
        std::exit(1);                                         \
    }                                                         \
} while(0)

// ============================
// 1) GPU kernels
// ============================

// (A * B) pointwise on device
__global__ void pointwise_mul(const cufftDoubleComplex* __restrict__ A,
                              const cufftDoubleComplex* __restrict__ B,
                              cufftDoubleComplex* __restrict__ C,
                              uint32_t n)
{
    uint32_t i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i >= n) return;

    double ar = A[i].x, ai = A[i].y;
    double br = B[i].x, bi = B[i].y;

    // (ar + i ai) * (br + i bi)
    C[i].x = ar * br - ai * bi;
    C[i].y = ar * bi + ai * br;
}

// normalize + round to int64 on device
__global__ void normalize_round_to_i64(const cufftDoubleComplex* __restrict__ in,
                                      int64_t* __restrict__ out,
                                      uint32_t n,
                                      double inv_n)
{
    uint32_t i = blockIdx.x * blockDim.x + threadIdx.x;
    if (i >= n) return;

    double x = in[i].x * inv_n;
    // round to nearest
    out[i] = (int64_t)llround(x);
}

// 可選：GPU carry（限制很多，見下方說明）
// 這個版本是「單 block 序列 carry」，只適合 n <= 1,000,000 左右（仍可能慢）
__global__ void carry_base10_inplace(int64_t* __restrict__ a, uint32_t n)
{
    // 單執行緒做序列 carry（保證正確，但不快）
    if (blockIdx.x != 0 || threadIdx.x != 0) return;

    int64_t carry = 0;
    for (uint32_t i = 0; i < n; i++) {
        int64_t v = a[i] + carry;
        if (v >= 0) {
            carry = v / 10;
            a[i] = v % 10;
        } else {
            // 理論上不會負，但保險
            int64_t b = (-v + 9) / 10;
            carry = -b;
            a[i] = v - carry * 10;
        }
    }
    // 超出 n 的 carry 這裡不處理（因為輸出長度會變），我們仍建議 CPU 收尾
}

// ============================
// 2) Helper: parse / format (base10 digits)
// ============================

static std::vector<uint32_t> parse_decimal_to_digits_rev(const std::string& s) {
    // digits reversed, base10
    std::vector<uint32_t> d;
    d.reserve(s.size());
    for (auto it = s.rbegin(); it != s.rend(); ++it) {
        char c = *it;
        if (c < '0' || c > '9') continue;
        d.push_back((uint32_t)(c - '0'));
    }
    if (d.empty()) d.push_back(0);
    // trim
    while (d.size() > 1 && d.back() == 0) d.pop_back();
    return d;
}

static std::string digits_rev_to_string(const std::vector<uint32_t>& d) {
    std::string out;
    out.reserve(d.size());
    for (auto it = d.rbegin(); it != d.rend(); ++it) {
        out.push_back(char('0' + *it));
    }
    // trim leading zeros
    size_t p = 0;
    while (p + 1 < out.size() && out[p] == '0') p++;
    if (p) out.erase(0, p);
    return out;
}

// CPU carry（超穩、超快、工程上最常見）
static std::vector<uint32_t> carry_base10_cpu_from_i64(const std::vector<int64_t>& raw) {
    std::vector<uint32_t> out;
    out.reserve(raw.size() + 4);

    int64_t carry = 0;
    for (size_t i = 0; i < raw.size(); i++) {
        int64_t v = raw[i] + carry;
        // 這裡假設 v >= 0（FFT rounding 偶爾會出現微小負值，可修正）
        if (v < 0) v = 0;

        carry = v / 10;
        uint32_t digit = (uint32_t)(v % 10);
        out.push_back(digit);
    }
    while (carry > 0) {
        out.push_back((uint32_t)(carry % 10));
        carry /= 10;
    }
    while (out.size() > 1 && out.back() == 0) out.pop_back();
    return out;
}

// ============================
// 3) CUDA FFT BigInt multiply context
// ============================

struct CudaFFTContext {
    cufftHandle plan_fwd = 0;
    cufftHandle plan_inv = 0;
    uint32_t n = 0;

    cufftDoubleComplex* d_A = nullptr;
    cufftDoubleComplex* d_B = nullptr;
    cufftDoubleComplex* d_C = nullptr;
    int64_t* d_raw = nullptr;

    ~CudaFFTContext() {
        if (plan_fwd) cufftDestroy(plan_fwd);
        if (plan_inv) cufftDestroy(plan_inv);
        if (d_A) cudaFree(d_A);
        if (d_B) cudaFree(d_B);
        if (d_C) cudaFree(d_C);
        if (d_raw) cudaFree(d_raw);
    }

    void ensure(uint32_t new_n) {
        if (new_n == n) return;

        // cleanup old
        if (plan_fwd) { cufftDestroy(plan_fwd); plan_fwd = 0; }
        if (plan_inv) { cufftDestroy(plan_inv); plan_inv = 0; }
        if (d_A) { cudaFree(d_A); d_A = nullptr; }
        if (d_B) { cudaFree(d_B); d_B = nullptr; }
        if (d_C) { cudaFree(d_C); d_C = nullptr; }
        if (d_raw) { cudaFree(d_raw); d_raw = nullptr; }

        n = new_n;

        CUFFT_CHECK(cufftPlan1d(&plan_fwd, (int)n, CUFFT_Z2Z, 1));
        CUFFT_CHECK(cufftPlan1d(&plan_inv, (int)n, CUFFT_Z2Z, 1));

        CUDA_CHECK(cudaMalloc((void**)&d_A, sizeof(cufftDoubleComplex) * n));
        CUDA_CHECK(cudaMalloc((void**)&d_B, sizeof(cufftDoubleComplex) * n));
        CUDA_CHECK(cudaMalloc((void**)&d_C, sizeof(cufftDoubleComplex) * n));
        CUDA_CHECK(cudaMalloc((void**)&d_raw, sizeof(int64_t) * n));
    }
};

static uint32_t next_pow2(uint32_t x) {
    uint32_t p = 1;
    while (p < x) p <<= 1;
    return p;
}

// ============================
// 4) BigInt class
// ============================

class BigIntCUDA {
public:
    // base10 digits reversed
    std::vector<uint32_t> d;

    BigIntCUDA() : d{0} {}
    explicit BigIntCUDA(const std::string& s) : d(parse_decimal_to_digits_rev(s)) {}
    explicit BigIntCUDA(std::vector<uint32_t> digits_rev) : d(std::move(digits_rev)) {
        if (d.empty()) d.push_back(0);
        while (d.size() > 1 && d.back() == 0) d.pop_back();
    }

    std::string str() const { return digits_rev_to_string(d); }

    static BigIntCUDA multiply(const BigIntCUDA& a, const BigIntCUDA& b, CudaFFTContext& ctx, bool gpu_carry = false) {
        if ((a.d.size() == 1 && a.d[0] == 0) || (b.d.size() == 1 && b.d[0] == 0)) {
            return BigIntCUDA("0");
        }

        uint32_t need = (uint32_t)(a.d.size() + b.d.size());
        uint32_t n = next_pow2(need);

        ctx.ensure(n);

        // Host -> device (complex, imag=0)
        std::vector<cufftDoubleComplex> hA(n), hB(n);
        for (uint32_t i = 0; i < n; i++) {
            hA[i].x = (i < a.d.size()) ? (double)a.d[i] : 0.0;
            hA[i].y = 0.0;
            hB[i].x = (i < b.d.size()) ? (double)b.d[i] : 0.0;
            hB[i].y = 0.0;
        }

        CUDA_CHECK(cudaMemcpy(ctx.d_A, hA.data(), sizeof(cufftDoubleComplex) * n, cudaMemcpyHostToDevice));
        CUDA_CHECK(cudaMemcpy(ctx.d_B, hB.data(), sizeof(cufftDoubleComplex) * n, cudaMemcpyHostToDevice));

        // FFT on GPU
        CUFFT_CHECK(cufftExecZ2Z(ctx.plan_fwd, ctx.d_A, ctx.d_A, CUFFT_FORWARD));
        CUFFT_CHECK(cufftExecZ2Z(ctx.plan_fwd, ctx.d_B, ctx.d_B, CUFFT_FORWARD));

        // pointwise multiply on GPU
        const int TPB = 256;
        int blocks = (int)((n + TPB - 1) / TPB);
        pointwise_mul<<<blocks, TPB>>>(ctx.d_A, ctx.d_B, ctx.d_C, n);
        CUDA_CHECK(cudaGetLastError());

        // iFFT on GPU
        CUFFT_CHECK(cufftExecZ2Z(ctx.plan_inv, ctx.d_C, ctx.d_C, CUFFT_INVERSE));

        // normalize + round -> int64 on GPU
        normalize_round_to_i64<<<blocks, TPB>>>(ctx.d_C, ctx.d_raw, n, 1.0 / (double)n);
        CUDA_CHECK(cudaGetLastError());

        if (gpu_carry) {
            // 可選：GPU carry（單執行緒序列）
            carry_base10_inplace<<<1, 1>>>(ctx.d_raw, n);
            CUDA_CHECK(cudaGetLastError());
            CUDA_CHECK(cudaDeviceSynchronize());

            // 仍要回 CPU 來「截斷長度 + 補最後 carry」（因為輸出長度可變）
            std::vector<int64_t> hraw(n);
            CUDA_CHECK(cudaMemcpy(hraw.data(), ctx.d_raw, sizeof(int64_t) * n, cudaMemcpyDeviceToHost));

            // 這時候 hraw 已經是 base10 digits（多數情況）
            std::vector<uint32_t> out;
            out.reserve(n);
            for (uint32_t i = 0; i < n; i++) {
                int64_t v = hraw[i];
                if (v < 0) v = 0;
                if (v > 9) v %= 10; // 保險
                out.push_back((uint32_t)v);
            }
            while (out.size() > 1 && out.back() == 0) out.pop_back();
            return BigIntCUDA(std::move(out));
        } else {
            // 建議：回 CPU 做 carry（最穩最實用）
            std::vector<int64_t> hraw(n);
            CUDA_CHECK(cudaMemcpy(hraw.data(), ctx.d_raw, sizeof(int64_t) * n, cudaMemcpyDeviceToHost));
            auto out_digits = carry_base10_cpu_from_i64(hraw);
            return BigIntCUDA(std::move(out_digits));
        }
    }

    BigIntCUDA pow_u64(uint64_t e, CudaFFTContext& ctx, bool gpu_carry = false) const {
        BigIntCUDA result("1");
        BigIntCUDA base = *this;
        while (e > 0) {
            if (e & 1ULL) result = multiply(result, base, ctx, gpu_carry);
            e >>= 1ULL;
            if (e) base = multiply(base, base, ctx, gpu_carry);
        }
        return result;
    }
};

// ============================
// 5) main demo (你可以照你原本 freopen 改)
// ============================
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 你原本的 freopen
    freopen("bumA.txt", "r", stdin);
    freopen("cudaFFToutput.txt", "w", stdout);

    std::string s;
    std::cin >> s;

    CudaFFTContext ctx;

    BigIntCUDA a(s);

    // 這裡你原本是 pow(256<<1) = 512
    uint64_t exp = (63ULL << 1ULL);

    // gpu_carry 建議先 false（穩且快），你要硬全GPU再改 true
    bool gpu_carry = false;
    #ifdef ENABLE_TIMING
        auto start = chrono::high_resolution_clock::now();
    #endif
    BigIntCUDA ans = a.pow_u64(exp, ctx, gpu_carry);

    #ifdef ENABLE_TIMING
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
        std::cerr << "Time taken: " << duration.count() << " ms\n";
    #endif
    std::cout << ans.str() << "\n";

    return 0;
}
