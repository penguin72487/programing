#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        long long ans=0;
        for (int i = 0; i < n;++i)
        {
            if(s[i]=='B')
            {
                ++ans;
                for (int j = i;j<n&&j<i+k;++j)
                {
                    s[j] = 'W';
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}