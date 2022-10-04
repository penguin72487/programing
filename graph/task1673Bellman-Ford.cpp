#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include <tuple>
using namespace std;
vector<long long> dist;
vector<vector<pair<int, int>>> tunnel;
queue<tuple<int, int, int>> STL;
vector<unsigned long long> pass_By;
bool flag=0;
bool cycle=0;
void bellman_Ford(int now)
{
    set<tuple<int, int, int>> path;
    for (auto it = tunnel[now].begin(); it != tunnel[now].end();++it)
    {
        STL.push(make_tuple(now, it->first, it->second));
    }

    //pass_Node[now] = 1;
    // for (auto it = tunnel[now].begin(); it != tunnel[now].end();++it)
    // {
    //     STL.push(it->first);
    // }

    while(!STL.empty())
    {
        int t_Now, v, u;
        tie(t_Now,v,u)=STL.front();
        STL.pop();
        ++pass_By[t_Now];
        if(path.find(make_tuple(t_Now, v, u)) != path.end())
        {
            continue;
        }
        path.insert(make_tuple(t_Now, v, u));
        if(dist[t_Now]+u>dist[v])
        {
            flag = 1;
            dist[v] = dist[t_Now] + u;
            for (auto it = tunnel[v].begin(); it != tunnel[v].end();++it)
            {
                STL.push(make_tuple(t_Now, it->first, it->second));
            }
        }
        
    }
}
long long bellman_Ford(int now,int target)
{
    pass_By.resize(dist.size());
    fill(pass_By.begin(),pass_By.end(),0);
    // for (auto it = tunnel[now].begin(); it != tunnel[now].end();++it)
    // {
    //         dist[it->first] = dist[now] + it->second;
    //         STL.push(it->first);
    // }
    for(int i=0,tmp=dist.size();i<tmp;++i)
    {
        flag=0;
        bellman_Ford(0);
        if(!flag)
        {
            break;
        }
    }
    return pass_By[target]==dist.size()?-1:dist[target];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    tunnel.resize(n); // adj list
    

    for(int i=0,a,b,c; i<m; ++i)
    {
        cin >> a >> b>>c;
        --a;
        --b;
        tunnel[a].push_back(make_pair(b,c));
    }
    dist.resize(n);
    fill(dist.begin(),dist.end(),-((1ull<<31)));
    dist[0] = 0;
    cout << bellman_Ford(0,n-1)<<"\n";

    return 0;
}