#include <iostream>         // 替換為需要的標頭文件
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>
#include <chrono>
#include <string>
#include <fstream>
#include <cstdio>  // for freopen and FILE*
#include <cufft.h>
#include <cuda_runtime.h>
using namespace std;
typedef complex<double> cd;
#define endl "\n"
#ifdef ENABLE_TIMING
    #include <chrono>
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto durat = duration_cast<nanoseconds>(stop - start);
#endif

double PI = acos(-1.0);  // 使用更精確的方式取得 PI

// GPU FFT function using cuFFT
void cuda_fft(vector<double>& real, vector<double>& imag, unsigned long long n, bool inverse) {
    unsigned long long size = n * sizeof(cufftDoubleComplex);
    cufftDoubleComplex* h_data = (cufftDoubleComplex*)malloc(size);

    // Initialize data
    for (unsigned long long i = 0; i < n; i++) {
        h_data[i].x = real[i];
        h_data[i].y = imag[i];
    }

    // Allocate GPU memory
    cufftDoubleComplex* d_data;
    cudaMalloc((void**)&d_data, size);
    cudaMemcpy(d_data, h_data, size, cudaMemcpyHostToDevice);

    // cuFFT plan
    cufftHandle plan;
    cufftPlan1d(&plan, n, CUFFT_Z2Z, 1);
    if (inverse)
        cufftExecZ2Z(plan, d_data, d_data, CUFFT_INVERSE);
    else
        cufftExecZ2Z(plan, d_data, d_data, CUFFT_FORWARD);

    // Copy result back to CPU
    cudaMemcpy(h_data, d_data, size, cudaMemcpyDeviceToHost);

    // Update output
    for (unsigned long long i = 0; i < n; i++) {
        real[i] = h_data[i].x;
        imag[i] = h_data[i].y;
    }

    // Cleanup
    cufftDestroy(plan);
    cudaFree(d_data);
    free(h_data);
}

// Multiplication using GPU FFT
vector<unsigned long long> operator*(const vector<unsigned long long>& a, const vector<unsigned long long>& b) {
    unsigned long long n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;

    vector<double> real_a(n, 0.0), imag_a(n, 0.0);
    vector<double> real_b(n, 0.0), imag_b(n, 0.0);

    for (unsigned long long i = 0; i < a.size(); i++) {
        real_a[i] = a[i];
    }
    for (unsigned long long i = 0; i < b.size(); i++) {
        real_b[i] = b[i];
    }

    // Forward FFT
    cuda_fft(real_a, imag_a, n, false);
    cuda_fft(real_b, imag_b, n, false);

    // Point-wise multiplication
    vector<double> real_result(n), imag_result(n);
    for (unsigned long long i = 0; i < n; i++) {
        real_result[i] = real_a[i] * real_b[i] - imag_a[i] * imag_b[i];
        imag_result[i] = real_a[i] * imag_b[i] + imag_a[i] * real_b[i];
    }

    // Inverse FFT
    cuda_fft(real_result, imag_result, n, true);

    // Normalize the result after inverse FFT
    for (unsigned long long i = 0; i < n; i++) {
        real_result[i] /= n;
    }

    // Extract results and handle carry
    vector<unsigned long long> result;
    unsigned long long carry = 0;
    result.reserve(n);  // 提前分配空間以加速輸出
    for (unsigned long long i = 0; i < n; i++) {
        unsigned long long value = round(real_result[i]) + carry;
        carry = value / 10;
        result.push_back(value % 10);
    }

    // Remove trailing zeros
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    return result;
}

vector<unsigned long long> operator^(const vector<unsigned long long>& a,unsigned long long exp) {
    // Fast power function using repeated squaring
    vector<unsigned long long> result = {1};  // Start with 1
    vector<unsigned long long> base = a;  // Copy the base
    while (exp > 0) {
        if (exp & 1 == 1) {
            result = result * base;  // Multiply result by base
        }
        base = base * base;  // Square the base
        exp >>= 1;  // Divide exponent by 2
    }
    return result;  // Return the final result
}


// Operator overload for ostream output
// ostream& operator<<(ostream& os, const vector<unsigned long long>& v) {
//     // 使用字符串流構建輸出，減少多次字符串拼接的開銷
//     ostringstream result;
//     result.precision(0);  // 禁止小數點輸出
//     for (auto it = v.rbegin(); it != v.rend(); ++it) {
//         result << *it;
//     }
//     os << result.str();
//     return os;
// }

ostream& operator<<(ostream& os, const vector<unsigned long long>& v) {
    // 直接將輸出改為二進制寫入方式以減少 I/O 開銷
    constexpr size_t buffer_size = 1 << 30;  // 2^30 bytes
    char* buffer = new char[buffer_size];
    size_t buffer_pos = 0;

    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        string number = to_string(*it);
        for (char c : number) {
            buffer[buffer_pos++] = c;
            if (buffer_pos == buffer_size) {
                os.write(buffer, buffer_pos);
                buffer_pos = 0;
            }
        }
    }

    // Write any remaining data in buffer
    if (buffer_pos > 0) {
        os.write(buffer, buffer_pos);
    }

    delete[] buffer;
    return os;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    vector<unsigned long long> a = {2};
    unsigned long long exp = 512;
    #ifdef ENABLE_TIMING
        start = high_resolution_clock::now();
    #endif
    vector<unsigned long long> result = a ^ exp;
    result[0] -= 1;
    #ifdef ENABLE_TIMING
        stop = high_resolution_clock::now();
        durat = duration_cast<nanoseconds>(stop - start);
        // cout << "\nTotal time taken: " << double(durat.count()) / 1000000.0 << " ms.\n";
    #endif

    cout << result << endl;
    #ifdef ENABLE_TIMING
        cout << "\nTotal time taken: " << double(durat.count()) / 1000000.0 << " ms.\n";
    #endif
    cout << result.size()<< " digits in the result." << endl;
    return 0;
}

/*
cd "c:\gitproject\programing\penguinLibrary\FFTmut\" ; if ($?) { nvcc pow2.cpp -o cudaFFT -I"C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.6/include" -L"C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.6/lib/x64" -lcufft -lcudart -DENABLE_TIMING } ; if ($?) { .\cudaFFT }

.\cudaFFT.exe
*/