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
        v[a-1].push_back(make_pair(b-1, c));
    }
    vector<long long> dist(n, (1ll << 62));
    vector<long long> disct(n,(1ll << 62));
    vector<int> passed(n, 0);

    priority_queue < tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> pq;
    pq.push({0, 0, 0});
    // int now=0;
    // long long d=0;
    // int dis=0;
    while(!pq.empty())
    {
        auto [d,now,dis] = pq.top();
        pq.pop();
        if(passed[now])
        {
            continue;
        }
        passed[now] = 1;
        dist[now] = min(dist[now], d);

        for(auto& i:v[now])
        {
            if(!passed[i.first])
            {
                pq.push({d + i.second, i.first,dis});
            }
        }
        if(dis == 1)
        {
            disct[now] = d;
            for(auto& i:v[now])
            {
                if(!passed[i.first])
                {
                    pq.push({d + i.second/2, i.first,1});
                }
            }
        }
    }
    cout << disct[n - 1];
    return 0;
}
