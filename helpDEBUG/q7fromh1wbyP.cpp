#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin>>n;
    int l, r;
    set<int> seg;
    for(int i=0; i<n; i++)
    {
        cin >> l >> r;
        seg.insert(l);
        seg.insert(r);
    }
    bool flag = false;
    for(auto& it:seg)
    {
        cout << it;
        cout << (flag ? "\n" : " ");
        flag ^= 1;
    }
    return 0;
}