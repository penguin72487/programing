#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int LIS(string &s);
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    string s;
    cin >> s;
    cout << LIS(s)<<"\n";
}
int LIS(string &s)
{
    //int ans=0;
    int n = s.size();
    vector<int> v;
    v.push_back(s[1]);
    for (int i = 1; i < n;++i)
    {
        if(s[i]>=v.back())
        {
            v.push_back(s[i]);
        }
        else
        {
            auto it = upper_bound(v.begin(),v.end(),s[i]);
            *it = s[i];
        }
    }
        return v.size();
}