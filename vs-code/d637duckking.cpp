#include<iostream>
using namespace std;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >>n;
    int food[n];
    int vol[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> vol[i] >> food[i];
    }
    int dp[101]={0};

    for (int i = 0; i < n;++i)
    {
        for (int j = 100; j >=vol[i];--j)
        {
            dp[j] = max(dp[j], dp[j - vol[i]] + food[i]);
        }
    }
    /*
    for (int i = 0; i < 101;++i)
    {
        cout << dp[i] << " ";
    }
    */
    cout << "\n";
    cout << dp[100] << "\n";

    return 0;
}