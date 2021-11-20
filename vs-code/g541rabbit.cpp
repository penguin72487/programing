#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
unsigned two=2;
unsigned * dp=new unsigned[two<<31];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    unsigned a[2], q;
    cin >> a[0] >> a[1] >> q;
    
    unsigned k_Max = 0;
    unsigned k_Min =2147483647;
    for (unsigned i_count = 0; i_count < q;++i_count)
    {
        unsigned k;
        cin >> k;
        if(k<k_Max&&k>k_Min)
        {
            if(dp[k]==k)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
            k_Max = max(k,k_Max);
            k_Min = min(k,k_Min);
            continue;
        }
        else if(k<=k_Min)
        {
            for (int i = 0; i < 2;++i)
            {
                for (unsigned j = max(a[i],k); j <= k; ++j)
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
            k_Max = max(k,k_Max);
            k_Min = min(k,k_Min);
            continue;
        }
        
        for (int i = 0; i < 2;++i)
        {
            for (unsigned j = max(k, a[i]); j <= k; ++j)
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
        k_Max = max(k,k_Max);
        k_Min = min(k,k_Min);
    }
    
}