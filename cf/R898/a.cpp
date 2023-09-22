#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        string st = "abc";
        int count = 0;
        for (int i = 0; i < 3;++i)
        {
            if(s[i]!=st[i])
            {
                count++;
            }
        }
        if(count&1)
        {
            cout << "NO\n";
        }
        else
        {
            cout << "YES\n";
        }
    }
    return 0;
}