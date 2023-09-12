#include<bits/stdc++.h>
using namespace std;
#define e 2.71828182845904523536
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w",stdout);
    int n;
    //int cycle=7;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    //int ans=0;
    for(auto it:a)
    {
        cout<<it<<" ";
    }
    cout<<"\n";


    fclose(stdin);
    fclose(stdout);
    return 0;
}