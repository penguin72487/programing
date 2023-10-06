#include<iostream>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,t;
    cin >> n >> t;
    vector<long long> c(n);
    vector<long long> dp(t+1,0);
    for(int i = 0; i < n;++i)
    {
        cin>>c[i];
        if(c[i]<=t)
        {
            ++dp[c[i]];
        }
    }
    for (int i = 1; i <= t;++i)
    {
        for(int j = 0; j < n;++j)
        {
            if(i-c[j]>=0)
            {
                dp[i] =(dp[i] + dp[i-c[j]])%(1000000007);
            }
        }
    }
    

    cout << dp[t] << "\n";
    return 0;
}