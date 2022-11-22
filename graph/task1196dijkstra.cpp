#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m, k;
    cin>>n>>m >> k;
    long long a, b;
    long long c;
    vector<vector<pair<int,long long>>> v(n);
    for(int i=0;i<m; ++i)
    {
        cin >> a >> b >> c;
        v[a-1].push_back(make_pair(b-1, c));
    }
    vector<priority_queue<long long,vector<long long>,greater<long long>>> vpq(n);
    //vector<int> passed(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    //vpq[0].push(0);
    while(!pq.empty())
    {
        auto now = pq.top();
        pq.pop();
        if(vpq[now.second].size()>=k)
        {
            continue;
        }
        vpq[now.second].push(now.first);
        for(auto& i:v[now.second])
        {
            pq.push({now.first + i.second, i.first});
        }
    }
    while(!vpq[n-1].empty())
    {
        cout << vpq[n - 1].top() << " ";
        vpq[n-1].pop();
    }
    cout<< "\n";
    return 0;
}
