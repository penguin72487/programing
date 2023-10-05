#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int a[3];
        cin >> a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]+a[1]==a[2])
        {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        
    }
    return 0;
}