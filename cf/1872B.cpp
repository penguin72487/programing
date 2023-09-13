#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<tuple<int,int>> v(n);
        for(auto &[a,b]:v) cin >> a >> b;
        sort(v.begin(), v.end());
        int ans = 100000000;
        for(auto&[a,b]:v){
            if(a>ans) break;
            ans = min(ans, a + (b - 1) / 2);
        }
        cout << ans << "\n";
    }
    return 0;
}