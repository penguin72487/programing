#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string toLowerCase(string s) {
        for(auto it=s.begin(); it!=s.end(); ++it)
        {
            if(*it>='A'&&*it<='Z')
            {
                *it += 'z' - 'Z';
            }
        }
        return s;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    cout<<s.toLowerCase("LOVELY");
}