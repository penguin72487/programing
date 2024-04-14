#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> a(n);
        for (int i = 0; i < n;++i)
        {
            a[i] = s[i] - '0';
        }
        int accepted = count_if(a.begin(), a.end(), [&](int x) { return x == 1; });
        // int rejected = n - accepted;
        int acc_Low = (n+1) / 2;
        int ans = 0;
        float pos = FLT_MAX;
        if(accepted>=acc_Low)
        {
            pos = abs(n/2.0-1.0);
        }
        for (int i = 0; i < n;++i)
        {
            if(a[i]==1)
            {
                accepted--;
                // rejected++;
            }
            else
            {
                accepted++;
                // rejected--;
            }
            if(accepted>=acc_Low && abs(n/2.0-float(i)-1.0)<=pos)
            {
                ans = i+1;
                pos = abs(n/2.0-float(i)-1.0);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}