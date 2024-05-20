#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        if(word1.length()>word2.length()) {
            auto it=word1.begin();
            auto jt=word2.begin();
            for (;jt<word2.end();++it,++jt) {
                ans+=*it;
                ans+=*jt;
            }
            for (;it<word1.end();++it) {
                ans+=*it;
            }
        }
        else {
            auto it=word1.begin();
            auto jt=word2.begin();
            for (;it<word1.end();++it,++jt) {
                ans+=*it;
                ans+=*jt;
            }
            for (;jt<word2.end();++jt) {
                ans+=*jt;
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
    cout<<s.mergeAlternately("abcd","pq");
}