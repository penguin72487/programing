#include<iostream>
using namespace std;
long long gcd(long long a,long long b)
{
    if(!b)
    return a;
    return gcd( b, a%b );
}
long long lcm(long long a,long long b)
{
    return a*b/gcd(a,b); 
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long int a, b;
    cin >> a >> b;
    cout << lcm(a, b);

    return 0;
}