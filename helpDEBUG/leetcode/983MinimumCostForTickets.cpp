#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.back() + 1, 0);
        unordered_set<int> travelDays(days.begin(), days.end());
        
        for (int i = 1; i < dp.size(); i++) {
            if (travelDays.count(i) == 0) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = min({dp[i-1] + costs[0],dp[max(0, i-7)] + costs[1],dp[max(0, i-30)] + costs[2]});
            }
        }
        
        return dp.back();
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    vector<int> days={1,5,8,9,10,12,13,16,17,18,19,20,23,24,29};
    vector<int> costs={3,12,54};
    cout << s.mincostTickets(days, costs) << endl;
    return 0;
}