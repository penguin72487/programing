#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    string s_1, s_2;
    while(cin>>s_1>>s_2)
    {
        int n=s_1.length();
        int m=s_2.length();
        int dp[n + 1][m + 1];
        fill(*dp, *dp + (n + 1) * (m + 1), 0);
        for (int i = 1; i <=n;++i)
        {
            for (int j = 1; j <=m;++j)
            {
                if(s_1[i-1]==s_2[j-1])
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
        cout << dp[n][m] << "\n";
    }
}