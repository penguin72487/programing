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
    /*
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cout << matrix[i][j].i_BFSMax<<" ";
        }
        cout << "\n";
    }
    */
    for (int i = 1; i < n-1;++i)
    {
        for (int j = 1; j < m-1;++j)
        {
            cin >> matrix[i][j].i_Data;
        }
    }
    /*
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cout << matrix[i][j].i_Data<<" ";
        }
        cout << "\n";
    }
    */
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            //matrix[i][j].i_Data = -2147483648;
            matrix[i][j].i_BFSMax = matrix[i][j].i_Data;            
        }
    }
    bool iib_TrNode[n][m];
    fill(&iib_TrNode[0][0],&iib_TrNode[n-1][m],0);
    deque<pair<int, int> *> list;
    int dx[3] =  {0, 1, 0};
    int dy[3] = {-1, 0, 1};
    for (int i = 1; i < m - 1;++i)
    {
        //cout << i << " ";
        pair<int, int>* tmp=new pair<int,int>(1,i);
        //iib_TrNode[1][i] = 1;
        //cout <<"for"<< tmp->first << " " << tmp->second << "\n";
        list.push_back(tmp);
    }
    //cout << "\n";
    while (!list.empty())
    {
        pair<int, int> *now = list.front();
        int x = now->first;
        int y = now->second;
        iib_TrNode[x][y] = 1;
        //cout << x << " " << y << " " << matrix[x][y].i_BFSMax << "\n";
        for (int i = 0; i < 3; ++i)
        {
            if (matrix[x + dx[i]][y + dy[i]].i_Data > -2147483647&&iib_TrNode[x+dx[i]][y+dy[i]]==0)
            {
                pair<int, int>* tmp= new pair<int,int>(x + dx[i], y + dy[i]);
                list.push_back(tmp);
                //cout << "matrix[x + dx[i]][y + dy[i]].i_BFSMax" << matrix[x + dx[i]][y + dy[i]].i_BFSMax << "\n";
                matrix[x + dx[i]][y + dy[i]].i_BFSMax = max(matrix[x + dx[i]][y + dy[i]].i_BFSMax, matrix[x][y].i_BFSMax + matrix[x + dx[i]][y + dy[i]].i_Data);
            }
        }
        delete now;
        list.pop_front();
    }
    int i_Max=-2147483648;
    for (int i = 1; i < m-1;++i)
    {
        i_Max = max(i_Max, matrix[n - 2][i].i_BFSMax);
    }
    cout << i_Max << "\n";

}