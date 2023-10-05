#include <iostream>
#include <queue>
#include <vector>
#include<iterator>
#include <set>
#include <unordered_map>
#include <fstream>
using namespace std;
// #define file fstream f("task1202Test7.txt");cout.tie(0)->sync_with_stdio(0);
// #define cin f
// #define return f.close();return 
priority_queue<pair<long long , int>,vector<pair<long long,int>>,greater<pair<long long,int>>> list;

void Dijkstra(int i_Op, vector<long long> &dist_from_Begin, vector<set<long long>> &route_From_Whome, unordered_map < int, unordered_map<int, vector<long long>>> &map_Neighbors);
void path_DFS(int i_Now, unordered_map < int, unordered_map<int, vector<long long>>> &map_Neighbors, vector<set<long long>> &route_From_Whome);
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
    dp_MinRoute[1] = 0;
    dp_MaxRoute[1] = 0;
    dp_Path[1] = 1;

    vector<long long> dist_from_Begin(n);
    vector<set<long long> > route_From_Whome(n);
    fill(dist_from_Begin.begin(),dist_from_Begin.end(), ((1ull << 63) - 1ull));
    Dijkstra(1, dist_from_Begin, route_From_Whome, map_Neighbors);

    cout << dist_from_Begin[n - 1] << " ";

    path_DFS(n - 1, map_Neighbors, route_From_Whome);
    cout << dp_Path[n - 1]<<" "<<dp_MinRoute[n-1]<<" "<<dp_MaxRoute[n-1]<<"\n";

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
                    dp_Path[it->first] =dp_Path[i_Node];
                    dp_Path[it->first] %= MOD;
                }
                else if(node_Dist+*jt==dist_from_Begin[it->first])
                {
                    //dist_from_Begin[it->first] = node_Dist + *jt;
                    route_From_Whome[it->first].insert(i_Node);
                    list.push(make_pair(dist_from_Begin[it->first], it->first));
                    dp_Path[it->first] +=dp_Path[i_Node];
                    dp_Path[it->first] %= MOD;

                }
            }
            
            //dist_from_Begin[it->first] = max(dist_from_Begin[i_Node]+it->second,dist_from_Begin[it->first]);
        }
 
    }
}
void  path_DFS(int i_Now,unordered_map < int, unordered_map<int, vector<long long>>> &map_Neighbors,vector<set<long long> >& route_From_Whome)
{
    if(route_From_Whome[i_Now].empty())
    {
        // dp_MinRoute[i_Now] = min(dfs_Count_Routes, dp_MinRoute[i_Now]);
        // dp_MaxRoute[i_Now] = max(dfs_Count_Routes, dp_MaxRoute[i_Now]);
        dp_MinRoute[i_Now] = 0;
        dp_MaxRoute[i_Now] = 0;
        //dp_Path[i_Now] = 1;
        
    }
    else
    {
        
        for(auto it=route_From_Whome[i_Now].begin();it!=route_From_Whome[i_Now].end();++it)
        {
            if(dp_MaxRoute[*it])
            {
                //dp_Path[i_Now]+=dp_Path[*it];
                dp_MaxRoute[i_Now]=max(dp_MaxRoute[*it]+1,dp_MaxRoute[i_Now]);
                dp_MinRoute[i_Now]=min(dp_MinRoute[*it]+1,dp_MinRoute[i_Now]);
            }
            else
            {
                path_DFS(*it, map_Neighbors, route_From_Whome);
                //dp_Path[i_Now]+=dp_Path[*it];
                dp_MaxRoute[i_Now]=max(dp_MaxRoute[*it]+1,dp_MaxRoute[i_Now]);
                dp_MinRoute[i_Now]=min(dp_MinRoute[*it]+1,dp_MinRoute[i_Now]);
            }
            
        }
        dp_Path[i_Now] %= MOD;
    }

}