#include<iostream>
#include<vector>
using namespace std;
vector<long long> dist;
vector<vector<pair<int, int>>> tunnel;
vector<bool> pass_By;
bool flag=1;
void bellman_Ford(int now)
{
    for(auto it=tunnel[now].begin();it!=tunnel[now].end();++it)
    {
        if(pass_By[it->first])
        {
            continue;
        }
        if(it->second+dist[now]>dist[it->first])
        {
            flag=1;
            dist[it->first] = it->second + dist[now];
            bellman_Ford(it->first);
        }
    }
}
long long bellman_Ford(int now,int target)
{
    pass_By.resize(dist.size());
    for(long long i=0;i<dist.size()&&flag;++i)
    {
        flag = 0;
        fill(pass_By.begin(),pass_By.end(),0);
        pass_By[now] = 1;
        bellman_Ford(now);
    }
    if(flag)
    {
        return -1ll;
    }
    return dist[target];
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
    fill(dist.begin(),dist.end(),-((1ull<<63)));
    dist[0] = 0;
    cout << bellman_Ford(0,n-1)<<"\n";

    return 0;
}