#include <iostream>
#include <algorithm>
using namespace std;

inline void readCase(int arrows[], int n) {
    for (int i=0; i<n; i++) {
        cin >> arrows[i];
    }
}
inline void toggleArrow(int pos, string arrows, int n) {
    if (pos == 0) {
        arrows[0] = arrows[0] ? 0 : 1;
        arrows[1] = arrows[1] ? 0 : 1;
    } else if (pos == n-1) {
        arrows[pos-1] = arrows[pos-1] ? 0 : 1;
        arrows[pos] = arrows[pos] ? 0 : 1;
    } else if (pos < n-1) {
        arrows[pos-1] = arrows[pos-1] ? 0 : 1;
        arrows[pos] = arrows[pos] ? 0 : 1;
        arrows[pos+1] = arrows[pos+1] ? 0 : 1;
    }
}
inline void printArrows(int arrows[], int n) {
    for (int i=0; i<n; i++) {
        cout << arrows[i] << " ";
    }
    cout << endl;
}


int main() {
    static_cast<void>(cin.sync_with_stdio(0)), cout.tie(0);
    int n;
    cin >> n;
    string arrows;
    cin >> arrows;

    if (n == 2) {
        cout << "No" << endl;
        return 0;
    } else if (n==1) {
        cout << "Yes" << endl;
        return 0;
    }
    while (count(arrows.begin(), arrows.end(), 1)) {
        cout << "new loop" << endl;
        for (int i=0; i<n; i++) {
            if (arrows[i]) {
                if (i+1 < n) {
                    toggleArrow(i+1, arrows, n);
                } else {
                    toggleArrow(i, arrows, n);
                    toggleArrow(0, arrows, n);
                }
                cout << arrows << "\n";
            }
        }
    }
    
    return 0;
}