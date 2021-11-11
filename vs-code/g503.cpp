#include<iostream>
#include<cmath>
using namespace std;
long long q_Pew(long long a, long long n);
int main()
{
    long long n, x, md;
    cin >> n >> x >> md;
    int a, b;
    long long ans = 0;
    for (int i = 0; i < n;++i)
    {
        cin >> a >> b;
        ans += a * q_Pew(x,b);
    }
    ans = abs(ans);
    ans %= q_Pew(10,md);
    int m = md-log10(ans);
    for (int i = 0; i < m;++i)
    {
        cout << "0";
    }
    cout << ans << "\n";
}
long long q_Pew(long long a, long long n)
{
    long long ans = 1;
    while(n)
    {
        if(n&1)
        {
            ans *= a;
        }
        a *= a;
        n >>= 1;
    }
    return ans;
}