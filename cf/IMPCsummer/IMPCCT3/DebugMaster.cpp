#include <iostream>
using namespace std;
int main(){
cin.tie(0)->sync_with_stdio(0);
cout.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string tp;
        cin >> tp;
        if(n<3)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
return 0;
}