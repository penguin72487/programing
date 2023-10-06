#include<bits/stdc++.h>
using namespace std;
#define matrix array<array<long long,2>,2>
const long long MOD = 1000000007;

matrix operator*(matrix a, matrix b)
{
    matrix ans = {{{{0, 0}}, {{0, 0}}}};
    for(int i=0; i<2;i++)
    {
        for(int j=0; j< 2;++j)
        {
            ans[i][j] = ((a[i][0] * b[0][j])%MOD+(a[i][1]*b[1][j])%MOD)%MOD;
        }
    }
    return ans;
}
long long q_Pow(matrix B,long long n)
{
    
    matrix Ans = {{{{1, 0}}, {{0, 1}}}};
    if(n==0) 
    return 0;
    if(n==1)
    return 1;
    --n;
    while(n)
    {
        if(n&1)
        {
            Ans = Ans * B;
        }
        B = B * B;
        n>>=1;
    }
    return Ans[0][0];

}
long long operator^(matrix a,long long n)
{
    return q_Pow(a, n);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    matrix a={{{{1, 1}}, {{1, 0}}}};
    long long n;
    cin >> n;
    cout << q_Pow(a, n)<< "\n";
    return 0;
}