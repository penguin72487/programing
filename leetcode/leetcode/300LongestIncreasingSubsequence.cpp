#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp;
        for(int i=0;i<nums.size();i++){
            auto it = lower_bound(dp.begin(),dp.end(),nums[i]);
            if(it==dp.end()){
                dp.push_back(nums[i]);
            }else{
                *it = nums[i];
            }
        }
        return dp.size();
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout<<s.lengthOfLIS(nums);
    return 0;
}