#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int i_Max = 0;
        for(auto it = accounts.begin(); it!=accounts.end();++it)
        {
            i_Max = max(i_Max, accumulate(it->begin(), it->end(),0));
        }
        return i_Max;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<vector<int>> num ={{1,2,3},{3,2,1}};
    cout << s.maximumWealth(num);
}