#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n,w;
    cin >> n>>w;
    int A[n];//Åé¿n
    int B[n];//¹¡¨¬·P
    for (int i = 0; i < n; ++i)
    {
        cin >> B[i] >> A[i];
    }
    int* dp=new int[w + 1];
    fill(dp, dp+w+1, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = w; j >= A[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - A[i]] + B[i]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = w; j >= A[i]; --j)
        {
            dp[j] = min(dp[j], dp[j - A[i]] + B[i]);
        }
    }
    cout << dp[w] << "\n";
    delete []dp;
}