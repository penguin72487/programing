#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n=6;
    cin >> n;
    
    int w = 100;
    int A[n];//體積
    int B[n];//飽足感
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