#include<iostream>
#include<unordered_map>
#include<algorithm>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio (0);
    int n,k;
    cin>>n>>k;
    long long int ans=0;
    int s[n];
    int w[n];
    for(int i=0;i<n;++i)
    {
         cin>>s[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>w[i];
    }
    //int k_Type=w[0];
    int type_Max=s[0];
    for(int i=1;i<n;++i)
    {
        if(w[i-1]==w[i])
        {
            type_Max=max(type_Max,s[i]);
        }
        else
        {
            ans+=type_Max;
            type_Max=s[i];
        }
    }

    cout<<ans+type_Max<<"\n";
}