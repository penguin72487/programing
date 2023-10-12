#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v(n);
        for(auto& it : v)
        {
            cin>>it;
        }
        vector<int> dp(n+1,1<<30);
        for (int i = 0; i < n;++i)
        {
            dp[i+v[i]] = min(dp[i+v[i]], dp[i] + 1);
        }
    }
    return 0;
}