#include<iostream>
using namespace std;
int n, m, t;
class yee{
public:
    int x0;
    int y0;
    int dx;
    int dy;
    //bool flag = 1;
    bool b_in()
    {
        if(x0<0||x0>n-1||y0<0||y0>m-1)
        {
            dx = 0;
            dy = 0;
            x0 = -1;
            y0 = -1;
            return 0;
        }
        return 1;
    }

};

bool yee_in(yee *mo)
{
   // bool flag=0;
    for (int i = 0; i < t;++i)
    {
        if(mo[i].b_in())
        {
            return 1;
        }
    }
    return 0;
}
int main()
{
    
    cin >> n >> m >> t;
    int maze[n][m];
    fill(*maze, maze[n - 1] + m,0);

    yee mo[t];
    for (int i = 0; i < t; ++i)
    {
        cin >> mo[i].x0 >> mo[i].y0 >> mo[i].dx >> mo[i].dy;
        maze[mo[i].x0][mo[i].y0] = 1;
    }
    while(yee_in(mo))
    {
        
        for (int i = 0; i < n;++i)
        {
            for (int j = 0; j < m;++j)
            {
                cout<<maze[i][j]<<" ";
            }
            cout << "\n";
        }
        
        for (int i = 0; i < t;++i)
        {
                mo[i].x0 += mo[i].dx;
                mo[i].y0 += mo[i].dy;
                //cout << "do2 " << mo[i].x0 << " " << mo[i].y0 << "\n";
        }
        for (int i = 0; i < t;++i)
        {
            //cout << "do1 " << mo[i].x0 << " " << mo[i].y0 << "\n";
        }
        for (int i = 0; i < t;++i)
        {
            //cout << "do " << mo[i].x0 << " " << mo[i].y0 << "\n";
            if(maze[mo[i].x0][mo[i].y0]>0&&mo[i].b_in())
            {
                
                mo[i].x0 = -1;
                mo[i].y0 = -1;
                mo[i].dx = 0;
                mo[i].dy = 0;
                ++maze[mo[i].x0][mo[i].y0];
            }
            
        }
        for (int i = 0; i < t;++i)
        {
            //cout << "do" << mo[i].x0 << " " << mo[i].y0 << "\n";
        }
        for (int i = 0; i < n;++i)
        {
            for (int j = 0; j < m;++j)
            {
                if(maze[i][j]>1)
                {
                    maze[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < t;++i)
        {
            //cout <<mo[i].x0<<" "<<mo[i].y0<<" "<< mo[i].b_in() << "\n";
            if(mo[i].b_in())
            {
                maze[mo[i].x0][mo[i].y0] = 1;
            }
        }
        
        
    }
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cout<<maze[i][j]<<" ";
        }
        cout << "\n";
    }
    int totle = 0;
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            totle += maze[i][j];
        }
    }
    cout << totle << "\n";
}