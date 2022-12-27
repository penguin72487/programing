#include<bits/stdc++.h>
using namespace std;
void water_Bottle(int t_x,int t_y,char c,vector<vector<char>> &graph)
{
    queue<pair<int, int>> STL; // x y
    int dx[4] = {0, -1, 0, 1};
    int dy[4] = {1, 0, -1, 0};
    char target = graph[t_y][t_x];
    int pass_By[graph.size()][graph[0].size()];
    for(int i = 0; i < graph.size(); ++i)
    {
        for(int j = 0; j < graph[0].size(); ++j)
        {
            pass_By[i][j] = 0;
        }
    }
    STL.push(make_pair(t_x,t_y));
    while(!STL.empty())
    {
        int x = STL.front().first;
        int y = STL.front().second;
        
        if(x<0||y<0||y>=graph.size()||x>=graph[0].size())
        {
            break;
        }
        STL.pop();
        //cout<<x<<" "<<y<<"\n";
        graph[y][x] = c;
        for (int i = 0;i<4;++i)
        {
            //cout << i << " ";
            if(x+dx[i]<0||y+dy[i]<0||y+dy[i]>=graph.size()||x+dx[i]>=graph[0].size())
            {
                continue;
            }
            if(graph[y+dy[i]][x+dx[i]]==target&&pass_By[y+dy[i]][x+dx[i]]!=1)
            {
                STL.push(make_pair(x+dx[i],y+dy[i]));
                pass_By[y+dy[i]][x+dx[i]]=1;
            }
        }
    }
}
bool make_Sence(int &n,int &m,int &x,int &y,int &x1,int &x2,int &y1,int &y2)
{
    if(x1<0 || x2<0 || y1<0 || y2<0||x<0||y<0||x>=n||x1>=n||x2>=n||y>=m||y1>=m||y2>=m)
    {
        x = 1;
        x1 = 1;
        x2 = 1;
        y= 1;
        y1 = 1;
        y2 = 1;
        return 0;
    }
    return 1;
}
int main()
{
    cin.tie (0)->sync_with_stdio(0);
    cout.tie(0);
    vector<vector<char>> graph;
    char command;
    while(cin>>command)
    {   
        int n, m, x=1, y=1, x1=1, x2=1, y1=1, y2=1;
        char c;
        string name;

        if(command == 'I')
        {
            cin >> m >> n;
            graph.resize (n);
            for(auto it = graph.begin(); it != graph.end(); ++it)
            {
                it->resize (m);
                for(auto jt=it->begin(); jt != it->end(); ++jt)
                {
                    *jt='O';
                }
            }
         
        }
        else if(command == 'C')
        {
            for(auto it = graph.begin(); it != graph.end(); ++it)
            {
                for(auto jt=it->begin(); jt != it->end(); ++jt)
                {
                    *jt='O';
                }
            }
        }
        else if(command == 'L') // change dot calor 
        {
            cin >> x >> y>>c;
            --x;--y;
            if(!make_Sence(m,n,x,y,x1,x2,y1,y2))
            {
                continue;
            }
            graph[y][x] = c;
             
        }
        else if(command == 'V')
        {    
            cin >> x >> y1>>y2>>c;
            --x;--y1;//--y2;
            if(!make_Sence(m,n,x,y,x1,x2,y1,y2))
            {
                continue;
            }
            for (int i = y1;i<y2;++i)
            {
                graph[i][x] = c;
            }
                 

        }
        else if(command == 'H')
        {
            cin >> x1 >> x2 >> y>>c;
            --x1;/*--x2;*/--y;
            if(!make_Sence(m,n,x,y,x1,x2,y1,y2))
            {
                continue;
            }
            for(int i=x1;i<x2;++i)
            {
                graph[y][i] = c;
            }
             
        }
        else if(command == 'K')
        {

            cin >>x1>>y1>>x2>>y2>>c;
            --x1;/*--x2;*/--y1;/*--y2;*/
            if(!make_Sence(m,n,x,y,x1,x2,y1,y2))
            {
                continue;
            }
            for(int i=y1;i<y2;++i)
            {
                for(int j=x1;j<x2;++j)
                {
                    graph[i][j] = c;
                }
            }
        }
        else if(command == 'F')
        {
            cin >> x >> y >> c;
            --x;
            --y;
            if(!make_Sence(m,n,x,y,x1,x2,y1,y2))
            {
                continue;
            }
            water_Bottle(x,y,c,graph);
        }
        else if(command == 'S')
        {
            cin >> name;
            cout << name << "\n";
            for(auto it = graph.begin(); it != graph.end(); ++it)
            {
                for(auto jt=it->begin(); jt != it->end(); ++jt)
                {
                    cout << *jt;
                }
                cout<<"\n";
            }

        }
        else if(command == 'X')
        {
            break;
        }

    }
        

    return 0;
}
