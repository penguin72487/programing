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
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        char c_meow[] = "meow"; // 0 m 1 e 2 o 3 w
        bool flag = true;
        for (int i = 0,j=0; i < 4;++i)
        {
            while(j<n && s[j]==c_meow[i])
            {
                ++j;
            }
            if(s[j]!=c_meow[i]&&s[j]!=c_meow[i+1])
            {
                cout << "NO\n";
                flag = false;
                break;
            }
            if(j==n)
            {
                cout << "YES\n";
                flag = false;
                break;
            }
        }
        // if(flag)
        // cout << "YES\n";
    }
    return 0;
}