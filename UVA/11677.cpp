#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int h1, m1, h2, m2;
    while(cin>>h1>>m1>>h2>>m2)
    {
        if(h1==h2&&m1==m2&&h2==m2&&h1==0)
        {
            break;
        }
        h2 += 24;
        int d1 = (h1 * 60 + m1);
        int d2 = (h2 * 60 + m2);
        cout << (d2-d1)%1440 << "\n";
    }

    return 0;
}