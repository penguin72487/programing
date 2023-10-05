#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool areAlmostEqual(string s, string t) {
        vector<int> a(26,0);
        vector<int> b(26,0);
        for(auto it=s.begin(); it!=s.end(); ++it){
            ++a[*it-'a'];
        }
        for(auto it=t.begin(); it!=t.end(); ++it){
            ++b[*it-'a'];
        }
        if (a!=b)
        {
            return 0;
        }
        int i = 0;
        for (auto it = s.begin(), jt=t.begin();it!=s.end();++it,++jt) {
            if(*it!=*jt){
                ++i;
            }
        }
        return i==2||i==0? 1:0;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    string ss = "abcd";
    string t="dcba";
    cout << s.areAlmostEqual(ss,t);
}