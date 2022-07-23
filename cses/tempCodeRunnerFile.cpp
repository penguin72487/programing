#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;
int main(){
    int n,q;
    cin >> n >> q;
    map<int,map<int,int>> map_Neighbors;
    while(q--)
    {
        int a, b, u;
        cin >> a >> b >> u;
        if(map_Neighbors[a].find(b) == map_Neighbors[a].end())
        {
            map_Neighbors[a][b] = u;
        }
        else
        {
            map_Neighbors[a][b] = min(u, map_Neighbors[a][b]);
        }
        
    }
    ++n;
    priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int,int>>> list;// prior node
    long long dist_from_Begin[n];
    fill(dist_from_Begin, dist_from_Begin + n + 1, ((1ull << 63) - 1ull));
    dist_from_Begin[1] = 0;
    bool visit[n];
    fill(visit, visit + n, 0);

    list.push(make_pair(0,1));
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
            if(node_Dist+it->second<dist_from_Begin[it->first])
            {
                dist_from_Begin[it->first] = node_Dist + it->second;
                list.push(make_pair(dist_from_Begin[it->first], it->first));
            }
            //dist_from_Begin[it->first] = max(dist_from_Begin[i_Node]+it->second,dist_from_Begin[it->first]);
        }

    }
    for(int i = 1; i <n; ++i)
    {
        cout << dist_from_Begin[i]<<" ";
    }
}
