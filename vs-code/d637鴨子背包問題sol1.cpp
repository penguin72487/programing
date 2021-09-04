#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n=0;
    cin >> n;
    int w = 100;
    int A[n];//Åé¿n
    int B[n];//¹¡¨¬·P
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i] >> B[i];
    }
    int dp[n + 1][w + 1];
    fill(*dp, &dp[n][w+1], 0);
    
        for (int i = 0; i <n; ++i)
        {
            for (int j = 0; j <= w; ++j)
            {
                if (j < A[i])
                {
                    dp[i + 1][j] = dp[i][j];
                }
                else
                {
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - A[i]] + B[i]);
                }
            }
        }
    
    for (int i = 0; i < n+1;++i)
    {
        for (int j = 0; j < w + 1;++j)
        {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << dp[n][w]<<"\n";
}