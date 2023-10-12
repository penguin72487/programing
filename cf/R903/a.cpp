#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        string s, t;
        cin>>s>>t;
        int ans = 0;
        if(s.size() > t.size())
        {
            if(s.find(t) != string::npos)
            {
                cout<<ans<<"\n";
                continue;
            }
            s+=s;
            ans++;
            if(s.find(t) != string::npos)
            {
                cout<<ans<<"\n";
                continue;
            }
            else{
                cout<<-1<<"\n";
                continue;
            }
        }
        while(s.size() <t.size()*3)
        {
            if(s.find(t) != string::npos)
            {
                cout<<ans<<"\n";
                break;
            }
            s += s;
            ans++;
        }
        if(s.size() >=t.size()*3)
        {
            cout<<-1<<"\n";
        }
    }
    return 0;
}