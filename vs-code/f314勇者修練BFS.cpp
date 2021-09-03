#include<iostream>
#include<map>
#include<unordered_map>
#include<vector>
#include<deque>
#include<algorithm>
using namespace std;
class node{
public:
    int i_Data;
    int i_BFSMax;

};
int main()
{
    int n, m;
    cin >> n >> m;
    n += 2;
    m += 2;
    node matrix[n][m];
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            matrix[i][j].i_Data = -2147483648;
            matrix[i][j].i_BFSMax = -2147483648;            
        }
    }
    
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cout << matrix[i][j].i_BFSMax<<" ";
        }
        cout << "\n";
    }
    for (int i = 1; i < n-1;++i)
    {
        for (int j = 1; j < m-1;++j)
        {
            cin >> matrix[i][j].i_Data;
        }
    }
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cout << matrix[i][j].i_Data<<" ";
        }
        cout << "\n";
    }
    deque<pair<int, int> *> list;
    int dx[3] = {-1, 0, 1};
    int dy[3] = {0, 1, 0};
    for (int i = 1; i < m - 1;++i)
    {
        cout << i << " ";
        pair<int, int> tmp(1,i);
        list.push_back(&tmp);

    }
        while (!list.empty())
        {
            pair<int, int> *now = list.front();
            int x = now->first;
            int y = now->second;
            cout << x << " " << y << "\n";
            for (int i = 0; i < n; ++i)
            {
                if (matrix[x + dx[i]][y + dy[i]].i_Data > 0)
                {
                    pair<int, int> tmp(x + dx[i], y + dy[i]);
                    list.push_back(&tmp);
                    matrix[x + dx[i]][y + dy[i]].i_BFSMax = max(matrix[x + dx[i]][y + dy[i]].i_BFSMax, matrix[x][y].i_BFSMax + matrix[x + dx[i]][y + dy[i]].i_Data);
                }
            }
            list.pop_front();
        }
    int i_Max=-2147483648;
    for (int i = 1; i < m-1;++i)
    {
        i_Max = max(i_Max, matrix[n - 1][i].i_BFSMax);
    }
    cout << i_Max << "\n";
}