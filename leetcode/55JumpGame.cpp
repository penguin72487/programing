#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i_Max = nums[0];
        int n = nums.size();
        for(int i = 0; i < n&&i<i_Max+1;++i)
        {
            i_Max = max(i_Max, i + nums[i]);
        }
        if(i_Max>=n-1)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {3,2,1,0,4};
    cout<<s.canJump(num);
}