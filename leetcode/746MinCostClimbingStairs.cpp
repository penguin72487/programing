#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        cost.push_back(0);
        vector<int> dp(cost);
        vector<int> from(n+1,-1);
        //dp[0] = 0;
        //dp[1] = 0;
        ++n;
        //bool flag = false;
        for (int i = 2; i < n;++i){
            // if(dp[i-2]<=dp[i-1])
            // {
            //     from[i] = i - 2;
            // }
            // else {
            //     from[i] = i - 1;
            // }
            dp[i] = min(dp[i - 1], dp[i - 2])+cost[i];
        }
        // cost.clear();
        // int now = n - 1;
        // for (int now = n - 1; from[now] != -1;now=from[now])
        // {
        //     cost.push_back(now);
        // }

        return dp[n-1];
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    //vector<int> cost = {10,15,20};
    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    cout<<s.minCostClimbingStairs(cost);
}