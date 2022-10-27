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
            if(sum>>31==-1)
            {
                sum = 0;
                i_Max = max(i_Max, *it);
            }
            else{
                i_Max = max(i_Max, sum);
            }
        }
        return i_Max;
    }
    int max(int a,int b)
    {
        int m=(a-b)>>31;
        return (a&~m)|(b&m);
    }
    int min(int a,int b)
    {
        int m=(a-b)>>31;
        return (a&m)|(b&~m);
    }

};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<s.maxSubArray(num);
}