#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int ans = 0;
        for(auto i:nums)
        {
            ans ^= i;
        }
        return ans;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {1,1,2,3,3,4,4,8,8};
    cout<<s.singleNonDuplicate(num)<<"\n";
    return 0;
}