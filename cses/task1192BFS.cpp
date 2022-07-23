#include <iostream>
#include <queue>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    n += 2;
    m+= 2;
    int maze[n][m];
    char c_T;
    int count_Room=0;

    for(int i=1; i<n-1; i++){
        for(int j=1; j<m-1; j++)
        {
            cin >> c_T;
            if(c_T=='#')
            {
                maze[i][j] = -1;
            }
            else
            {
                maze[i][j] = 0;
            }
        }
    }
    for(int i=0; i<n; i++){
        maze[i][0] = -2;
        maze[i][m - 1] = -2;
    }
    for (int i = 0; i < m;++i)
    {
        maze[0][i] = -2;
        maze[n-1][i] = -2;
    }
        int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1,0,-1,0};
    queue<pair<int, int>> sea_BFS;
    sea_BFS.push(make_pair(1,1));
    queue<pair<int, int>> room_BFS;
    while(!sea_BFS.empty())
    {
        
        int x=sea_BFS.front().first;
        int y=sea_BFS.front().second;
        sea_BFS.pop();
        if(x<0||x>=n||y<0||y>=m||maze[x][y]==-2)
        {
            continue;
        }
        else if(maze[x][y]==-1)
        {
            for (int i = 0; i < 4;++i)
            {
                if(maze[x+dx[i]][y+dy[i]]>-2)
                {
                    sea_BFS.push(make_pair(x+dx[i],y+dy[i]));
                }
            }
            maze[x][y] = -2;
        }
        else if(maze[x][y]==0)
        {
            ++count_Room;
            room_BFS.push(make_pair(x,y));
            while(!room_BFS.empty())
            {
                int x = room_BFS.front().first;
                int y = room_BFS.front().second;
                room_BFS.pop();
                if(x<0||x>=n||y<0||y>=m||maze[x][y]<0)
                {
                    continue;
                }
                else if(maze[x][y]==0)
                {
                    
                    for (int i = 0; i < 4;++i)
                    {
                        if(maze[x+dx[i]][y+dy[i]]==0)
                        {
                            room_BFS.push(make_pair(x+dx[i],y+dy[i]));
                        }
                        else if(maze[x+dx[i]][y+dy[i]]==-1)
                        {
                            sea_BFS.push(make_pair(x+dx[i],y+dy[i]));
                        }
                    }
                    maze[x][y] = -2;
                }
            }

        }
    }
    cout << count_Room << "\n";
}