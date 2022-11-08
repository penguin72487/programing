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
    }
    dp[0] = 1;
    for (int i = 0; i <n;++i)
    {
        for (int j = c[i]; j <= t;++j)
        {
            dp[j] = (dp[j] + dp[j - c[i]]) % 1000000007;
        }
    }
    

    cout << dp[t] << "\n";
    return 0;
}