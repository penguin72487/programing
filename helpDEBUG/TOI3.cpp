#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n,q,l,r;
    cin>>n;
    int prefix[n+1];
    memset(prefix,0,sizeof(prefix));
    unordered_map<int,int> Map;
    for(int i=1,val;i<=n;i++)
    {
        cin>>val;
        if(!Map[val]) prefix[i] = prefix[i-1] + 1;
        else prefix[i] = prefix[i-1];
        Map[val]++;
    }

    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<prefix[r]-prefix[l-1]<<"\n";
    } 
 return 0;
}