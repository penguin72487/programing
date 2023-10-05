#include<bits/stdc++.h>
using namespace std;
#define matrix vector<vector<long long>>

matrix operator*(matrix a, matrix b)
{
    int n=a.size();
    matrix ans(n, vector<long long>(n,(1ll<<60) ));

    for(int i=0; i<n;i++)
    {
        for(int j=0; j< n;++j)
        {
            for(int k=0; k< n;++k)
            {
                ans[i][j] = min(ans[i][i], a[i][k] + b[k][j]);
            }
            
        }
    }
    return ans;
}
matrix q_Pow(matrix B,long long n)
{
    int m=B.size();
    matrix Ans(B);
    
    // for(int i=0;i<m;++i)
    // {
    //     Ans[i][i] = 1;
    // }
    if(n==0) 
    return Ans;
    if(n==1)
    return B;
    while(n)
    {
        if(n&1)
        {
            Ans = Ans * B;
        }
        B = B * B;
        n>>=1;
    }
    return Ans;

}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long n, m, k;
    cin >> n >> m >> k;
    matrix a(n, vector<long long>(n, (1ll<<60)));
    for(int i = 0; i < m; ++i){
        long long l, r,c;
        cin >> l >> r>>c;
        --l;
        --r;
        a[l][r] = min(a[l][r], c);
    }
    cout << (q_Pow(a, k)[0][n - 1] < (1ll<<60)?q_Pow(a, k)[0][n - 1]:-1)<<"\n";

    return 0;
}