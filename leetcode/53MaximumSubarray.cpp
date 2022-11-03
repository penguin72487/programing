#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int i_Max = -100000;
        int sum = 0;
        for(auto it =nums.begin(); it!=nums.end();++it)
        {
            sum+=*it;
            i_Max = max(i_Max, sum);
            if(sum<0)
            {
                sum = 0;
            }
        }
        return i_Max;
    }
};
