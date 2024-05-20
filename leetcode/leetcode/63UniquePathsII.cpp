#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<long long>> dp(m+1,vector<long long>(n+1,0));
        dp[0][1]=1;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(!obstacleGrid[i-1][j-1]){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m][n];
    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    vector<vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};
    cout << s.uniquePathsWithObstacles(obstacleGrid) << endl;
    return 0;
}