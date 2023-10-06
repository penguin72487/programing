#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int l, r, d, u;
        cin>>l>>r>>d>>u;
        int x, y, x1, y1, x2, y2;
        cin>>x>>y>>x1>>y1>>x2>>y2;
        if((x1==x2&&l+r>0)||(y1==y2&&d+u>0))
        {
            cout<<"NO"<<"\n";
            continue;
        }
        else if(x+r-l>=x1&&x+r-l<=x2&&y+u-d>=y1&&y+u-d<=y2)
            cout<<"YES"<<"\n";
        else
            cout<<"NO"<<"\n";
    }
    return 0;
}