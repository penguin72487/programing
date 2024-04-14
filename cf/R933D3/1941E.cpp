#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        int cost, d;
        cin>>n>>m>>cost>>d;
        vector<vector<int>> river(n, vector<int>(m));
        for(auto &i:river){
            for(auto &j:i){
                cin>>j;
            }
        }
        vector<vector<long long>> dp(n, vector<long long>(m, 1e9));
        for(int i = 0;i<n;i++){
            dp[i][0] = cost;
        }
        for (int i = 0; i < n; i++)
        {            
            multiset<long long> q;
            // q.insert(dp[i][0]);
            auto it=0;
            auto jt=1;
            for (; jt <= d;jt++)
            {
                dp[i][jt] = *q.begin()+river[i][jt]*cost+cost;
                q.insert(dp[i][jt]);
            }
            for (; jt < m;jt++, it++)
            {
                dp[i][jt] = *q.begin()+(river[i][jt])*cost+cost;
                q.insert(dp[i][jt]);
                q.erase(q.find(dp[i][it]));
                
            }
        }
        long long ans = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            ans = min(ans, dp[i][m-1]);
        }
        cout<<ans<<endl;

    }
    return 0;
}
/*

1 
4 4 2 1
0 3 3 0
0 2 1 0
0 1 2 0
0 3 3 0

*/