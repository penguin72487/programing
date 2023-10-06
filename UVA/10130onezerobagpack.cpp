#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int v[n];
        int w[n];
        for(int i=0; i<n; ++i){
            cin >> v[i]>>w[i];
        }
        int q;
        cin >> q;
        int max_W;
        long long sum = 0;
        while(q--)
        {
            cin >> max_W;
            int dp[max_W+1];
            fill(dp, dp + max_W+1, 0);

            for(int i=0; i<n; ++i)
            {
                for(int j=max_W; j>=w[i];--j)
                {
                    dp[j] = max(dp[j],dp[j - w[i]] + v[i]);
                }
            }
            sum += dp[max_W];
            
        }
        cout << sum << "\n";
    }
    return 0;
}