#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif
    
    start:
    cout<<0;
    goto start;


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<nanoseconds>(stop - start);
        cout << "\nTotal time taken: " << double (duration.count())/1000.0 << " ms.\n";
    #endif

    return 0;
}
