#include <iostream>
#include <queue>
#include <vector>
#include<iterator>
#include <unordered_map>
using namespace std;
unordered_map<int,unordered_map<int,long long>> map_Neighbors;
priority_queue<pair<long long , int>,vector<pair<long long,int>>,greater<pair<long long,int>>> list;
void Dijkstra(int op,vector<long long> &dist_from_Begin)
{
    int n=dist_from_Begin.size();
// prior node
    dist_from_Begin[op] = 0;
    bool visit[n];
    fill(visit, visit + n, 0);
    list.push(make_pair(0,op));
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

}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,q,k;
    cin >> n >> q >> k;

    while(q--)
    {
        int a, b;
        long long u;
        cin >> a >> b >> u;
        if(map_Neighbors[a].find(b) == map_Neighbors[a].end())
        {
            map_Neighbors[a][b] = u;
        }
        else
        {
            map_Neighbors[a][b] = min(u, map_Neighbors[a][b]);
        }
        if(map_Neighbors[b].find(a)== map_Neighbors[b].end())
        {
            map_Neighbors[b][a] = u;
        }
        else
        {
            map_Neighbors[b][a] = min(u, map_Neighbors[b][a]);
        }
        
    }
    ++n;
    vector<long long> dist_from_Begin(n);
    fill(dist_from_Begin.begin(),dist_from_Begin.end(),((1ull << 63) - 1ull));

    int storage[k];
    for(int i =0;i<k;++i)
    {
        cin>>storage[i];
        dist_from_Begin[storage[i]]=0;
    }
    for(int i =0;i<k;++i)
    {
        Dijkstra(storage[i], dist_from_Begin);
    }
    long long min_direct=((1ull << 63) - 1ull);
    for (int i = 0; i < n;++i)
    {
        if(dist_from_Begin[i]!=0)
        {
            min_direct=min(min_direct,dist_from_Begin[i]);
        }
    }
    if(min_direct==((1ull << 63) - 1ull))
    {
        cout << "-1";
        return 0;
    }
    cout<<min_direct<<"\n";
    return 0;
}
