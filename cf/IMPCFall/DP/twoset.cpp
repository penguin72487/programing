#include<iostream>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int n2 = (n << 1);
    vector<vector<int>> dp(n+1, vector<int>(n2+2,0));
    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 1;
    }
    for(int i = 0; i <=n;++i)
    {
        for (int j = 0; j < n2+2;++j)
        {
            dp[i][j] =dp[i-1][j]+dp[i-1][j-i];
        }
    }
    cout << dp[n - 1][n];
    return 0;
}