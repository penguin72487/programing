#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n,2147483647);
        dp[0] = cost[0];
        dp[1] = cost[1];
        bool flag = false;
        for (int i = 0; i < n;++i){

        }

            return 0;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> cost = {10, 15, 20};
    cout<<s.minCostClimbingStairs(cost);
}