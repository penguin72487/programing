#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<int> dp(2001, 0);
        dp[nums[0]+1000] = 1;
        dp[-nums[0]+1000] += 1;
        for(int i=1; i<nums.size(); i++){
            vector<int> next(2001, 0);
            for(int sum=-1000; sum<=1000; sum++){
                if(dp[sum+1000] > 0){
                    next[sum+nums[i]+1000] += dp[sum+1000];
                    next[sum-nums[i]+1000] += dp[sum+1000];
                }
            }
            dp = next;
        }
        return target>1000?0:dp[target+1000];
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    vector<int> nums = {1,1,1,1,1};
    int target = 3;
    cout << s.findTargetSumWays(nums, target) << endl;

    return 0;
}