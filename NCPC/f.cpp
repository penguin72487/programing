#include<bits/stdc++.h>
using namespace std;
unordered_map<string, int> dp;
int lass(string& s,int count)
{
    dp[s] = count;
    vector<int> c_Num(10,0);
    for(auto i:s)
    {
        c_Num[i-'0']++;
    }
    string ans;
    for (int i = 0; i < 10;++i)
    {
        if(c_Num[i]>0)
        {
            ans+=to_string(c_Num[i]);
            ans.push_back(i + '0');
        }
    }
    if(dp.find(ans)!=dp.end())
        return dp[ans];
    else
    {
        return lass(ans, count + 1);
    }
        
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<lass(s,1)<<"\n";
        dp.clear();
    }
    return 0;
}