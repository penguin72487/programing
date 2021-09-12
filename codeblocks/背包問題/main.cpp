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
    int* dp=new int[n + 1];
    fill(dp, dp+n+1, 0);
    cout <<"n="<< &n << "\n";
    for (int i = 1; i < n; ++i)
    {
        for (int j = w; j >= A[i]; --j)
        {
            cout<<dp[j] <<" "<< dp[j - A[i]]<<" "<<B[i]<<"\n";
            dp[j] = max(dp[j], dp[j - A[i]] + B[i]);
        }
    }
    for (int i = 0; i < n + 1;++i)
    {
        cout << dp[i] << " ";
    }
        cout << dp[n] << "\n";
    delete []dp;
}
