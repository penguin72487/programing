#include <iostream>
#include <queue>
#include <vector>
#include<iterator>
#include <unordered_map>

using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,q;
    cin >> n >> q;
    unordered_map<int,unordered_map<int,long long>> map_Neighbors;
    
    while(q--)
    {
        int a, b;
        long long u;
        cin >> a >> b >> u;
        map_Neighbors[a][b]=u;
        map_Neighbors[b][a]=u;
        
    }
    ++n;
    priority_queue<pair<long long , int>,vector<pair<long long,int>>,greater<pair<long long,int>>> list;// prior node
    long long dist_from_Begin[n];
    long long route_From_Whome[n];
    fill(dist_from_Begin, dist_from_Begin + n, ((1ull << 63) - 1ull));
    fill(route_From_Whome, route_From_Whome + n, 1);
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
                route_From_Whome[it->first] = i_Node;
                list.push(make_pair(dist_from_Begin[it->first], it->first));
            }
            //dist_from_Begin[it->first] = max(dist_from_Begin[i_Node]+it->second,dist_from_Begin[it->first]);
        }

    }

    if(dist_from_Begin[n-1]==((1ull << 63) - 1ull))
    {
        cout << "-1";
    }
    else
    {
        vector<int> path;
        path.push_back(n - 1);
        for (auto it = route_From_Whome[n - 1]; it != 1;it=route_From_Whome[it])
        {
            path.push_back(it);
        }
        path.push_back(1);
        for (auto it = path.rbegin();it!=path.rend();++it)
        {
            cout << *it << " ";
        }
    }

}
