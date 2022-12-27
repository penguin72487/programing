#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    vector<int> seg(10000001, 0);
    cin >> n;
    int l, r;//[ l,r)
    for(int i = 0; i < n; i++)
    {
        cin >> l >> r;
        seg[l] += 1;
        seg[r] -= 1;
    }
    partial_sum(seg.begin(), seg.end(), seg.begin());
    int sum = 0;
    for(auto& it : seg)
    {
        sum += bool(it);
    }
    cout << sum << "\n";
    return 0;
}