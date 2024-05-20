#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> dp(n,0);
        for(auto i:trust){
            dp[i[0]-1]--;
            dp[i[1]-1]++;
        }
        auto it= find(dp.begin(),dp.end(),n-1);
        if(it!=dp.end()){
            return it-dp.begin()+1;
        }
        return -1;
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    int n = 3;
    vector<vector<int>> trust = {{1,3},{2,3}};
    cout << s.findJudge(n, trust);
    return 0;
}