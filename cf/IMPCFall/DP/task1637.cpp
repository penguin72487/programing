#include<iostream>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> dp(n+1,2147483647);
    
    for (int i = 1; i < 10;++i){
        dp[i] = 1;
    }
    for (int i = 1;i<=n;++i)
    {
        int tmp = i;
        while(i)
        {
            dp[i] = min(dp[i], dp[i - tmp % 10]+1);
        }
    }

        cout << dp[n] << "\n";
    return 0;
}