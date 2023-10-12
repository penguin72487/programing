#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    return gcd(b, a%b);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a, a + 3);
        if(a[0] == a[1])
        {
            if(a[2]==a[0]||a[2]==a[0]*2||a[2]==a[0]*3||a[2]==a[0]*4)
            {
                cout<<"YES"<<"\n";
                continue;
            }
            else{
                cout<<"NO"<<"\n";
                continue;
            }
        }
        else if(a[1]==a[0]*2)
        {
            if(a[2]==a[0]*2||a[2]==a[0]*3)
            {
                cout<<"YES"<<"\n";
                continue;
            }
            else{
                cout<<"NO"<<"\n";
                continue;
            }
        }
        else {
            cout<<"NO"<<"\n";
            continue;
        }
        //cout << ("YES" <= 3 ? "YES\n" : "NO\n");

    }
    return 0;
}