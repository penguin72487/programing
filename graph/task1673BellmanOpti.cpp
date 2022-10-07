#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<algorithm>
#include <tuple>
#include<unordered_map>
#include <utility>
using namespace std;
vector<long long> dist;
//vector<vector<pair<int,long long>>> tunnel(2500);
//unordered_map<int,unordered_map<int,long long>> tunnel;
queue<tuple<int, int, long long>> STL;
unordered_map<int,unordered_map<int,long long>> path;
unordered_map<int,unordered_map<int,long long>> count_Pass;
set<int> update;
bool flag=0;
bool cycle=0;
void bellman_Ford(int now)
{
    
    //pass_Node[now] = 1;
    // for (auto it = tunnel[now].begin(); it != tunnel[now].end();++it)
    // {
    //     STL.push(it->first);
    // }

    while(!STL.empty())
    {
        long long t_Now, v, u;
        tie(t_Now,v,u)=STL.front();
        STL.pop();
        
        if(path[t_Now].find(v) != path[t_Now].end())
        {
            continue;
        }
        ++count_Pass[t_Now][v];
        path[t_Now][v]= 1;
        if(dist[t_Now]+u>dist[v])
        {
            flag = 1;
            dist[v] = dist[t_Now] + u;
            update.insert(v);
            for (auto it = tunnel[v].begin(); it != tunnel[v].end();++it)
            {
                if(path[v].find(it->first) != path[v].end())
                {
                    continue;
                }
                STL.push(make_tuple(v, it->first, it->second));
            }
        }
        
    }
}
long long bellman_Ford(int now,int target)
{

    for (auto it = tunnel[now].begin(); it != tunnel[now].end();++it)
    {
            STL.push(make_tuple(now, it->first, it->second));
    }
    for(int i=0,tmp=dist.size();i<tmp;++i)
    {
        flag=0;
        bellman_Ford(0);
        if(!flag)
        {
            break;
        }
        for(auto it=update.begin();it!=update.end();++it)
        {
            for(auto jt=tunnel[*it].begin();jt!=tunnel[*it].end();++jt)
            {
                STL.push(make_tuple(*it,jt->first,jt->second));
            }
        }
        update.clear();
        path.clear(); 
    }
    flag =0;
    while(!STL.empty())
    {
        STL.pop();
    }
    for(auto it=count_Pass.begin();it!=count_Pass.end();++it)
    {
        for(auto jt = it->second.begin();jt!=it->second.end();++jt)
        {
            if(jt->second==dist.size())
            {
                flag = 1;
                //tunnel[it->first][jt->first] = (1ll<<50);
                STL.push(make_tuple(it->first, jt->first, (1ll<<50)));
            }
        }
    }
    if(flag==1)
    {
        bellman_Ford(0);
    }
    long long ans = dist[target] > (1ll << 49) ? -1 : dist[target];
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
     // adj list

    int a, b;
    long long c;
    //tunnel.resize(n);
    for(int i=0; i<m; ++i)
    {
        cin >> a >> b>>c;
        --a;
        --b;
        tunnel[a].push_back(make_pair(b, c));
    }
    dist.resize(n);
    fill(dist.begin(),dist.end(),-((1ll<<46)));
    dist[0] = 0;
    cout << bellman_Ford(0,n-1)<<"\n";

    return 0;
}