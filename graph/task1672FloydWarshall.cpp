#include<iostream>
#include<vector>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> dist(n+1,vector<long long>(n+1,(1ll<<40)));
    for(int i=0;i<=n;i++)
    {
        dist[i][i] = 0;
    }
    for(int i=0;i<m;++i)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = dist[a][b];
        
    }
    for(int k=1;k<=n;k++)
    {
        for (int i = 1; i <=n;i++)
        {
            if (i == k) continue;
            for (int j = i+1;j<=n;j++)
            {
                if (j == k) continue;
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    dist[j][i] = dist[i][j];
                }
            }
        }
    }
    for(int i=0;i<q;++i)
    {
        int a, b;
        cin >> a >> b;
        if(dist[a][b]>(1ll<<39))
        {
            cout << "-1\n";
        }
        else 
        {
            cout << dist[a][b]<< "\n";
        }
        
    }
    return 0;
}