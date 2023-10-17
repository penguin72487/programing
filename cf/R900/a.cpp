#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(auto& i : a) cin >> i;
        sort(a.begin(), a.end());
        cout<<(binary_search(a.begin(), a.end(), k) ? "YES" : "NO")<<"\n";

    }
    return 0;
}