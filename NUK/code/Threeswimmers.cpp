#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        long long p,a[3];
        cin >> p >> a[0] >> a[1] >> a[2];
        long long i_Min = ((1ull<<63)-1);
        for (int i = 0; i < 3;++i)
        {
            if(p<=a[i])
            {
                i_Min = min(i_Min, a[i] - p);
            }
            else if(p%a[i]==0)
            {
                i_Min = 0;
            }
            else {
                a[i] = a[i] * (p / a[i] + 1);
                i_Min = min(i_Min, a[i] - p);

            }
        }
        cout << i_Min << "\n";
    }
    return 0;
}