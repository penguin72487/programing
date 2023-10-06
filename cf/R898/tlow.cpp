#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &i:a)cin>>i;
    sort(a.begin(),a.end());
    cout<<lower_bound(a.begin(),a.end(),2)-a.begin()<<"\n";
    cout<<upper_bound(a.begin(),a.end(),2)-a.begin()<<"\n";
    return 0;
}