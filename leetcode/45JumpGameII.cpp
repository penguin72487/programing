#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> v(nums.size(), (1 << 30));
        v[0] = 0;
        for(int i = 0; i < nums.size();++i)
        {
            for (int j = i; j < i + nums[i]+1&&j<nums.size();++j)
            {
                v[j] = min(v[i] + 1, v[j]);
            }
        }
        return v[nums.size() - 1];
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {2,3,1,1,4};
    cout<<s.jump(num);
    return 0;
}