#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long a, b;
        cin >> a >> b;
        if(b<=3)
        {
            cout << -1 << "\n";
            continue;
        }
        if(a==b&&(a&1))
        {
            for (int i = 3;i*i<=a;i+=2)
            {
                if(a%i==0)
                {
                    cout << (i-1)*a/i << " " << a/i << "\n";
                    goto next;
                }
            }
            cout << -1 << "\n";
            next:;
        }
        else{
            cout << b/2<<" "<<b/2<< "\n";
        }
    }
    return 0;
}