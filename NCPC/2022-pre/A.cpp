#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n*n);
        for(auto& i:v)
            cin >> i;

        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;
        int i_Op=v[a*n+b];
        int i_Ed=v[c*n+d];
        sort(v.begin(), v.end());
        auto it=lower_bound(v.begin(), v.end(),i_Op), jt=lower_bound(v.begin(), v.end(),i_Ed);
        cout<<jt-it-1<<"\n";
        
    }
    return 0;
}