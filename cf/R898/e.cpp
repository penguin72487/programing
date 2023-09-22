#include<bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> v(n);
        partial_sum(a.begin(), a.end(),v.begin());
        if(a[n-1]*n-v[n-1]<=x)
        {
            cout<<a[n-1]+(x-a[n-1]*n+v[n-1])/n<<"\n";
        }
        else
        {
            int i_Op = 0;
            int i_Ed = a[n-1];
            while(i_Op<i_Ed)
            {
                int i_Mid = (i_Op + i_Ed) >> 1;
                int t = a[i_Mid]*n-(a[i_Mid] * (n - i_Mid-1) + v[i_Mid]);
                if(t<x)
                {
                    i_Op = i_Mid;
                }
                else
                {
                    i_Ed = i_Mid-1;
                }
            }
            cout<<a[i_Op-1]<<"\n";
        }



    }
    return 0;
}
