#include<bits/stdc++.h>
using namespace std;
bool segment(int target,vector<int> v)
{
    int n=v.size();
    if(accumulate(v.begin(),v.end(),0)==target)
    {
        return true;
    }
    if(n==0)
    {
        return false;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum==target)
        {
            sum=0;
            v.erase(v.begin(),v.begin()+i+1);
            return segment(target,v);
        }
        else if(sum>target)
        {
            return false;
        }
    }
    return false;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<int> v(n,0);
    for(int i=0;i<n;i++)
    {
        v[i]=s[i]-'0';
    }
    long long target=0;
    for(int i=0;i<n;i++)
    {
        target+=v[i];
        if(segment(target,vector<int>(v.begin()+i+1,v.end())))
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}