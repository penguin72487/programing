#include<iostream>
#include<cmath>
using namespace std;
int b_Big(long long a, long long b);
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int ans = 0;
    long long int a, b;
    for (int i = 0; i < n;++i)
    {
        cin >> a >> b;
        ans += b_Big(a,b);
    }
    cout << ans << "\n";
}
int b_Big(long long a, long long b)
{
    int ans = 0;
    while(b)
    {
        if((b&1)&&!(a&1))
        {
            ++ans;
        }
        a >>= 1;
        b >>= 1;
    }
    return ans;
}