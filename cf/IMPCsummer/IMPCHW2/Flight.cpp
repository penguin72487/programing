#include <iostream>
#include <queue>
#include <vector>
#include<iterator>
#include <unordered_map>
using namespace std;
class myComparator 
{
public:
  bool operator()(const tuple<long long, int, int>& tuple1,const tuple<long long, int, int>& tuple2)
  {
    // Second element of tuples is equal
    if (get<0>(tuple1) == get<0>(tuple2)) 
    {
      // first element of tuples is equal
      if (get<1>(tuple1) == get<1>(tuple2)) 
      {
        return (get<2>(tuple1) < get<2>(tuple2));
      }
  
      return get<1>(tuple1) < get<1>(tuple2);
    }
  
    return get<0>(tuple1) < get<0>(tuple2);
  }
};

priority_queue<pair<long long , int>,vector<pair<long long,int>>,greater<pair<long long,int>>> list;
//priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> route_Rank;
//priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, less<tuple<long long, int, int>>> route_Rank;
//priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, myComparator > route_Rank;


void Dijkstra(int i_Op,vector<long long> &dist_from_Begin,vector<long long> &route_From_Whome, unordered_map < int, unordered_map<int, long long>> &map_Neighbors)
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
            if(node_Dist+it->second<=dist_from_Begin[it->first])
            {
                dist_from_Begin[it->first] = node_Dist + it->second;
                route_From_Whome[it->first] = i_Node;
                list.push(make_pair(dist_from_Begin[it->first], it->first));
            }
            //dist_from_Begin[it->first] = max(dist_from_Begin[i_Node]+it->second,dist_from_Begin[it->first]);
        }

    }
}
void Dijkstra(int i_Op,vector<long long> &dist_from_Begin, unordered_map < int, unordered_map<int, long long>> &map_Neighbors)
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
            if(node_Dist+it->second<=dist_from_Begin[it->first])
            {
                dist_from_Begin[it->first] = node_Dist + it->second;
                //route_From_Whome[it->first] = i_Node;
                list.push(make_pair(dist_from_Begin[it->first], it->first));
            }
            //dist_from_Begin[it->first] = max(dist_from_Begin[i_Node]+it->second,dist_from_Begin[it->first]);
        }

    }
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ++n;
    priority_queue<tuple<long long, int, int>> route_Rank;
    unordered_map<int,unordered_map<int,long long>> map_Neighbors;
    //unordered_map<int, unordered_map<int, long long>> map_Revers_Route;
    vector<long long> dist_from_Begin;
    //vector<long long> dist_from_End;
    vector<long long> route_From_Whome;
    dist_from_Begin.resize(n);
    //dist_from_End.resize(n);
    route_From_Whome.resize(n);
    fill(dist_from_Begin.begin(), dist_from_Begin.end(),((1ull << 63) - 1ull));
    //fill(dist_from_End.begin(), dist_from_End.end(),((1ull << 63) - 1ull));
    fill(route_From_Whome.begin(), route_From_Whome.end(), 1ll);
    int a, b;
    long long u;
    while(m--)
    {

        cin >> a >> b >> u;
        route_Rank.push(make_tuple(u,a,b));
        if(map_Neighbors[a].find(b) == map_Neighbors[a].end())
        {
            map_Neighbors[a][b] = u;
        }
        else
        {
            map_Neighbors[a][b] = min(u, map_Neighbors[a][b]);
        }

        //map_Revers_Route[b][a]= u;
        
    }

    Dijkstra(1,dist_from_Begin,route_From_Whome, map_Neighbors);
    //Dijkstra(n - 1, dist_from_End, map_Revers_Route);
    long long ans = dist_from_Begin[n-1];
    // vector<int> path;
    // path.push_back(n - 1);
    // for (auto it = route_From_Whome[n - 1]; it != 1;it=route_From_Whome[it])
    // {
    //     path.push_back(it);
    // }
    // path.push_back(1);
    // int max_price = 0;
    // for (auto it = next(path.rbegin());it!=path.rend();++it)
    // {
    //     int u = map_Neighbors[*prev(it)][*it];         
    //     if(u>max_price)
    //     {
    //         max_price = u;
    //     }
    // }
    //while(!route_Rank.empty()&&get<0>(route_Rank.top())>=max_price)
    while(!route_Rank.empty())
    {

        long long be_U = get<0>(route_Rank.top());
        long long half_U = be_U >> 1;
        ans = min(ans,half_U+dist_from_Begin[n-1]-dist_from_Begin[get<2>(route_Rank.top())]+dist_from_Begin[get<1>(route_Rank.top())]);
        route_Rank.pop();
    }

        // prior node

    cout << ans<< "\n";
}
