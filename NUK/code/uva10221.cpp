#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    double s,a;
    string str;
    double pi=acos(-1);
    double r=6440;
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
        cout<<fixed<<setprecision(6)<<2*pi*(r+s)*a/360<<" "<<2*(r+s)*sin(a/2/180*pi)<<"\n";
    }
    return 0;
}