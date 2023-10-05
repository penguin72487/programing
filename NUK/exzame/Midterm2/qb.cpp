#include <bits/stdc++.h>
using namespace std;
int dx[]={0,-1,0,1};
int dy[]={-1,0,1,0};
void dfs(int x,int y,vector<string>& maze)
{
    int n=maze.size();
    int m=maze[0].size();
    if(x<0||x>=n||y<0||y>=m||maze[x][y]!='.')
    {
        return;
    }
    maze[x][y]='#';
    for(int i=0;i<4;++i)
    {
        dfs(x+dx[i],y+dy[i],maze);
    }

}
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
    }
    int room=0;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(s[i][j]=='.')
            {
                ++room;
                dfs(i,j,s);
            }
        }
    }
    cout<<room<<"\n";
}
