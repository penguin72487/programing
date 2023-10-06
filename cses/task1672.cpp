#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int,unordered_map<int,long long>> map_Neighbors;
priority_queue<pair<long long , int>,vector<pair<long long,int>>,greater<pair<long long,int>>> list;
vector<vector<long long>> dist_from_Begin;
void Dijkstra(int i_Op)
{
    int n=dist_from_Begin.size();
    dist_from_Begin[i_Op][i_Op] = 0;
    bool visit[n];
    fill(visit, visit + n, 0);

    list.push(make_pair(0,i_Op));
    while(!list.empty())
    {
        long long node_Dist=list.top().first;
        int i_Node =  list.top().second;
        list.pop();


        if(visit[i_Node])
        {
            continue;
        }
        visit[i_Node] = 1;
        for (auto it = map_Neighbors[i_Node].begin(); it != map_Neighbors[i_Node].end();++it)
        {
            if(node_Dist+it->second<=dist_from_Begin[i_Op][it->first])
            {
                dist_from_Begin[i_Op][it->first] = node_Dist + it->second;
                //dist_from_Begin[it->first][i_Op] = min(node_Dist + it->second,dist_from_Begin[it->first][i_Op]);
                list.push(make_pair(dist_from_Begin[i_Op][it->first], it->first));
            }
            //dist_from_Begin[it->first] = max(dist_from_Begin[i_Node]+it->second,dist_from_Begin[it->first]);
        }

    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,m,q;
    cin >> n>>m >> q;
    ++n;
    dist_from_Begin.resize(n);
    for(auto it=dist_from_Begin.begin(); it!=dist_from_Begin.end();++it)
    {
        it->resize(n);
        fill(it->begin(), it->end(), ((1ull << 63) - 1ull));
    }
    while(m--)
    {
        int a, b;
        long long u;
        cin >> a >> b >> u;
        if(map_Neighbors[a].find(b) == map_Neighbors[a].end())
        {
            map_Neighbors[a][b] = u;
            //dist_from_Begin[a][b] = u;
        }
        else
        {
            map_Neighbors[a][b] = min(u, map_Neighbors[a][b]);
            //dist_from_Begin[a][b] = min(u, map_Neighbors[a][b]);
        }
        if(map_Neighbors[b].find(a) == map_Neighbors[b].end())
        {
            map_Neighbors[b][a] = u;
            //dist_from_Begin[b][a] = u;
        }
        else
        {
            map_Neighbors[b][a] = min(u, map_Neighbors[b][a]);
            //dist_from_Begin[b][a]=min(u, map_Neighbors[b][a]);
        }
        
    }
    
    for (int i = 1;i<n; ++i)
    {
        Dijkstra(i);
    }
        // prior node

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        if (dist_from_Begin[a][b] == ((1ull << 63) - 1ull))
        {
            cout << "-1\n";
        }
        else
        {
            cout << dist_from_Begin[a][b] << "\n";
        }

    }
}
