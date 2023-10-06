#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int ne=0;
        int po=0;
        for(auto it=nums.begin(); it!=nums.end();++it)
        {
            if(*it<0)
            {
                ++ne;
            }
            else if(*it>0)
            {
                ++po;
            }
            else {
                return 0;
            }
        }
        if(ne&1)
        {
            return -1;
        }
        else {
            return 1;
        }
        
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {-1,-2,-3,-4,3,2,1};
    cout << s.arraySign(num);
}