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
            if(n==2)
            {
                if(tp[0]==tp[1])
                {
                    cout << "NO\n";
                    continue;
                }
            }
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
return 0;
}