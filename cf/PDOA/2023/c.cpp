#include<bits/stdc++.h>
using namespace std;
long long max_Subarray(vector<long long>& vec)
{
    long long ans = vec[0];
    long long sum = 0;
    for(auto& x:vec)
    {
        sum+=x;
        ans = max(ans,sum);
        if(sum<0)
        {
            sum = 0;
        }
    }
    return ans;
}
bool isSubstring(string str, string substr) {
    size_t pos = str.find(substr); // 在母字串中查找子字串
    if (pos == string::npos) { // 如果子字串不是母字串的一部分
        return false;
    } else { // 如果子字串是母字串的一部分
        return true;
    }
}
string int_to_letter(long long x)
{
    string ans;
    if(x==0)
    {
        return "A";
    }   
    while(x)
    {
        ans.push_back((char)(x%10+'A'));
        x/=10;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long n,m;
    cin>>n>>m;
    vector<long long> ans;
    for (long long i = 0;i<n;++i)
    {
        vector<long long> vec(m);
        for (auto& x:vec)
        {
            cin>>x;
        }
        vector<long long> tmp(vec);
        int ert=0;
        for (long long j = 0;j<m;++j)
        {
            if(tmp[j]>0)
            {
                tmp.push_back(tmp[j]);
            }
            else{
                ert = j;
                break;
            }
        }
        if(ert==0)
        {
            ans.push_back(max_Subarray(vec));
            if(ans.back()<0)
            {
                ans.back()=-ans.back();
            }
            continue;
        }
        for(int j = 0;j<ert;++j)
        {
            tmp.erase(tmp.begin());
        }
        ans.push_back(max_Subarray(tmp));
        if(ans.back()<0)
        {
            ans.back()=-ans.back();
        }
    }
    string s;
    cin>>s;
    // for(auto& x:ans)
    // {
    //     cout<<int_to_letter(x);
    // }
    // cout<<"\n";
    string check;
    for (auto& x:ans)
    {
        check+=int_to_letter(x);
        //cout<<int_to_letter(x);
    }
    //cout<<"\n";
    if(isSubstring(s,check))
    {
        for(auto& x:ans)
        {
            cout << x;
        }
        cout<<"\n";
    }
    else 
    {
        cout<<"-1\n";
    }
    


    return 0;
}