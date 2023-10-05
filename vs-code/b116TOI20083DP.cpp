#include<iostream>
using namespace std;
bool b_eqSuum(int *tmp,int n);
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int p[m];
        for (int i = 0; i < n;++i)
        {

            for (int j = 0; j < m;++j)
            {
                cin >> p[j];
            }
            if(b_eqSuum(p,m))
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }

}
bool b_eqSuum(int *tmp,int n)
{
    //int n = sizeof(tmp);
    
    --n;
    int dp[tmp[n]];
    fill(dp, dp + tmp[n],0);
    for (int i = 0; i < n;++i)
    {
        for (int j = tmp[n]; j >=tmp[i];--j)
        {
            dp[j] = max(dp[j], dp[j - tmp[i]] + tmp[j]);
        }
    }
    return (dp[tmp[n]] == tmp[n]);
}