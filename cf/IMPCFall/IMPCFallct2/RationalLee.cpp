#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> w(k);
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        for(int i = 0; i < k; ++i)
        {
            cin >> w[i];
        }
        sort(a.rbegin(), a.rend());
        sort(w.begin(), w.end());
        long long ans = 0;
        for(auto it=a.begin(),jt=w.begin(),ed = upper_bound(w.begin(), w.end(),1); jt !=ed; ++it,++jt)
        {
            ans += *it;
        }
        auto it = a.begin();
        for(auto jt=w.begin(); jt !=w.end(); ++it,++jt)
        {
            ans += *it;
        }
        
        //auto jt = upper_bound(w.begin(), w.end(),1);
        for (auto jt=upper_bound(w.begin(), w.end(),1); jt!=w.end(); ++jt,++it)
        {
            it += *jt - 2;
            ans += *it;
        }


            cout << ans << "\n";
    }
    return 0;
}