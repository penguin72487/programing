#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
unsigned * dp=new unsigned[2147483648];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    unsigned a[2], q;
    cin >> a[0] >> a[1] >> q;
    
    unsigned k_Max = 0;
    for (unsigned i_count = 0; i_count < q;++i_count)
    {
        unsigned k;
        cin >> k;
        if(k<k_Max)
        {
            if(dp[k]==k)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            continue;
        }
        
        for (int i = 0; i < 2;++i)
        {
            for (unsigned j = max(k_Max, a[i]); j <= k; ++j)
            {
                if(dp[j])
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
        k_Max = k;
    }
    
}