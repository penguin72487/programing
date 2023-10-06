#include <iostream>
#include <fstream>
#include <queue>
#include <list>
#include <vector>
#include <iomanip>
#include "Wall.h"
using namespace std;
ofstream path("maze0Path.txt");
fstream f("maze0.txt");
class prior_Rul{
    bool operator()(wall a, wall b)
    {
        if(a.count_Wall==b.count_Wall)
        {
            if(a.f_Odistance==b.f_Odistance)
            {
                if(a.pa->count_Node==b.pa->count_Node)
                {
                    if(a.pa->f_Odistance==b.pa->f_Odistance)
                    {
                        return 0;
                    }
                    else
                    {
                        return (a.pa->f_Odistance < b.pa->f_Odistance);
                    }
                }
                else
                {
                    return (a.pa->count_Node < b.pa->count_Node);
                }
            }
            else
            {
                return (a.f_Odistance < b.f_Odistance);
            }
        }
        else
        {
            return (a.count_Wall < b.count_Wall);
        }
    }
};
void solution(wall &A)
{
    priority_queue<wall, vector<wall>, prior_Rul> stl;
}
int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    maze_Wall A(f);
    path << A << "\n";

    path.close();
    f.close();
}
