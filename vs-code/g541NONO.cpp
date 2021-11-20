#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long two=2;
long long * dp=new long long[two<<32];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    long long a[2], q;
    cin >> a[0] >> a[1] >> q;
    
    
    for (long long i_count = 0; i_count < q;++i_count)
    {
        long long k;
        cin >> k;
        for (int i = 0; i < 2;++i)
        {
            for (long long j = a[i]; j <= k; ++j)
            {
                 if(dp[j]!=NULL)
                {
                    dp[j] = max(dp[j], dp[j - a[i]]+a[i]);
                }
                else
                {
                    dp[j] = dp[j - a[i]] + a[i];
                }
                
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
    
}