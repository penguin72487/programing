#include<iostream>
#include<vector>
using namespace std;
vector<long long> dist;
long long bellman_Ford(int now)
{

}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> tunnel(n); // adj list
    

    for(int i=0,a,b,c; i<n; ++i)
    {
        cin >> a >> b>>c;
        --a;
        --b;
        tunnel[a].push_back(make_pair(b,c));
    }
    dist.resize(n);
    fill(dist.begin(),dist.end(),((1ull<<63) - 1ull));
    dist[0] = 0;
    cout << bellman_Ford(0)<<"\n";

    return 0;
}