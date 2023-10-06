#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> h(n);
        for (auto &it:a)
            cin >> it;
        for (auto &it:h)
            cin >> it;
        long long ans = 0;
        if(n==1)
        {
            cout << 0 << "\n";
            continue;
        }
        int i_Op = 0;

        //int i_Ed=0;
        long long c_F = 0;
        if(h[0]%h[1]==0)
        {
            c_F = a[0];
        }
        for (int i = 1;i<n;++i)
        {
            if(h[i-1]%h[i]==0)
            {
                c_F+=a[i];
                while(c_F>k)
                {
                    c_F-=a[i_Op];
                    ++i_Op;
                }
                ans = max(ans, (long long)(i - i_Op + 1));
            }
            else{
                c_F = 0;
                i_Op = i+1;
                if(i+1<n&&h[i]%h[i+1]==0)
                {
                    c_F = a[i];
                    i_Op = i;
                }

            }
        }
        cout << ans << "\n";
    }
    return 0;
}