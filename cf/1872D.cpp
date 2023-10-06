#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long  n;
        cin >> n;
        long long  a, b;
        cin >> a >> b;
        long long  a_Nums = n/a, b_Nums = n/b;
        long long  lcm = a*b/__gcd(a,b);
        long long  lcm_Nums = n/lcm;
        a_Nums -= lcm_Nums;
        b_Nums -= lcm_Nums;
        long long ans = (n+n-a_Nums+1)*(a_Nums)/2 - (1+b_Nums)*(b_Nums)/2;
        cout << ans << "\n";
    }
    return 0;
}