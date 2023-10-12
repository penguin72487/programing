#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> v(n);

        for(auto& it : v)
        {
            cin>>it;
        }
        vector<string> v1(v);
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                v[i][j] = max({v[i][j], v[j][n - i - 1], v[n - j - 1][i], v[n - i - 1][n - j - 1]});
                v[j][n - i - 1] = v[i][j];
                v[n - j - 1][i] = v[i][j];
                v[n-i-1][n-j-1] = v[i][j];
            }
        }
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                ans+=v[i][j]-v1[i][j];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}