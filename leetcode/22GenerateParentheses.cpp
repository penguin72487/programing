#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        gen(string(""),n,0,0,n);
        return ans;
    }
    void gen(string s, int up,int l,int r,int now)
    {
        if(s.size()==(up<<1))
        {
            ans.push_back(s);
            return;
        }
        if(l<up)
        {
            gen(s+"(",up,l+1,r,now-1);
        }

        //gen(s+"()",up,l+1,r+1,now-1);
        if(l>r)
        {
            gen(s+")",up,l,r+1,now-1);
        }
        
        
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    vector<string> vs(s.generateParenthesis(3));
    for(auto& it:vs)
    {
        cout << it << "\n";
    }
}