#include<iostream>
#include<vector>
using namespace std;
const int MOD = 1e9 + 7;
long long f[2000001];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    f[0] = 0;
    f[1] = 0;
    f[2] = 0;
    f[3] = 4;
    for (int i = 4; i < 2000001;++i)
    {
        if(i%3)
        {
            f[i] = (f[i - 1] + 2 * f[i - 2] % MOD) % MOD;
        }
        else
        {
            f[i] = (f[i - 1] + 2 * f[i - 2] % MOD + 4) % MOD;
        }
    }
        while (t--)
        {
            long long n;
            cin >> n;
            cout << f[n] << "\n";
        }
    return 0;
}