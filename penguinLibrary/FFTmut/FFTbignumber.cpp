#include <bits/stdc++.h>
using namespace std;
typedef complex<long double> cd;
#define endl "\n" 

#ifdef ENABLE_TIMING
    #include <chrono>
    using namespace std::chrono;
    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now();
    auto durat = duration_cast<nanoseconds>(stop - start);
#endif

long double PI = acosl(-1.0L);  // 使用更精確的方式取得 PI

// FFT function
void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    if (n == 1) return;
    int half = n >> 1;

    vector<cd> a0(half), a1(half);
    for (int i = 0; i < half; i++) {
        a0[i] = a[i << 1];
        a1[i] = a[(i << 1) + 1];
    }

    fft(a0, invert);
    fft(a1, invert);

    long double ang = PI* 2 / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (int i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + half] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + half] /= 2;
        }
        w *= wn;
    }
}

// Multiplication using FFT
vector<unsigned long long> multiply(const vector<unsigned long long>& a, const vector<unsigned long long>& b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<unsigned long long> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());

    // Handle carry
    unsigned long long carry = 0;
    for(auto& x : result) {
        x += carry;
        carry = x / 10;
        x %= 10;
    }

    // Remove trailing zeros
    while (result.size() > 1 && result.back() == 0)
        result.pop_back();

    return result;
}

// Operator overload for ostream output
ostream& operator<<(ostream& os, const vector<unsigned long long>& v) {
    for (auto it = v.rbegin(); it != v.rend(); ++it) {
        os << *it;
    }
    return os;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    // Open input and output files
    freopen("bumA.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<unsigned long long> a, b;
    for (int i = s.size() - 1; i >= 0; i--) {
        a.push_back(s[i] - '0');
    }

    // cout << a << endl;
    
    b = a;  // Squaring the number
    #ifdef ENABLE_TIMING
        start = high_resolution_clock::now();
    #endif
    vector<unsigned long long> result = multiply(a, b);
    #ifdef ENABLE_TIMING
        stop = high_resolution_clock::now();
        durat = duration_cast<nanoseconds>(stop - start);
        // cout << "\nTotal time taken: " << double (durat.count())/1000000.0 << " ms.\n";
    #endif

    cout << result << endl;
    #ifdef ENABLE_TIMING
        cout << "\nTotal time taken: " << double (durat.count())/1000000.0 << " ms.\n";
    #endif

    return 0;
}
