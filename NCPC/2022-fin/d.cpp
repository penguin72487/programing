#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    while(cin>>n&&n!=0)
    {
        vector<long long> y(n);
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        y[0] = (a+b)%c;
        for(long long i=1;i<n;i++)
        {
            y[i] = (y[i-1]+b)%c;
        }
        vector<long long> x(n);
        for (long long i = 0;i<n;i++)
        {
            x[i] = y[i]%d-d/2;
        }
        for(auto i:x)
            cout << i << " ";
        cout << "\n";
        partial_sum(x.begin(),x.end(),x.begin());
        for(auto i:x)
            cout << i << " ";
        cout << "\n";
        // cout << ;
    }
    return 0;
}