#include <iostream>
#include<algorithm>
using namespace std;

inline void readCase(int arrows[], int n) {
    for (int i=0; i<n; i++) {
        cin >> arrows[i];
    }
}


int main() {
    static_cast<void>(cin.sync_with_stdio(0)), cout.tie(0);
    int n;
    cin >> n;
    int arrows[n];
    readCase(arrows, n);
    
    cout << (count(arrows, arrows+n, 1)%2 ? "No" : "Yes") << endl;
    
    return 0;
}