#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        int n=s.size();
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            v[i] = s[i]-'0';
        }
        vector<int> ans(n);
        ans[0] = 1;
        for(int i=2,now=v[0];i<n;i++)
        {
            if(ans[(now+v[now])%n]==0)
            {
                ans[now]=1;
                now=(now+v[now])%n;
                
            }
            else{
                cout<<"No\n";
                goto no;
            }
        }
        cout<<"Yes\n";
        no:;
    }
    return 0;
}
