#include<iostream>
#include<sstream>
#include<deque>
using namespace std;
int main()
{
    const int mod = 100000;
    cin.tie(0)->sync_with_stdio(0);
    int ans = 0;
    string s;
    string ss;
    cin >> s;
    s.push_back('+');
    deque<int> stl;
    for (auto it = s.begin(); it != s.end();++it)
    {
        if(*it>'+')
        {
            ss.push_back(*it);
        }
        else 
        {
            int tmp;
            tmp=stoi(ss);
            ss.clear();
            tmp = (tmp+mod)%mod;
            stl.push_back(tmp);
            if(*it=='+')
            {
                tmp = stl.back();
                stl.pop_back();
                while(!stl.empty())
                {
                    tmp = (tmp*stl.back()+mod)%mod;
                    stl.pop_back();
                }
                ans = (ans+tmp+mod)%mod;
            }
        }
    }
    cout << (ans+mod)%mod << "\n";
}