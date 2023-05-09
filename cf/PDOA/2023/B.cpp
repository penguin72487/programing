#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long n, t;
    cin >> n >> t;
    vector<vector<tuple<long long,long long>>> vec(n);//time satis
    for(long long i=1;i<n;++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        vec[c].push_back({a,b});
    }
    vector<long long> dp(t+1);
    for(long long i=0;i<n;++i)
    {
        for(long long j=t;j>=0;--j)
        {
            for(auto& [a,b]:vec[i])
            {
                if(j-a>=0)
                {
                    dp[j] = max(dp[j],dp[j-a]+b);
                }
            }
        }
    }
    cout << dp[t] << "\n";

    return 0;
}
/*
5 11
2 10 0
8 20 0
9 21 1
6 14 1

5 15
2 10 0
8 20 0
9 21 1
6 14 1


5 100
2 10 0
8 20 0
9 21 1
6 14 1
*/