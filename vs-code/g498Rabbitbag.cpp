#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int a[2], k;
    cin >> a[0] >> a[1] >> k;
    int dp[k+1];
    fill(dp, dp + k+1, 0);
    for (int i = 0; i < 2;++i)
    {
        for (int j = a[i]; j <=k;++j)
        {
            dp[j] = max(dp[j], dp[j - a[i]]+a[i]);
        }
    }
    if(dp[k]==k)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}