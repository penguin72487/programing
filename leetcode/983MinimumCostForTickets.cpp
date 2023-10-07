#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        days.insert(days.begin(),0);
        int n=days.back();
        vector<long long> dp(n + 1, INT_MAX);
        dp[0]=0;
        for (int i = 1; i <=n;++i)
        {
            auto ont=lower_bound(days.begin(),days.end(),i-1);
            auto wkt=lower_bound(days.begin(),days.end(),i-7);
            auto mnt=lower_bound(days.begin(),days.end(),i-30);
            dp[i]=min(dp[i],dp[*ont]+costs[0]);
            dp[i]=min(dp[i],dp[*wkt]+costs[1]);
            dp[i]=min(dp[i],dp[*mnt]+costs[2]);
        }
        return dp[n];
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    vector<int> days={1,4,6,7,8,20};
    vector<int> costs={2,7,15};
    cout<<s.mincostTickets(days,costs)<<endl;
    return 0;
}