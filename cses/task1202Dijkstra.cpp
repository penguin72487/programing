#include <iostream>
#include <queue>
#include <vector>
#include<iterator>
#include <set>
#include <unordered_map>
using namespace std;
 
priority_queue<pair<long long , int>,vector<pair<long long,int>>,greater<pair<long long,int>>> list;

void Dijkstra(int i_Op, vector<long long> &dist_from_Begin, vector<set<long long>> &route_From_Whome, unordered_map < int, unordered_map<int, vector<long long>>> &map_Neighbors);
int requested[3] = {0,2147483647,0};
int &count_Route = requested[0];
int &min_CountRoutes = requested[1];
int &max_CountRoutes = requested[2];
void path_DFS(int i_Now, int dfs_Count_Routes, unordered_map < int, unordered_map<int, vector<long long>>> &map_Neighbors, vector<set<long long>> &route_From_Whome);
const long long MOD = 1E9 + 7;
vector<long long> dp_Path;
vector<long long> dp_MinRoute;
vector<long long> dp_MaxRoute;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    unordered_map < int, unordered_map<int, vector<long long>>> map_Neighbors;
    
    while(q--)
    {
        int a, b;
        long long u;
        cin >> a >> b >> u;
        map_Neighbors[a][b].push_back(u);
        
        
    }
    ++n;
    dp_Path.resize(n);
    dp_MinRoute.resize(n);
    dp_MaxRoute.resize(n); 
    
    fill(dp_Path.begin(), dp_Path.end(), 0ll);
    fill(dp_MinRoute.begin(), dp_MinRoute.end(), ((1ull << 63) - 1ull));
    fill(dp_MaxRoute.begin(), dp_MaxRoute.end(),0);

    vector<long long> dist_from_Begin(n);
    vector<set<long long> > route_From_Whome(n);
    fill(dist_from_Begin.begin(),dist_from_Begin.end(), ((1ull << 63) - 1ull));
    Dijkstra(1, dist_from_Begin, route_From_Whome, map_Neighbors);

    cout << dist_from_Begin[n - 1] << " ";

    count_Route = path_DFS(n - 1, 0, map_Neighbors, route_From_Whome);

    for (int i = 0; i < 3; ++i)
    {
        cout << requested[i] << " ";
    }

    cout << "\n";
    return 0;
}


void Dijkstra(int i_Op,vector<long long> &dist_from_Begin,vector<set<long long> >& route_From_Whome,unordered_map < int, unordered_map<int, vector<long long>>> &map_Neighbors)
{
    int n=dist_from_Begin.size();
    dist_from_Begin[i_Op] = 0;
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
            for(auto jt= it->second.begin(); jt != it->second.end();++jt)
            {
                if( node_Dist+*jt<dist_from_Begin[it->first])
                {
                    dist_from_Begin[it->first] = node_Dist + *jt;
                    route_From_Whome[it->first].clear();
                    route_From_Whome[it->first].insert(i_Node);
                    list.push(make_pair(dist_from_Begin[it->first], it->first));
                }
                else if(node_Dist+*jt==dist_from_Begin[it->first])
                {
                    //dist_from_Begin[it->first] = node_Dist + *jt;
                    route_From_Whome[it->first].insert(i_Node);
                    list.push(make_pair(dist_from_Begin[it->first], it->first));
                }
            }
            
            //dist_from_Begin[it->first] = max(dist_from_Begin[i_Node]+it->second,dist_from_Begin[it->first]);
        }
 
    }
}
void  path_DFS(int i_Now,int dfs_Count_Routes,unordered_map < int, unordered_map<int, vector<long long>>> &map_Neighbors,vector<set<long long> >& route_From_Whome)
{
    if(route_From_Whome[i_Now].empty())
    {
        min_CountRoutes = min(dfs_Count_Routes, min_CountRoutes);
        max_CountRoutes = max(dfs_Count_Routes,max_CountRoutes);
        dp_Path[i_Now] = 1;
        return;
    }
    else
    {
        long long res = 0;
        for(auto it=route_From_Whome[i_Now].begin();it!=route_From_Whome[i_Now].end();++it)
        {
            if(dp_Path[*it])
            {
                res+=dp_Path[*it];
            }
            else
            {
                path_DFS(*it, dfs_Count_Routes+1, map_Neighbors, route_From_Whome);
                res+=dp_Path[*it];
            }
            
        }
        dp_Path[i_Now] = res % MOD;
    }

}