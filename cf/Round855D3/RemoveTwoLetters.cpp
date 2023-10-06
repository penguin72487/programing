#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = n-1;
        for (int i = 2; i < n;++i)
        {
            if(s[i]==s[i-2])
            {
                ans--;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}