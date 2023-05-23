#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, d;
        cin >> n >> k >> d;
        int a[n];
        int v[k + 1];
        for(int i=0; i<n; i++)
        {
            cin >> a[i];
            v[a[i]] = 0;
        }
        long long ans = 0;
        for(int i=0; i<d; i++)
        {
            if(v[a[i]]==0)
            {
                ans++;
            }
            v[a[i]]++;
        }
        long long min_Ans = ans;
        for(int i=d; i<n; i++)
        {
            if(v[a[i-d]]==1)
            {
                ans--;
            }
            v[a[i-d]]--;

            if(v[a[i]]==0)
            {
                ans++;
            }
            v[a[i]]++;
            min_Ans = min(min_Ans, ans);
        }
        cout << min_Ans << "\n";
        // delete[] a;
        // delete[] v;
    }
    return 0;
}