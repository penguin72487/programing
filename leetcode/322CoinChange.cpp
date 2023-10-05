#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<coins.size();j++){
                if(coins[j]<=i){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
        }
        return (dp[amount]==INT_MAX-1)?-1:dp[amount];
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    vector<int> coins = {1,2,5};
    int amount = 11;
    cout<<s.coinChange(coins,amount);
    
    return 0;
}