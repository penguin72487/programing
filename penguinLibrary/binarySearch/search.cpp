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

auto binary_search(vector<long long>::iterator start, vector<long long>::iterator end, long long target) -> auto {
    auto notFound = end;
    while (start <= end) {
        auto mid = start + (end - start) / 2;
        if (*mid == target) {
            return mid;
        } else if (*mid < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return notFound;
}


int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);

    vector<long long> testCases(100000000);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(INT_MIN, INT_MAX);
    for(auto &i: testCases) {
        i = dis(gen);
    }
    sort(testCases.begin(), testCases.end());

    #ifdef ENABLE_TIMING
        start = high_resolution_clock::now();
    #endif
    
    cout<<*binary_search(testCases.begin(), testCases.end(), testCases[1000])<<endl;


    #ifdef ENABLE_TIMING
        stop = high_resolution_clock::now();
        durat = duration_cast<nanoseconds>(stop - start);
        cout << "\nTotal time taken: " << double (durat.count())/1000000.0 << " ms.\n";
    #endif

    return 0;
}