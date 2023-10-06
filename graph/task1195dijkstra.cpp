#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    long long a, b;
    long long c;
    vector<vector<pair<int,long long>>> v(n);
    for(int i=0;i<m; ++i)
    {
        cin >> a >> b >> c;
        v[a-1].push_back({b-1,c});
    }
    vector<vector<long long>> dist(2,vector<long long> (n,(1ll<<60)));
    priority_queue < tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    pq.push({0, 0, 0});
    // int now=0;
    // long long d=0;
    // int dis=0;
    while(!pq.empty())
    {
        auto [d,now,dis] = pq.top();
        pq.pop();
        if (d > dist[dis][now]) continue;
        for (auto& i:v[now]){
            if (dist[dis][i.first] > d + i.second){
                dist[dis][i.first] = d + i.second;
                pq.push({dist[dis][i.first], i.first, dis});
            }
            if (dis == 0){
                if (dist[1][i.first] > d + i.second/2){
                    dist[1][i.first] = d + i.second/2;
                    pq.push({dist[1][i.first], i.first, 1});
                }
            }
        }
    }
    cout << dist[1][n - 1];
    return 0;
}
