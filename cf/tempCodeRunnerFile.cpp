#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int coin[] = {1, 5, 10, 20, 100};
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n;++i)
    {
        dp[i] = 1 << 30;
        for (int j = 0; j < 5;++j)
        {
            if(i>=coin[j])
            {
                dp[i] = min(dp[i], dp[i - coin[j]] + 1);
            }
        }
    }
    cout << dp[n] << "\n";
    return 0;
}