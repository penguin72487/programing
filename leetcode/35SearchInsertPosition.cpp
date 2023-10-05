#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();

    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {1,3,5,6};
    int target = 5;
    cout<<s.searchInsert(num,target)<<"\n";
    return 0;
}