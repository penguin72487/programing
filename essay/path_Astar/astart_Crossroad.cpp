#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#include<list>
#include<deque>
using namespace std;
ofstream path("maze0Path.txt");
fstream f("maze0.txt");
class node{
public:
    int x, y;
    char spot;
    int pass=0; // count passed node;
    long double h = 0; // estimate funtion;
    
    priority_queue<node, vector<node>, less<node>> n_Inter;

    

    bool operator()(node a,node b)
    {
        if(a.pass+a.h==b.pass+b.h)
        {
            if(a.pass==b.pass)
            {
                if(a.h==b.h)
                {
                    return 1;
                }
                return (a.h > b.h);
            }
            return (a.pass>b.pass);
        }
        return (a.pass + a.h > b.pass + b.h);
    }
    friend void operator>>(istream& s,node &tmp)
    {
        s >> tmp.spot;
    }
    // bool cmp_Max(node a,node b)
    // {
    //     if(a.pass+a.h==b.pass+b.h)
    //     {
    //         if(a.pass==b.pass)
    //         {
    //             if(a.h==b.h)
    //             {
    //                 return 1;
    //             }
    //             return (a.h < b.h);
    //         }
    //         return (a.pass<b.pass);
    //     }
    //     return (a.pass + a.h < b.pass + b.h);
    // }
    bool cmp(node a,node b)
    {
        if(a.pass+a.h==b.pass+b.h)
        {
            if(a.pass==b.pass)
            {
                if(a.h==b.h)
                {
                    return 1;
                }
                return (a.h > b.h);
            }
            return (a.pass>b.pass);
        }
        return (a.pass + a.h > b.pass + b.h);
    }
    class cmp_Min{
        public:
        bool operator()(node a,node b)
        {
            if(a.pass+a.h==b.pass+b.h)
            {
                if(a.pass==b.pass)
                {
                    if(a.h==b.h)
                    {
                        return 1;
                    }
                    return (a.h > b.h);
                }
                return (a.pass>b.pass);
            }
            return (a.pass + a.h > b.pass + b.h);
        }
    };
    class cmp_Max
    {
        public:
        bool operator()(node a,node b)
        {
            if(a.pass+a.h==b.pass+b.h)
            {
                if(a.pass==b.pass)
                {
                    if(a.h==b.h)
                    {
                        return 1;
                    }
                    return (a.h < b.h);
                }
                return (a.pass<b.pass);
            }
            return (a.pass + a.h < b.pass + b.h);
        }
    };
};
class maze{
    public:
    int n, m;
    vector<vector<node>> maze_Node;
    int end_X, end_Y;
    maze(int &t_n,int &t_m)
    {
        n = t_n;
        m = t_m;
        end_X = n - 2;
        end_Y = m - 2;
        maze_Node.resize(n);
        for (int i = 0; i < m;++i)
        {
            maze_Node[i].resize(m);
        }
    }
    maze(int &t_n,int &t_m,fstream &f)
    {
        n = t_n;
        m = t_m;
        end_X = n - 2;
        end_Y = m - 2;
        maze_Node.resize(n);
        for (int i = 0; i < m;++i)
        {
            maze_Node[i].resize(m);
        }
        for (int i = 0; i < n;++i)
        {
            for (int j = 0; j < m;++j)
            {
                f >> maze_Node[i][j];
            }
        }
        this->h();

    }
    void h()
    {
        for (int i = 0; i < n;++i)
        {
            for (int j = 0; j < m;++j)
            {
                maze_Node[i][j].x = i;
                maze_Node[i][j].y = j;
                if(maze_Node[i][j].spot=='X')
                {
                    maze_Node[i][j].h = 100000000;
                    maze_Node[i][j].pass = 100000000;
                    continue;
                }
                maze_Node[i][j].h = ((end_X - i) * (end_X - i) + (end_Y - j) * (end_Y - j));
                
            }
        }
    }
    vector<node>& operator[](int& i)
    {
        return maze_Node[i];
    }
    vector<node>& operator[](int&& i)
    {
        return maze_Node[i];
    }
    bool sol_astar()
    {
        queue<node> STL;
        priority_queue<node, list<node>, node::cmp_Max> go_Str;
        maze_Node[1][1].pass = 1;
        STL.push(maze_Node[1][1]);
        int dx[4] = {0, 1, 0, -1};
        int dy[4] = {1, 0, -1, 0};
        
        while(!STL.empty())
        {
            node now = STL.back();
            STL.pop();
            int x = now.x;
            int y = now.y;
            maze_Node[x][y].spot = '$';
            path << *this<<"\n";
            if(x==end_X&&y==end_Y)
            {
                return 1;
            }
            
            for (int i = 0; i < 4;++i)
            {
                if(maze_Node[x+dx[i]][y+dy[i]].pass==0)
                {
                    maze_Node[x + dx[i]][y + dy[i]].pass = now.pass + 1;
                     maze_Node[x + dx[i]][y + dy[i]].n_Inter.push(maze_Node[x+dx[i]][y+dy[i]]);
                    
                }
            }
            maze_Node[x][y].spot = '&';

        }
        return 0;
    }
    friend istream operator>>(istream& s, maze &tmp);
    friend ostream& operator<<(ostream& s, maze &tmp)
    {
        for (auto it = tmp.maze_Node.begin(); it != tmp.maze_Node.end();++it)
        {
            for (auto jt = it->begin(); jt != it->end();++jt)
            {
                s << jt->spot;
            }
            s << "\n";
        }
        return s;
    }
};
int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m;
    f >> n >> m;
    maze A(n, m, f);
    A.sol_astar();

    cout << A << "\n";
    path.close();
    f.close();
}