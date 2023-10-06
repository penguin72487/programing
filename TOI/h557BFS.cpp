#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1,0,-1,0};
unordered_map<int, unordered_map<int, int>> maze;
vector<pair<int, int>> mark;
queue<pair<int, int>> list;
long long ans = 0;
void BFS(int x_Op,int y_Op,int r);
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n, r;
    cin >> n >> r;
    
    int x_Cash,y_Cash;
    for (int i = 0; i < n;++i)
    {
        cin >> x_Cash >> y_Cash;
        BFS(x_Cash, y_Cash, r);
    }
    for(auto it=maze.begin(); it!=maze.end();++it)
    {
        for(auto jt = it->second.begin(); jt != it->second.end();++jt)
        {
            ans += (jt->second & 1);
        }
    }
    
    cout << ans << "\n";
}
void BFS(int x_Op,int y_Op,int r)
{
    unordered_map < int, unordered_map<int, int>> maze_Path;

    int m = 1E6;
    int lowest = -m;
    // for(int i = lowest; i < m;++i)
    // {
    //     maze[i][lowest] = -2;
    //     maze[lowest][i] = -2;
    //     maze[i][m] = -2;
    //     maze[m][i] = -2;
    // }

    
    int r_Pow2 = r * r;
    //vector<pair<int, int>> ans;
    
    int dist_X_Cash,dist_Y_Cash;
    list.push(make_pair(x_Op,y_Op));
    while(!list.empty())
    {
        int x = list.front().first;
        int y = list.front().second;
        list.pop();
        if(maze[x].find(y)!=maze[x].end())
        {
            continue;
        }
        else if(x<lowest||x>m||y<lowest||y>m)
        {
            continue;
        }
        //cout << x << " " << y << "\n";
        maze_Path[x][y] = -2;
        dist_X_Cash = x - x_Op;
        dist_Y_Cash = y - y_Op;
        if(dist_X_Cash*dist_X_Cash+dist_Y_Cash*dist_Y_Cash<=r_Pow2)
        {
            if(maze[x].find(y)==maze[x].end())
            {
                maze[x][y] = 1;
            }
            else
            {
                ++maze[x][y];
            }
 

            for (int i = 0; i < 4;++i)
            {
                if(maze_Path[x+dx[i]].find(y+dy[i])==maze_Path[x+dx[i]].end())
                {
                    list.push(make_pair(x + dx[i], y + dy[i]));
                }
            }
        }
        

    }

}