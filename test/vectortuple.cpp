#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    vector<tuple<long long, long long, long long>> vtll;
    vtll.push_back({0,0,0});
    vtll.push_back({10, 20, 30});
    vtll.push_back({100, 200, 300});
    auto it = lower_bound(vtll.begin(), vtll.end(),make_tuple(11,21,31));
    *it = {11, 21, 31};
    auto [l,w,h] = vtll.back();
    cout << l << " " << w << " " << h << "\n";
    return 0;
}