#include<iostream>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
const int ascii=97;
int asciiv=-1;
void maze_DFS(int x, int y, int v_Type);
char maze[12][12];
int main()
{
    int n, m;
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
        if(maze[i][0]=='S')
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
    ++asciiv;
    asciiv %= 26;
    maze[x][y] = ascii+(asciiv);
    for (int i = 0; i < 4;++i)
    {
        if (maze[x+dx[i]][y+dy[i]] == 'E')
        {
            return;
        }
    }
    for (int i = -1; i < 2;++i)
    {
        if (maze[x + dx[(v_Type + i+4) % 4]][y + dy[(v_Type + i+4) % 4]] == '.')
        {
            maze_DFS(x + dx[(v_Type + i+4) % 4], y + dy[(v_Type + i+4) % 4], (v_Type + i+4) % 4);
        }
    }

    return;
}