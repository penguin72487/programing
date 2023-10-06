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
        int Dxy, Dalt;
        cin >> Dxy >> Dalt;
        vector<tuple<int, int, int, int>> fly;//ID x y alt
        vector<tuple<int, int, int, int>> dist;//ID iD dist alt
        for(int i=0; i<n; i++)
        {
            int ID,x, y, alt;
            cin >>ID>> x >> y >> alt;
            for(auto [ID1, x1, y1, alt1]:fly)
            {
                float o_Dist =  sqrt(abs(x1 - x) * abs(x1 - x) + abs(y1 - y) * abs(y1 - y));
                dist.push_back({min(ID1, ID), max(ID1, ID),ceil(o_Dist), abs(alt1-alt)});
            }
            fly.push_back({ID, x, y, alt});
        }
        sort(dist.begin(), dist.end());
        int count=0;
        for(auto [ID1, ID2, dist, alt]:dist)
        {
            if(dist<=Dxy || alt>=Dalt)
            {
                count++;
                cout<<ID1<<" "<<ID2<<" "<<dist<<" "<<alt<<"\n";
            }
        }
        cout<<count<<"\n";

    }
    return 0;
}