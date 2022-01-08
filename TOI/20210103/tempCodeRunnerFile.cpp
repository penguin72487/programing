#include<iostream>
#include<cmath>
#include<algorithm>
#include<numeric>
using namespace std;
int qury(int * prior_Sum,int ed,int v);//ed會後一個 回傳前v個的和
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n, k, t;
    cin >> n >> k >> t;
    int m[n];
    for (int i = 0; i < n;++i)
    {
        cin >> m[i];
    }
    int prior_Sum[n];
    partial_sum (m, m+n, prior_Sum);
    int fakeDP[n+k+t+1];
    fill(fakeDP,fakeDP+n+k+t+1,0);
    int *dp = &fakeDP[k+t+1];
    for (int i = 0; i < n;++i)
    {
        dp[i] = max(dp[i-1],max(m[i],dp[i-k-t]+qury(prior_Sum,i,t-1)));
    }
    /*
    for (int i = 0; i < n;++i)
    {
        cout << dp[i] << " ";
    }
    */
    cout << dp[n - 1]<<"\n";
}
int qury(int * prior_Sum,int ed,int v)//ed會後一個 回傳前v個的和
{
    if(ed-v-1<0)
    {
        return prior_Sum[ed];
    }
    return prior_Sum[ed] - prior_Sum[ed - v-1];
}