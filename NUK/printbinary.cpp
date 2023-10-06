#include<iostream>
#include<math.h>
using namespace std;
int main(){
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);
    int n;
    while(cin >> n)
    {
        if(n == 0)
        {
            cout << "0\n";
            continue;
        }
        int h = log2(n);
        for (int i = h; i > -1;--i)
        {
            cout << (bool(n & (1 << i)));
        }
        cout<<"\n";
    }
    
    return 0;
}