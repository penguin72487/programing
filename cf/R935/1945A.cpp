#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int introverts, extroverts, guests;
        cin>>introverts>>extroverts>>guests;
        int ans = 0;
        ans += introverts + extroverts / 3;
        extroverts %= 3;
        if(extroverts==0)
            ans += (guests + 2) / 3;
        else if(extroverts==1)
        {
            if(guests<2)
            {
                cout<<-1<<endl;
                continue;
            }
            ans += (guests - 2 + 2) / 3+1;
        }
        else if(extroverts==2)
        {
            if(guests<1)
            {
                cout<<-1<<endl;
                continue;
            }
            ans += (guests - 1 + 2) / 3+1;
        }
        else
        {
            ans += (guests+2) / 3;
        }
        cout<<ans<<endl;
    }
    return 0;
}