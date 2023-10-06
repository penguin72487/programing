#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> a(26, 0);
        vector<int> b(26, 0);
        for(auto it=s.begin(); it!=s.end(); ++it)
        {
            ++a[*it - 'a'];
        }
        for(auto it=t.begin(); it!=t.end(); ++it)
        {
            ++b[*it - 'a'];
        }
        for (int i = 0; i < 26;++i)
        {
            if(b[i]>a[i])
            {
                return (char)(i + 'a');
            }
        }
        return 'a';
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    cout<<s.findTheDifference("abcd","abcde");
}