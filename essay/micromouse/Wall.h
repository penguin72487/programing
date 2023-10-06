#include<iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
#ifndef _WALL_H_
#define _WALL_H_ 1
float q_sqrt(unsigned long long x);
class node;
class maze_Wall;
class wall{
public:
    int count_Wall=0;
    float f_Odistance=0.0f;
    node *pa=nullptr;//if nullptr mean note wall if 1 mean is wall
};
class node{
public:
    int i_X, i_Y;
    bool b_Situ;//def 0 road, 1 wall
    int count_Node=0;
    float f_Odistance;
    wall w_direct[4]; // def 0 right, 1 up, 2 left, 3 down,
    maze_Wall *pa=nullptr;
    void operator<<(char &tmp)
    {
        if(tmp=='X')
        {
            b_Situ = 1;
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
        return s;
    }

};
class maze_Wall{
public:
    int n, m;
    vector<vector<node>> maze_Node;
    int end_X, end_Y;
    int abs_direction=1; // def 0 right, 1 up, 2 left, 3 down,
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
                maze_Node[i][j].pa = this;
                maze_Node[i][j].i_X = i;
                maze_Node[i][j].i_Y = j;
                maze_Node[i][j].f_Odistance = q_sqrt((end_X-i)*(end_X-i)+(end_Y-j)*(end_Y-j));
                if(maze_Node[i][j].b_Situ==1)
                {
                    float v_LocX[4]{0,-0.5f,0,0.5f};
                    float v_LocY[4]{0.5f, 0, -0.5f, 0};
                    for(int k=0; k<4; k++)
                    {
                        maze_Node[i][j].w_direct[k].f_Odistance = q_sqrt((end_X - i+v_LocX[k]) * (end_X - i+v_LocX[k]) + (end_Y - j+v_LocY[k]) * (end_Y - j+v_LocY[k]));
                    }

                }
            }
        }
    }
    friend ostream& operator<<(ostream& s, maze_Wall &tmp)
    {
        for (int i = 0; i < tmp.n;++i)
        {
            for(int j = 0; j < tmp.m;++j)
            {
                if (tmp.maze_Node[i][j].b_Situ == 1)
                {
                    s << 'X';
                }
                else
                {
                    s << ".";
                }
            }
            s<< "\n";
        }
        
        for (int i = 0; i < tmp.n;++i)
        {
            for(int j = 0; j < tmp.m;++j)
            {
                s<<setw(7)<< fixed << setprecision(4)<<tmp.maze_Node[i][j].f_Odistance<<" ";
            }
            s<< "\n";
        }
        

        return s;
    }

};
float q_sqrt(unsigned long long x) { 
	if(x == 0) return 0; 
	float result = x; 
	float xhalf = 0.5f*result; 
	int i = *(int*)&result; 
	i = 0x5f375a86- (i>>1); // what the fuck? 
	result = *(float*)&i; 
	result = result*(1.5f-xhalf*result*result); // Newton step, repeating increases accuracy 
	result = result*(1.5f-xhalf*result*result); 
	return 1.0f/result; 
}


#endif
