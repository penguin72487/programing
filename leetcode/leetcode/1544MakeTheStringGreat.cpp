#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string makeGood(string s) {
        bool flag = 1;
        
        
        while(flag)
        {
            bool a[s.size()];
            fill(a,a+s.size(),0);
            flag = 0;
            for(auto it=next(s.begin()); it!=s.end();++it)
            {   
                if(a[distance(s.begin(), it)])
                {
                    continue;
                }

                if(*it>='A'&&*it<='Z')
                {
                    if(*it==(*prev(it)+'A'-'a'))
                    {
                        a[(distance(s.begin(), it))] = 1;
                        a[(distance(s.begin(), it)) - 1] = 1;
                        flag = 1;
                    }
                }
            }
            for(auto it = s.begin(); it != s.end();++it)
            {
                if((a[distance(s.begin(), it)]))
                {
                    s.erase(it);
                    --it;
                }
            }
        }
        string t = "";
        for(auto it = s.begin(); it != s.end();++it)
        {
            if(!(a[distance(s.begin(), it)]))
            {
                t.push_back(*it);
            }
        }
        return t;
    }
};
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    cin.tie(0);
    Solution s;
    cout<<s.makeGood("abBAcC");
}