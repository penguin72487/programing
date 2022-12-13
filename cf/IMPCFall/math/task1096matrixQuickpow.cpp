#include<bits/stdc++.h>
using namespace std;
#define matrix array<array<long long,6>,6>
const long long MOD = 1000000007;

matrix operator*(matrix a, matrix b)
{
    matrix ans={};
    int n=a.size();
    for(int i=0; i<n;i++)
    {
        for(int j=0; j< n;++j)
        {
            for(int k=0; k< n;++k)
            {
                ans[i][j] += (a[i][k] * b[k][j]) % MOD;
                ans[i][j] %= MOD;
            }
            
        }
    }
    return ans;
}
matrix q_Pow(matrix B,long long n)
{
    
    matrix Ans={};
    int m=B.size();
    for(int i=0;i<m;++i)
    {
        Ans[i][i] = 1;
    }
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
    matrix a={{{{1, 1,1,1,1,1}},{{1,0,0,0,0}},{{0, 1,0,0,0,0}},{{0, 0,1,0,0,0}},{{0, 0,0,1,0,0}},{{0, 0,0,0,1,0}}}};
    long long n;
    cin >> n;
    cout << q_Pow(a, n)[0][0]<< "\n";
    return 0;
}