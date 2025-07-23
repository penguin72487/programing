#include <iostream>         // 替換為需要的標頭文件
#include "cudaFFT8.hpp"
#define endl "\n"
using namespace std;
#ifdef ENABLE_TIMING
    #include <chrono>
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto durat = duration_cast<nanoseconds>(stop - start);
#endif
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    #ifdef ENABLE_TIMING
        start = high_resolution_clock::now();
    #endif
    
    freopen("bumA.txt", "r", stdin);
    freopen("cudaFFToutput.txt", "w", stdout);


    string s;
    cin >> s;

    cudaFFT a(s);
    #ifdef ENABLE_TIMING
        start = high_resolution_clock::now();
    #endif
    cout << a.pow(1ull<<1) << endl;
    #ifdef ENABLE_TIMING
        stop = high_resolution_clock::now();
        durat = duration_cast<nanoseconds>(stop - start);
        cout << "\nTotal time taken: " << double (durat.count())/1000000.0 << " ms.\n";
    #endif

    return 0;
}

/*

cd "c:\gitproject\programing\penguinLibrary\FFTmut\cudaFFT" ; if ($?) { nvcc cudaFFT.cpp -o cudaFFT -I"C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.6/include" -L"C:/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.6/lib/x64" -lcufft -lcudart -DENABLE_TIMING } ; if ($?) { .\cudaFFT }


*/

