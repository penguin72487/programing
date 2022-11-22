#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include <tuple>

using namespace std;
void DFS(int op,vector<bool> &path,vector<vector<int>> &adj_List){
    path[op] = 1;
    for(auto it:adj_List[op])
    {
        if(!path[it])
        {
            DFS(it, path, adj_List);
        }
    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
     // adj list
    long long tt = (~(1ll << 42) + 1);
    vector<long long> dist(n,tt);
    vector<tuple<int, int, long long>> tunnel(m);
    vector<vector<int>> adj_List(n);//adj list
    vector<vector<int>> bdj_list(n);//adj list
    vector<bool> path(m,0);
    vector<bool> repath(m,0);
    bool flag = false;
    for(int i=0,a,b,c; i<m; ++i)
    {
        cin >> a >> b>>c;
        // --a;
        // --b;
        adj_List[a-1].push_back(b-1);
        bdj_list[b-1].push_back(a-1);
        tunnel.push_back(make_tuple(a-1,b-1,c));
    }
    DFS(0,path,adj_List);
    DFS(n - 1, repath,bdj_list);

    dist[0] = 0;
    for (int i = 0; i < n;++i)
    {   flag = 0;
        for(auto it=tunnel.begin(); it!=tunnel.end();++it)
        {
            auto [v, u, d] = *it;
            if(path[v]&&repath[u]&&dist[v]+d>dist[u])
            {
                flag = 1;
                dist[u] = dist[v] + d;
            }
        }
    }
        // cout << bellman_Ford()<<"\n";
    if (flag)
    {
        cout << "-1\n";
    }
    else
    {
        cout << dist[n - 1]<<"\n";
    }
    return 0;
}