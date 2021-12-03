#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    int m = n;
    int k = 0;
    int zero_Max = 0;
    int maze[n][m];
    for (int i = 0; i < n;++i)
    {
        int tmp = 0;
        for (int j = 0; j < m;++j)
        {
            cin >> maze[i][j];
            if(maze[i][j]==0)
            {
                ++tmp;
            }
        } 
        if(tmp==n)
        {
            ++k;
            continue;
        }
    }
    
    for (int i = 0; i < n;++i)
    {
        int tmp = 0;
        for (int j = 0; j < m;++j)
        {
            if(maze[i][j]==0)
            {
                ++tmp;
            }
        }
        if(tmp==n)
        {
            continue;
        }
        zero_Max = max(zero_Max, tmp-k);
    }
    cout << zero_Max +k<< "\n";
    return 0;
}