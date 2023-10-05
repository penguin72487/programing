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
        if(ts<0)
        {
            cout << 0 << "\n";
            continue;
        }

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
        cout << min(ans, ts/(tr+tp)+1) << "\n";
    }
    return 0;
}
/*
1
4 1 3 0
10 10 10 10
*/