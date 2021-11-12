#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n, m,h;
    cin >> n >> m >> h;
    char maze[n][m];
    for (int i = 0; i < n;++i)
    {
        fill(maze[i],maze[i]+m," ");
    }
    
}