#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void water_Bottle(int t_x,int t_y,char c,vector<vector<char>> &graph)
{
    queue<pair<int, int>> STL;
    STL.push(make_pair(t_x,t_y));
    while(!STL.empty())
    {
        int x = STL.front().first;
        int y = STL.front().second;
        if(x<0||y<0||x>=graph.size()||y>=graph[0].size())
        {
            break;
        }
        STL.pop();
        

    }
}
int main()
{
    cin.tie (0)->sync_with_stdio(0);
    cout.tie(0);
    vector<vector<char>> graph;
    char command;
    while(cin>>command)
    {   
        int n, m, x, y, x1, x2, y1, y2;
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
        else if(command == 'L'||command == 'G') // change dot calor 
        {
            cin >> x >> y>>c;
            --x;--y;
            graph[y][x] = c;
             
        }
        else if(command == 'V')
        {    
            cin >> x >> y1>>y2>>c;
            --x;--y1;//--y2;
            for (int i = y1;i<y2;++i)
            {
                graph[i][x] = c;
            }
                 

        }
        else if(command == 'H')
        {
            cin >> x1 >> x2 >> y>>c;
            --x1;/*--x2;*/--y;
            for(int i=x1;i<x2;++i)
            {
                graph[y][i] = c;
            }
             
        }
        else if(command == 'K')
        {

            cin >>x1>>x2>>y1>>y2>>c;
            --x1;/*--x2;*/--y1;/*--y2;*/
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
