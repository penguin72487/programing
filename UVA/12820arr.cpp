
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
            if(s.size()==1)
            {
                s.push_back(s[0]+1);
            }
            for(auto& it:s)
            {
                ++c[i][it - 'a'];
            }
        }
        int ans = 0;
        
        for(int i=0; i<n;++i)
        {
            vector<int> vi(31);
            bool flag = 1;
            for(auto& it:c[i])
            {
                ++vi[it];
            }
            for (int i = 1; i < 31;++i)
            {
                if(vi[i] >1)
                {
                    flag = 0;
                    break;
                }
            }
            ans += flag;
        }



        cout <<"Case "<<k<<": "<< ans << "\n";
    }
    return 0;
}



