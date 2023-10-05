#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        if(n<10)
        {
            cout << n << "\n";
        }
        else{
            n -= 10;
            if(n&1)
            {
                cout << (n % 20) / 2<<"\n";
            }
            else {
                cout << n / 2 << "\n";
            }
        }
    }
    return 0;
}