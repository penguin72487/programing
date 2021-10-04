#include<iostream>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n;++i)
    {
        int m;
        cin >> m;
        int coin[m];
        int totle=0;
        int sum;
        /*
        for (int j = 0; j < m;++j)
        {
            cin >> coin[j];
            totle += coin[j];
        }
        */
        for (int *it = coin; it != coin + m;++it)
        {
            cin >> *it;
            totle += *it;
        }
            sum = totle;
        totle/=2;
        totle+=2;
        int dp[totle + 1];
        fill(dp, dp + totle + 1, 0);
        for (int j = 0; j < m; ++j)
        {
            for (int k = totle; k >=coin[j];--k)
            {        
                dp[k]=max(dp[k],dp[k-coin[j]]+coin[j]);
            }
        }
        int ans = 2147483647;
        --totle;
        //totle *= 2;
        //cout << "tttt" << sum << " ";
        for (int j = 0; j < totle;++j)
        {
            ans=min(ans,abs(sum-2*dp[j]));
            //cout << dp[j] << " ";
        }
        //cout << "\n";
        cout << ans << "\n";
        //cout << dp[totle/2+1]-dp[totle/2] << "\n";
    }
    return 0;
}