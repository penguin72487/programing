#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n,target;
    cin >> n>>target;
    int time[n];//time
    int credit[n];//credit
    for (int i = 0; i < n; ++i)
    {
        cin >> time[i]>> credit[i];
        //cin >> credit[i]>>time[i];
    }
    vector<int> dp(target+1,0);
    for (int i = 0; i < n; ++i)
    {
        for (int j = target; j >= credit[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - credit[i]] + time[i]);
        }
    }
    //vector<int> dp(target+1,2147483647);
        for (int i = 0; i <n; ++i)
        {
            for (int j = target; j >= 0; --j)
            {
                if (j <= credit[i])
                {
                    dp[j] = min(dp[j], time[i]);
                }
                else
                {
                    dp[j] = min(dp[j], dp[j - credit[i]] - time[i]);
                }
            }
        }
    cout << dp[target] << "\n";
}