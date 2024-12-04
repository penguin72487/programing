#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
#ifdef ENABLE_TIMING
    #include <chrono>
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto durat = duration_cast<nanoseconds>(stop - start);
#endif

long double Kelly_With_Fee(long double a, long double b, long double p, long double c) {
    long double discriminant = pow((b * a + c * (p - 1)), 2) - 4 * c * b * (p * (a + b) - a);
    if (discriminant < 0) {
        std::cerr << "判别式小于零，没有实数解。" << endl;
        return NAN; // 返回非数字，表示无解
    } else {
        return (b * a + c * (p - 1) + sqrt(discriminant)) / (2 * c * b);
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    #ifdef ENABLE_TIMING
        start = high_resolution_clock::now();
    #endif
    
    long double a=15, b=10, p=0.5, c=0.0001;
    cout << Kelly_With_Fee(a, b, p, c) <<"%"<< endl;

    #ifdef ENABLE_TIMING
        stop = high_resolution_clock::now();
        durat = duration_cast<nanoseconds>(stop - start);
        cout << "\nTotal time taken: " << double (durat.count())/1000000.0 << " ms.\n";
    #endif

    return 0;
}