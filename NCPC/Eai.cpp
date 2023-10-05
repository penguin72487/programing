#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>& pos, int x, int cur) {
    if (cur == 0) return true;  // 所有的數字都已放置
    if (pos[cur] != -1) return dfs(pos, x, cur - 1);  // 如果當前數字已放置，則繼續下一個

    for (int i = 0; i < 2 * x; ++i) {
        if (i + cur + 1 < 2 * x && pos[0] == -1 && pos[i] == -1 && pos[i + cur + 1] == -1) {
            pos[i] = cur;
            pos[i + cur + 1] = cur;
            if (dfs(pos, x, cur - 1)) return true;
            pos[i] = -1;
            pos[i + cur + 1] = -1;
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        vector<int> pos(2 * x, -1);
        if (dfs(pos, x, x)) {
            for (int i = 0; i < 2 * x; ++i) {
                cout << pos[i] << " ";
            }
            cout << "\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}
