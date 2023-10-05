#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> a(10002,0);
        //vector<int> a(12,0);
        int sum = 0;
        for(auto it=nums.begin(); it!=nums.end();++it)
        {
            a[*it]+=*it;
        }
        vector<int> tmp;
        auto it = a.begin();
        auto ed = a.end();
        for(; it!=a.end();++it)
        {
            if(*it!=0)
            {
                auto jt = it;
                ++jt;
                while(jt!=a.end())
                {
                    if(*jt==0)
                    {
                        tmp.clear();
                        tmp.assign(it,jt);
                        sum += get(tmp);
                        ed = jt;
                        break;
                    }
                    ++jt;
                }
                it = jt;
            }
        }
        return sum;
    }
    int get(vector<int>&nums)
    {
        int n = nums.size();
        if(n==1)
        {
            return nums[0];
        }
        else if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i = 2; i < n;++i){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return max(dp[n - 1],dp[n - 2]);
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<int> num = {1,2,3,15,16,17,18};
    sort(num.begin(), num.end());
    cout<<s.deleteAndEarn(num);
}