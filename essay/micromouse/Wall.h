#include<iostream>
#include <fstream>
#include <vector>
using namespace std;
#ifndef _WALL_CC_
#define _WALL_CC_ 1

class node{
public:

    bool b_Situ;//def 0 road, 1 wall
    int count_By[5]={}; // def 0 right, 1 up, 2 left, 3 down, 4 path
    void operator<<(char &tmp)
    {
        if(tmp=='X')
        {
            this->b_Situ = 1;
        }
        else 
        {
            b_Situ = 0;
        }
    }
    friend ostream& operator<<(ostream& s, node &tmp)
    {
        if(tmp.b_Situ==1)
        {
            s << 'X';
        }
        else 
        {
            s << ".";
        }
    }

};
class wall{
public:
    int n, m;
    vector<vector<node>> maze_Node;
    int end_X, end_Y;
    wall(int t_R,int t_C,fstream &f_Tmp)
    {
        n=t_R;
        m=t_C;
        end_X = n - 2;
        end_Y = m - 2;
        maze_Node.resize(n);
        for (int i = 0; i < n;++i)
        {
            maze_Node[i].resize(m);
        }
        char tmp;
        for (int i = 0; i < n;++i)
        {
            for (int j = 0; j < m;++j)
            {
                f_Tmp >> tmp;
                maze_Node[i][j]<<tmp;
            }
        }
    }


};



#endif
