#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    double s,a;
    string str;
    while(cin>>s>>a>>str)
    {
        if(str=="min")
        {
            a/=60;
        }
        if(a>180)
        {
            a=360-a;
        }
        double ans = 2*s*acos(-1)*a/360;
        cout<<fixed<<setprecision(6)<<ans<<" "<<2*s*sin(a*acos(-1)/180)<<"\n";
    }
    return 0;
}