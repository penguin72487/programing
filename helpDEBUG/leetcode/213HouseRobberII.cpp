#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n ? nums[0] : 0;
        auto it1=nums.begin();
        ++it1;
        auto ed1=nums.end();--ed1;
        vector<int> a;
        vector<int> b;
        a.assign(nums.begin(), ed1);
        b.assign(it1, nums.end());
        return max(robb(a),robb(b));
    }
    int robb(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums.back();
        }
        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i = 2; i < n;++i){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return max(dp[n - 1],dp[n - 2]);
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {1,2,3,1};
    cout<<s.rob(num);
}