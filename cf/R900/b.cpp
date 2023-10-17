#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n;++i)
        {
            a[i] = 3*i + 1;
        }
        // for (int i = 2;i<n;++i)
        // {
        //     if(3*a[i]%(a[i-1]+a[i-2])==0)
        //     {
        //         cout << "NO\n";
        //         goto end;
        //     }
        // }
        // cout << "YES\n";
        // end:;
        for(auto it:a) cout << it << " ";
        
        cout << "\n";
    }
    return 0;
}