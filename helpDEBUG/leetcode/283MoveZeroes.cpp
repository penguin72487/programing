#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(nums.size() == 1)
        {
            return;
        }
        int p = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[p]);
                p++;
            }
        }
        return;
    }
    void swap(int &a,int &b)
    {
        a^=b^=a^=b;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {0,1};
    s.moveZeroes(num);
}