#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum&1) return false;
        sum >>= 1;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int i=0; i<nums.size(); i++){
            for(int j=sum; j>=nums[i]; j--){
                dp[j] = dp[j] || dp[j-nums[i]];
            }
        }
        return dp[sum];
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    vector<int> nums = {1,5,11,5};
    cout << s.canPartition(nums) << endl;
    return 0;
}