#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        if(n==m&&m==3)
        {
            cout << "2 2\n";
        }
        else if(n<2||m<2)
        {
            cout << "1 1\n";
        }
        else if(n==3)
        {
            if(m<3)
            {
                cout << "2 2\n";
            }
            else {
                cout << "1 1\n";
            }
        }
        else if(m==3)
        {
            if(n<3)
            {
                cout << "2 2\n";
            }
            else {
                cout << "1 1\n";
            }
        }
        else 
        {
            cout << "1 1\n";
        }

    }
    return 0;
}