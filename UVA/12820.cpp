#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    int k = 0;
    while(cin>>n&&n!=0){
        ++k;
        string s;
        vector<vector<int>> c(n, vector<int>(26, 0));
        for(int i=0; i<n;++i)
        {
            cin >> s;
            for(auto& it:s)
            {
                ++c[i][it - 'a'];
            }
        }
        int ans = 0;
        for(int i=0; i<n;++i)
        {
            set<int> si;
            multiset<int> msi;
            for(auto& it:c[i])
            {
                if(it<=0)
                {
                    continue;
                }
                si.insert(it);
                msi.insert(it);
            }
            if(si.size()==1)
            {
                continue;
            }
            ans += (si.size() == msi.size());
        }
        
        cout <<"Case "<<k<<": "<< ans << "\n";
    }
    return 0;
}



