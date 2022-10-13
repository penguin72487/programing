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
        auto it = a.begin();
        auto ed = it + k;
        for(; it!=ed; it++)
        {
            ans += *it;
        }
        auto jt = upper_bound(w.begin(), w.end(),1);
        for (; jt != w.end();++jt)
        {
            it += *jt - 1;
            ans += *it;
        }


            cout << ans << "\n";
    }
    return 0;
}