#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
long long q_2Pow(long long n)
{
    long long int ans=1;
    long long a = 1;
    //int b=1;
    while(n)
    {
        if(n&1)
        {
            ans*=a;
            ans%=MOD;
        }
        n>>=1;
        a*=a;
        a%=MOD;
    }
    return ans;
}


int main()
{
    long long int a;
    cin>>a;
    cout<<q_Pow(2,a)<<"\n";
}
