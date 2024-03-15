#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    #ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x: a){
            cin >> x;
            x=abs(x);
        }
        cout<<accumulate(a.begin(), a.end(), 0)<<endl;
        
    }
    
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}