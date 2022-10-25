#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(auto it=nums.begin(); it!=nums.end();++it)
        {
            if(*it==0)
            {
                nums.erase(it);
                nums.push_back(0);
            }
        }
        return;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {0,1,0,3,12};
    s.moveZeroes(num);
}