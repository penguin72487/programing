#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n=0;
    cin >> n;
    vector<pair<int,int>> lis(n);
    for(auto& it:lis)
    {
        cin>>it.first;
    }
    for(auto& it:lis)
    {
        cin>>it.second;
    }
    sort(lis.begin(),lis.end(), [](auto &a, auto &b)->bool
    { return (a.first * a.second < b.first * b.first); });
    cout << lis[0].first << " " << lis[0].second << "\n";

    return 0;
}