#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    long long MAX = 1000000000000000000;
    while(t--)
    {
        long long n, tr, tp, ts;
        cin >> n >> tr >> tp >> ts;
        ts-=tp;
        vector<long long> a(n, 0);
        for (int i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        long long ans = 1;
        for (int i = 0; i < n;i++)
        {
            if(a[i]<(MAX/ans))
            {
                ans*=a[i];
            }
            else
            {
                ans = MAX;
                break;
            }
        }
        long double ld=  (long double)(ts) / ( (long double)(tr) +  (long double)(tp));
        cout << min(ans, (long long)(ld)+1) << "\n";
    }
    return 0;
}