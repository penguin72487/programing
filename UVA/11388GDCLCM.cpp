#include <iostream>
using namespace std;
int main() {
    int T, G, L;
    cin >> T;
    while (T--){
        cin >> G >> L;
        if (L % G != 0){
            cout << "-1\n";
            continue;
        }
        cout << G << ' ' << L << '\n';
    }
    return 0;
}