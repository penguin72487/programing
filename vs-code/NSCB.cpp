#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int s[n];
    int r[n];
    for (int i = 0; i < n;++i)
    {
        cin >> s[i];
    }
    for (int i = 0; i < n;++i)
    {
        cin >> r[i];
    }
    int dp[n + 1];
    fill(dp,dp+1+n,0);
    for (int k = 0; k <=n;++k)
    {
        for (int i = 1; i < n;++i)
        {
            
        }
    }
}