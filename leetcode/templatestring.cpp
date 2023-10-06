#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string interpret(string command) {
        string cash;
        string ans;
        for(auto it=command.begin(); it!=command.end();++it)
        {
            cash += *it;
            if(cash=="G")
            {
                ans += cash;
                cash.clear();
            }
            else if(cash=="()")
            {
                ans+="o";
                cash.clear();
            }
            else if(cash=="(al)")
            {
                ans+="al";
                cash.clear();
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
    cout<<s.interpret("G()(al)");
    return 0;
}