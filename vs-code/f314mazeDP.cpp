#include <iostream>
#include<algorithm>
using namespace std;
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int m, n;
    cin >> n >> m;
    ++m;
    ++n;
    int a[n][m], l[m], r[m],dp[n][m];
    fill(l, l + m + 1, 0);
    fill(r, r + m + 1, 0);

    for (int i = 0; i < n+1;++i)
    {
        fill(dp[i],dp[i]+m+1,0);
    }
    for (int i = 1; i <n;++i)
    {
        for (int j = 1; j <m;++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i < n;++i)
    {
        for (int j = 1; j < m;++j)
        {
            if(j==1)
            {
                l[j] = dp[i - 1][j] + a[i][j];
            }
            else
            {
                l[j] = max(dp[i-1][j],l[j-1])+a[i][j];
            }
        }
        for (int j = m-1; j > 0;--j)
        {
            if (j == m-1)
            {
                r[j] = dp[i - 1][j] + a[i][j];
            }
            else
            {
                r[j] = max(dp[i - 1][j], r[j+1])+a[i][j];
            }
            dp[i][j] = max(l[j], r[j]);
        }
    }
    int ans = -2147483647;
    for (int i = 1; i <=m;++i)
    {
        ans = max(ans, dp[n - 1][i]);
    }
    cout << ans << "\n";
}