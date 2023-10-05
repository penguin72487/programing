#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> a(26,0);
        vector<int> b(26,0);
        // for(auto it=s.begin(); it!=s.end(); ++it)
        // {
        //     ++a[*it - 'a'];
        // }
        unordered_map<char, bool> cb_Map;
        for(auto it=t.begin(); it!=t.end(); ++it)
        {
            ++b[*it - 'a'];
            cb_Map[*it] = true;
        }
        vector<string::iterator> sit;
        for (auto it = s.begin();it!=s.end(); ++it)
        {
            if(cb_Map.find(*it) != cb_Map.end())
            {
                sit.push_back(it);
            }
        }
        ++b[*sit[0] - 'a'];
        string s="";
        for(auto it = next(sit.begin());it!=sit.end(); ++it)
        {
            --[**prev(it) - 'a'];
            ++b[**it - 'a'];
        }
        return s;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    string ss="ADOBECODEBANC";
    string t="ABC";
    cout << s.minWindow(ss,t);
}