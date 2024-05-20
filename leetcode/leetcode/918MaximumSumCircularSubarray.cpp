#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        vector<int> a;
        vector<int> b;
        a.push_back(nums.back());
        a.insert(a.end(), nums.begin(), --nums.end());
        b.assign(++nums.begin(), nums.end());
        b.push_back(nums[0]);
        return max(maxSubArray(a),maxSubArray(b));
    }
    int maxSubArray(vector<int>& nums) {
        int i_Max = -300000;
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
    vector<int> num = {-2,4,-5,4,-5,9,4};
    cout<<s.maxSubarraySumCircular(num);
}