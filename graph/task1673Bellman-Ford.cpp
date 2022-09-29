#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
vector<long long> dist;
vector<vector<pair<int, int>>> tunnel;
queue<int> STL;
vector<unsigned long long> pass_By;
bool flag=0;
bool cycle=0;
void bellman_Ford(int now)
{
   
    vector<bool> pass_Node(dist.size(),0);
    STL.push(now);
    //pass_Node[now] = 1;
    // for (auto it = tunnel[now].begin(); it != tunnel[now].end();++it)
    // {
    //     STL.push(it->first);
    // }

    while(!STL.empty())
    {
        int t_Now=STL.front();
        STL.pop();
        ++pass_By[t_Now];
        for (auto it = tunnel[t_Now].begin(); it != tunnel[t_Now].end();++it)
        {
            if(pass_Node[it->first])
            {
                continue;
            }
            else if(dist[t_Now]+it->second>dist[it->first])
            {
                flag=1;
                dist[it->first] = dist[t_Now] + it->second;
                STL.push(it->first);
                pass_Node[it->first] = 1;
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