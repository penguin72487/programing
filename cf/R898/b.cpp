#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (auto &it:v)
            cin >> it;
        (*min_element(v.begin(), v.end()))++;
        long long ans = 1;
        for (auto &it:v)
            ans *= it;
        cout << ans << "\n";

    }
    return 0;
}