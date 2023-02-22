#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int a, b, c, d;
    char t;
    cin >> a >> t >> b;
    cin >> c >> t >> d;
    int tt= (a*60+b+c*60+d)/2;
    cout<<setw(2)<<setfill('0')<< tt / 60 << ":" <<setw(2)<<setfill('0')<< tt % 60 << "\n";

    return 0;
}