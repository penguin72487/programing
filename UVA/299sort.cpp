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
        int a[n];
        long long ans = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n;++i)
        {
            for(int j = 1; j < n-i;++j)
            {
                if(a[j-1]>a[j]){
                    swap(a[j-1],a[j]);
                    ++ans;
                }
            }
        }
        cout << "Optimal train swapping takes " << ans << " swaps.\n";
    }
    return 0;
}