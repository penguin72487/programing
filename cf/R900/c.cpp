#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long n, k, x;
        cin >> n >> k >> x;
        long long lower = (1 + k) * k / 2;
        long long upper = (2 * n - k + 1) * k / 2;
        if(lower<=x && x<=upper) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}