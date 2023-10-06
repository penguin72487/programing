#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int x, y;
        int a, b;
        cin >> x >> y >> a >> b;
        if(x>y)
        {
            swap(x, y);
        }
        cout << min((x+y)*a,(y-x)*a+x*b) << "\n";
        
    }
    return 0;
}