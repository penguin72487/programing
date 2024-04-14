#include<bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;

#ifdef ENABLE_TIMING
        using namespace std::chrono;
        auto start = high_resolution_clock::now();
    #endif

    while (t--)
    {
        int n, m, k;
        cin>>n>>m>>k;
        vector<int> l(n);
        vector<int> r(m);
        for(auto &i:l)
        {
            cin>>i;
        }
        for(auto &i:r)
        {
            cin>>i;
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        int ans = 0;
        for(auto it = l.begin(); it!=l.end(); it++)
        {
            if(*it>k) break;
            auto it2 = upper_bound(r.begin(), r.end(), k-*it);
            ans+=it2-r.begin();
        }
        cout<<ans<<endl;
    }
    
    


    #ifdef ENABLE_TIMING
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        cout << "\nTotal time taken: " << duration.count() << " ms.\n";
    #endif

    return 0;
}