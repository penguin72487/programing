#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    int w = 100;
    int A[n];//Åé¿n
    int B[n];//¹¡¨¬·P
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i] >> B[i];
    }
    int dp[n + 1];
    fill(dp, dp+n+1, 0);
    cout <<"n="<< n << " ";
    for (int i = 0; i < n; ++i)
    {
        cout << n << " ";
        cout << i << "\n";
        for (int j = w; j >= A[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - A[i]] + B[i]);
        }
    }
    
    cout << dp[n]<<"\n";
}