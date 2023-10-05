#include<bits/stdc++.h>
using namespace std;
int looping(unordered_map<long long,int> &mp,long long n,int step)
{
    long long ans = 0;
    while(n)
    {
        ans += pow(n%10,2);
        n/=10;
    }
    if(mp[ans])
        return step-mp[ans];
    mp[ans] = step;
    return looping(mp,ans,step+1);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        unordered_map<long long,int> mp;
        cout<<looping(mp,n,1)<<endl;
    }

    return 0;
}