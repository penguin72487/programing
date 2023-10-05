#include<bits/stdc++.h>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1,0,-1,0};
void dfs(int x, int y, vector<vector<int>> &vvi, vector<vector<char>> &vvc)
{   
    if(vvi[x][y])
    {
        return;
    }
    vvi[x][y] = 1;
    for (int i = 0; i < 4;++i)
    {
        if(vvc[x+dx[i]][y+dy[i]] ==vvc[x][y]&&!vvi[x+dx[i]][y+dy[i]] )
        {
            dfs(x + dx[i], y + dy[i], vvi, vvc);
        }
    }
}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    int n, m;
    int k=0;
    while (t--)
    {
        ++k;
        cin >> n >> m;
        n+=2;
        m+=2;
        vector<vector<char>> vvc(n, vector<char>(m, '*'));
        for (int i = 1; i < n-1; ++i)
        {
            for (int j = 1; j < m-1; ++j)
            {
                cin >> vvc[i][j];
            }
        }
        vector<vector<int>> vvi(n, vector<int>(m, 0));
        vector<tuple<int, char>> cc(26, {0, 'a'});
        for (int i = 0; i < 26; ++i)
        {
            get<1>(cc[i]) = 'a' + i;
        }
        for (int i = 1; i < n-1; ++i)
        {
            for (int j = 1; j < m-1; ++j)
            {
                if (vvi[i][j] == 0)
                {
                    ++get<0>(cc[vvc[i][j]-'a']);
                    dfs(i, j, vvi, vvc);
                }
            }
        }
        sort(cc.begin(), cc.end(), [](auto& r , auto& l) -> bool
             {
            auto& [a, b] = r;
            auto& [c, d] = l;
            if(a==c)
            {
                return (b < d);
            }
            return (a > c); });
        cout << "World #" << k << "\n";
        for(auto& [a,b]:cc){
            if(a==0)
            {
                break;
            }
            cout << b << ": " << a << "\n";
        }
    }
        return 0;
}