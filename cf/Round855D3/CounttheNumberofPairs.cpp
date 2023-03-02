#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n,k;
        cin >> n>>k;
        string s;
        cin >> s;
        vector<int> up(26,0);
        vector<int> down(26,0);
        for (int i = 0; i < n; ++i)
        {
            if(s[i]>='A'&&s[i]<='Z')
            {
                up[s[i]-'A']++;
            }
            else
            {
                down[s[i]-'a']++;
            }
        }
        int ans = 0;
        int less = 0;
        for(int i = 0; i < 26; ++i)
        {

            int tmp=0; 
            tmp =min(up[i],down[i]);

                
            ans += tmp;
            up[i]-=tmp;
            down[i]-=tmp;
            if(up[i]>0)
            {
                less+=up[i]/2;
            }
            else
            {
                less+=down[i]/2;
            }
        }
        ans+=min(less,k);
        cout << ans << "\n";
    }
    return 0;
}