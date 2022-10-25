#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n==1)
        {
            return mat[0][0];
        }
        int ans = 0;
        if(n&1)
        {
            for(int i=0; i<n; ++i)
            {
                ans += mat[i][i];
                ans += mat[i][n-i-1];
            }
            int j = (n >> 1);
            ans-=mat[j][j];
        }
        else {
            for(int i=0; i<n; ++i)
            {
                ans += mat[i][i];
                ans += mat[i][n-i-1];
            }
        }
        return ans;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<vector<int>> num = {{7,9,8,6,3},{3,9,4,5,2},{8,1,10,4,10},{9,5,10,9,6},{7,2,4,10,8}};
    cout << s.diagonalSum(num) << "\n";
}