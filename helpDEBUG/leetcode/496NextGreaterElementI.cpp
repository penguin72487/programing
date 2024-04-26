#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        for(auto it=nums1.begin(); it!=nums1.end();++it)
        {
            auto jt = nums2.begin();
            for (; jt != nums2.end(); ++jt)
            {
                if(*jt==*it)
                {
                    break;
                }
            }
            bool flag = 0;
            for (;jt<nums2.end();++jt)
            {
                if(*jt>*it)
                {
                    *it = *jt;
                    flag = 1;
                    break;
                }
            }
            if(!flag)
            {
                *it = -1;
            }
        }
        return nums1;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {4,1,2};
    vector<int> nums2={1,3,4,2};
    auto jt=s.nextGreaterElement(num,nums2);
}