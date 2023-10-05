#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string s, string t) {
        auto it=t.begin();
        string ans;
        for(auto jt:s)
        {
            for(;it!=t.end();++it)
            {
                if(jt==*it)
                {
                    ans+=jt;
                    break;
                }
            }
        }
        return (ans==s);

    }
};
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    Solution s;
    cout<<s.isSubsequence("aaaaaa","bbaaaa");
    return 0;
}