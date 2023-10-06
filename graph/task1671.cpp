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
    vector<long long> dist(n,(1ll<<60));
    dist[0] = 0;
    priority_queue < tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    pq.push({0, 0, 0});
    while(!pq.empty())
    {
        auto [d,now,dis] = pq.top();
        pq.pop();
        if (d > dist[now]) continue;
        for (auto& i:v[now]){
            if (dist[i.first] > d + i.second)
            {
                dist[i.first] = d + i.second;
                pq.push({dist[i.first], i.first, dis});
            }
        }
    }
    for(auto& i:dist)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}