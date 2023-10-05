#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n-1;++i)
    {
        cin>>a[i];
    }
    long long ans=a[0]+a[n-2];
     for(int i=1;i<n-1;++i)
    {
        ans+=min(a[i],a[i-1]);
    }
    cout<<ans<<"\n";
}
