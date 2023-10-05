#include<iostream>
using namespace std;
long long gcd(long long a, long long b)
{
    if( b==0 )
        return a;
    return gcd( b, a%b );
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    while(cin >> n&&n!=0)
    {
        long long ans = 0;
        for(int i = 1; i < n;++i)
        {
            for (int j = i + 1; j <= n;++j)
            {
                ans += gcd(i, j);
            }
        }
        cout << ans << "\n";
    }

    

    return 0;
}