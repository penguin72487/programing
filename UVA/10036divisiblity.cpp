#include<iostream>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        int a[n];
        for(auto& it:a){
            cin >> it;
            it = abs(it) % k;
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));//dp[n][k]
        dp[0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                if(dp[i][j])
                {
                    dp[i + 1][((j + k + a[i]) % k+k)%k] = 1;
                    dp[i + 1][((j + k - a[i]) % k+k)%k] = 1;
                }
            }
        }
        if(dp[n][0])
        {
            cout << "Divisible\n";
        }
        else 
        {
            cout << "Not divisible\n";
        }
    }
    return 0;
}