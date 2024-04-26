#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if(r*c!=mat.size()*mat[0].size())
        {
            return mat;
        }
        vector<vector<int>> ans(r, vector<int>(c));
        vector<int> a;
        for(auto it=mat.begin(); it!=mat.end();++it)
        {
            for(auto jt = it->begin(); jt != it->end();++jt)
            {
                a.push_back(*jt);
            }
        }
        auto kt=a.begin();
        for(auto it=ans.begin(); it!=ans.end();++it)
        {
            for(auto jt = it->begin(); jt != it->end();++jt)
            {
                *jt = *kt;
                ++kt;
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
    vector<vector<int>> num = {{1,2},{3,4}};
    int r=1, c=4;
    s.matrixReshape(num, r, c);
}