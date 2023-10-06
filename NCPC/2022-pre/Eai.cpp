#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<int>& ans, int n) {
    if (n == 0) return true;
    for (int i = 0; i < ans.size() - n - 1; i++) {
        if (ans[i] == 0 && ans[i + n + 1] == 0) {
            ans[i] = n;
            ans[i + n + 1] = n;
            if (dfs(ans, n - 1)) return true;
            ans[i] = 0;
            ans[i + n + 1] = 0;
        }
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {

        int n;
        cin >> n;
        // if(n%4==1||n%4==2)
        // {
        //     cout << "0\n";
        //     continue;
        // }
        vector<int> ans(2 * n, 0);
        if (dfs(ans, n)) {
            reverse(ans.begin(), ans.end());
            for (int j : ans) cout << j << " ";
            cout << "\n";
        } else {
            cout << "0\n";
        }
    }
    return 0;
}
