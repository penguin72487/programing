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

#ifndef CUDAFFT_HPP
#define CUDAFFT_HPP

int digit=8;

typedef complex<double> cd;
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
vector<unsigned long long> operator+(const vector<unsigned long long>& a, const vector<unsigned long long>& b) {
    unsigned long long n = max(a.size(), b.size()) + 1;
    vector<unsigned long long> result(n, 0);
    unsigned long long carry = 0;
    for (unsigned long long i = 0; i < n; i++) {
        unsigned long long sum = carry;
        if (i < a.size()) sum += a[i];
        if (i < b.size()) sum += b[i];
        unsigned long long pow10 = pow(10, digit);
        result[i] = sum % pow10;
        carry = sum / pow10;
    }

    // Remove leading zeros
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    return result;
}

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
    unsigned long long pow10 = round(pow(10, digit));
    for (unsigned long long i = 0; i < n; i++) {
        unsigned long long value = round(real_result[i]) + carry;
        carry = value / pow10;
        result.push_back(value % pow10);
    }

    // Remove trailing zeros
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    return result;
}

  
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

class cudaFFT {
    public:
        cudaFFT();
        cudaFFT(vector<unsigned long long> val) {
            this->val = val;
        }
        cudaFFT(string s) {
            reverse(s.begin(), s.end());
            while(s.size() % digit != 0) {
                s.push_back('0');
            }
            val.reserve(s.size());  // 提前分配空間以提高性能

            for (unsigned long long i = 0; i < s.size(); i += digit) {
                unsigned long long value = 0;
                unsigned long long pow10 = 1;
                for (int j = 0; j < digit; j++) {
                    value += (s[i + j] ^ 48) * pow10;
                    pow10 *= 10;
                }
                val.push_back(value);
            }
        }

        ~cudaFFT() {
            val.clear();
        }

        cudaFFT operator+(const cudaFFT& b) {
            vector<unsigned long long> a = this->val;
            vector<unsigned long long> b_val = b.val;
            return cudaFFT(a + b_val);
        }

        cudaFFT operator*(const cudaFFT& b) {
            vector<unsigned long long> a = this->val;
            vector<unsigned long long> b_val = b.val;
            return cudaFFT(a * b_val);
        }

        cudaFFT& operator=(const cudaFFT& b) {
            this->val = b.val;
            return *this;
        }
        cudaFFT& operator=(const vector<unsigned long long>& b) {
            this->val = b;
            return *this;
        }

        friend ostream& operator<<(ostream& os, const cudaFFT& a) {
            return os << a.val;
        }

        cudaFFT pow(unsigned long long n) {
            cudaFFT result = cudaFFT("1");
            cudaFFT base = this->val;
            while (n > 0) {
                if (n & 1) {
                    result = result * base;
                }
                base = base * base;
                n >>= 1;
            }
            return result;
        }


        
        
    private:
        double PI = acos(-1.0);  // 使用更精確的方式取得 PI
        vector<unsigned long long> val;
};





#endif