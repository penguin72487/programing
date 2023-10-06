#include<iostream>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int n, m;
void maze_DFS(int x, int y, int v_Type);
char maze[12][12];
int main()
{
    
    cin >> n >> m;
    
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cin >> maze[i][j];
        }
    }
    for (int i = 0; i < n;++i)
    {
        if(maze[i][0]=='X')
        {
            maze_DFS(i,1,0);
            break;
        }
    }
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cout << maze[i][j];
        }
        cout << "\n";
    }
}
void maze_DFS(int x,int y,int v_Type)
{
    if (y==11)
    {
        maze[x][y] = 'X';
        for (int i = 0; i < n;++i)
        {
            for (int j = 0; j < m;++j)
            {
                cout << maze[i][j];
            }
            cout << "\n";
        }
        exit(1);
    }
    maze[x][y] = 'X';
   
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cout << maze[i][j];
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i = -1; i < 2;++i)
    {
        if (maze[x + dx[(v_Type + i+4) % 4]][y + dy[(v_Type + i+4) % 4]] == '.')
        {
            maze_DFS(x + dx[(v_Type + i+4) % 4], y + dy[(v_Type + i+4) % 4], (v_Type + i+4) % 4);
        }
    }

    return;
}