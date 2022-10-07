#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pi (3.141592653589)
#define mod 1000000007
#define int long long
#define float double
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define all(c) c.begin(), c.end()
#define min3(a, b, c) min(c, min(a, b))
#define min4(a, b, c, d) min(d, min(c, min(a, b)))
#define rrep(i, n) for(int i=n-1;i>=0;i--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
 
const int INF = 1e18;
 
void dfs(vector<vector<int>>&g, vector<int>&s, int u) {
  s[u] = 1;
  for(auto v:g[u])
    if (!s[v])
      dfs(g, s, v);
} 
 
int32_t main(){
fast
// Fuck Ratings, I'm in Love with Experience.
// Once a Charas, Always a CHARAS.
 
 
int t=1;
//cin>>t;
while(t--){
    int n, m, u, v, w;cin>>n>>m;
    vector<vector<int>>a(n+1);
    vector<vector<int>>b(n+1);
    vector<tuple<int, int, int>>e(m);
    rep(i, m){
        cin>>u>>v>>w;
        a[u].pb(v);
        b[v].pb(u);
        e[i]={u, v, -w};
    }
    vector<int>vis(n+1), vis1(n+1);
    dfs(a, vis, 1);
      dfs(b, vis1, n);
      vector<int>d(n+1, INF);
      d[1]=0;
      bool flag=0;
      for (int i=1; i<=n;i++) {
        flag=0;
        for (auto x:e){
              tie(u, v, w) = x;
              if(vis[u] and vis1[v] and d[u]+w<d[v]){
                  flag=1;
                  d[v]=d[u]+w;
              }
        }
      }
      if(flag)cout<<-1;
      else cout<<d[n]*-1;
}
return 0;
}