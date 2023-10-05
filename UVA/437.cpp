#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    int t = 0;
    while(cin>>n&&n!=0)
    {
        ++t;
        long long a, b, c;
        vector<tuple<long long, long long, long long>> vtll;
        for(int i=0; i<n; i++)
        {
            cin >> a >> b >> c;
            vtll.push_back({a,b,c});
            vtll.push_back({a,c,b});
            vtll.push_back({b,a,c});
            vtll.push_back({b,c,a});
            vtll.push_back({c,b,a});
            vtll.push_back({c,a,b});

        }
        sort(vtll.begin(), vtll.end());
        vector<long long> v(vtll.size());
        for (int i = 0;i<vtll.size();i++)
        {
            auto [L, W, H] = vtll[i];
            v[i] = H;
            for (int j = 0;j<i;++j)
            {
                auto [l,w,h] = vtll[j];
                if(L>l&&W>w)
                {
                    v[i] = max(v[i], v[j] + H);
                }
            }
        }
        cout << "Case " << t << ": maximum height = " << *max_element(v.begin(), v.end()) << "\n";
    }
    return 0;
}
