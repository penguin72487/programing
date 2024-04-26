#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        for (int i = 2,n=nums.size();i<n;++i) {
            if(nums[i-2]<nums[i-1]+nums[i])
            {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }

            return 0;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> nums = {2,1,2};
    cout<<s.largestPerimeter(nums);
}