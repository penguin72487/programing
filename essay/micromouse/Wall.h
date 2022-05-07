#include<iostream>
#include <fstream>
#include <vector>
using namespace std;
#ifndef _WALL_H_
#define _WALL_H_ 1
class node;
class wall{
public:
    int count_Wall=0;
    node *pa=nullptr;//if nullptr mean note wall if 1 mean is wall
};
class node{
public:
    int i_X, i_Y;
    bool b_Situ;//def 0 road, 1 wall
    int count_Node=0;
    wall *w_direct[4]; // def 0 right, 1 up, 2 left, 3 down, 4 path totle
    void operator<<(char &tmp)
    {
        if(tmp=='X')
        {
            b_Situ = 1;
            for(int i=0; i<4; i++)
            {
                w_direct[i]->pa = this;
            }
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
class maze_Wall{
public:
    int n, m;
    vector<vector<node>> maze_Node;
    int end_X, end_Y;
    maze_Wall(fstream &f_Tmp)
    {
        f_Tmp >> n;
        f_Tmp >> m;
        f_Tmp>>end_X;
        f_Tmp>>end_Y;
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
