#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 2147483647));
        for(int i = 0; i < n; i++)
        {
                dp[0][i] = grid[0][i];
        }

        for(int i = 0; i < m-1; i++)
        {
            for (int j = 0; j < n;j++)
            {
                for (int k = 0; k < n;k++)
                {
                    dp[i+1][k] = min(dp[i+1][k],dp[i][j]+moveCost[grid[i][j]][k]+grid[i+1][k]);
                }
            }
        }
        
        
        
        return *min_element(dp[m-1].begin(), dp[m-1].end());
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<vector<int>> grid = {{5,3},{4,0},{2,1}};
    vector<vector<int>> moveCost = { {9, 8}, {1, 5}, {10, 12}, {18, 6}, {2, 4}, {14, 3}};
    cout<<s.minPathCost(grid,moveCost)<<"\n";
    return 0;
}