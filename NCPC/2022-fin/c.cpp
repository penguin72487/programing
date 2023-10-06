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
        vector<int> v(n);
        for(auto &i:v)
            cin>>i;
        adjacent_difference(v.begin(),v.end(),v.begin());
        v[0] = 0;
        long long ans = 0;
        for(auto i:v)
        {
            if(i>0)
                ans+=i;
        }
        cout << ans << "\n";
    }
    return 0;
}
/*
2
6
112 111 113 117 115 118
5
210 209 208 207 206
*/