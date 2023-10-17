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
        vector<int> dp(n + 1);
        for (int i = 0; i <=n;++i)
        {
            dp[i] = i;
        }
        for (int i = 0; i < n;++i)
        {
            if(i + v[i]+1<=n)
            {
                dp[i + v[i]+1] = min({dp[i],dp[i + v[i]+1]});
                dp[n] = min(dp[n], dp[i] + n-i-v[i]-1);
            }
            dp[i+1]=min(dp[i+1],dp[i]+1);
            
        }
        cout << dp[n] << "\n";
    }
    return 0;
}