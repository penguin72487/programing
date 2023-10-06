#include<bits/stdc++.h>
using namespace std;
int main(){
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);
    string s;
    while(cin>>s)
    {
        // if(s=="0")
        // {
        //     break;
        // }
        vector<int> v(256, 0);
        for(auto& it:s)
        {
            ++v[it];
        }

        vector<pair<int, int>> vpii;
        for (int i = 0; i < 256;++i)
        {
            if(v[i] >0)
            {
                vpii.push_back({i, v[i]});
            }
        }
        sort(vpii.begin(), vpii.end(),[](auto& a,auto& b)->bool{
            if(a.second == b.second)
            {
                return (a.first > b.first);
            }
            else {
                return (a.second< b.second);
            }
        });
        for(auto& it:vpii)
        {
            cout << it.first << " " << it.second << "\n";
        }
        cout << "\n";
    }
    return 0;
}
