#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto& it:a)
        {
            cin >> it;
        }
        sort(a.begin(), a.end());
        int k = a.size() >> 1;
        int sum = 0;
        for(int i = 0; i < n; ++i){
            sum += abs(a[i] - a[k]);
        }
        cout << sum << "\n";
    }

    return 0;
}