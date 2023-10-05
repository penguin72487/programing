#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s,t;
        cin>>s>>t;
        if(s==t)
        {
            cout<<"YES\n";
            continue;
        }
        vector<int> count_S(26,0);
        vector<int> count_T(26,0);
        for(auto& it:s)
        {
            count_S[it-'a']++;
        }
        for(auto& it:t)
        {
            count_T[it-'a']++;
        }
        if(count_S!=count_T)
        {
            cout<<"NO\n";
            continue;
        }
        if(n>=k*2)
        {
            cout<<"YES\n";
            continue;
        }
        else if(n<k)
        {
            cout<<"NO\n";
            continue;
        }
        else{
            int can_Move = n - k;
            bool flag = true;
            for (int i = can_Move;i<n-can_Move;++i)
            {
                if(s[i]!=t[i])
                {
                    cout<<"NO\n";
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                cout<<"YES\n";
            }
        }


    
    }
    
    return 0;
}