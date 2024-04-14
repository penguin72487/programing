#include<bits/stdc++.h>
using namespace std;

int min_Delet(string s) {
    int ans = 0;
    for (size_t i = 0; i < s.length(); ++i) {
        if (i + 2 < s.length() && (s.substr(i, 3) == "pie" || s.substr(i, 3) == "map")) {
            ans++;
            i += 2; // Skip the next 2 characters
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << min_Delet(s) << "\n";
    }
    return 0;
}
