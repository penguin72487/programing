#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    cin >> n;
    
    
    int w = 100;
    int A[n];//Åé¿n
    int B[n];//¹¡¨¬·P
    for (int i = 0; i < n; ++i)
    {
        cin >> A[i] >> B[i];
    }
    int* dp=new int[w + 1];
    fill(dp, dp+w+1, 0);

    for (int i = 0; i < n; ++i)
    {
        for (int j = w; j >= A[i]; --j)
        {
            dp[j] = max(dp[j], dp[j - A[i]] + B[i]);
        }
        // for (int j = 0; j < w+1;++j)
        // {
        //     cout << dp[j] <<" ";
        // }
        // cout << "end\n";
    }
    cout << dp[w] << "\n";
    delete []dp;
}