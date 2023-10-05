#include <bits/stdc++.h>
#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
typedef long long ll;
const ll MAX = 1LL << 60;
 
int main(){
    StarBurstStream
 
    int n, m;
    cin >> n >> m;
 
    vector<vector<ll>> dp(2, vector<ll>(m + 1, MAX));
    int now = 0, lst = 1;
    dp[0][0] = 0;
 
    for(int i = 0; i < n; i++){
        int t, s;
        cin >> t >> s;
        swap(now, lst);
        dp[now] = dp[lst];
        
        for(int j = 0; j <= m; j++){
            int tmp = min(m, j + s);
            dp[now][tmp] = min(dp[now][tmp], dp[lst][j] + t);
        }
    }
 
    cout << dp[now][m] << "\n";
 
    return 0;
}