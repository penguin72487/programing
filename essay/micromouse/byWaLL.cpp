#include <iostream>
#include <fstream>
#include <queue>
#include "Wall.h"
using namespace std;
ofstream path("maze0Path.txt");
fstream f("maze0.txt");
class priorty_Wall{
    public:
        bool operator()(node &n_A,node &n_B)
        {
          
        }
};
void solution(maze_Wall &A)
{
    
}
int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    f >> n >> m;
    maze_Wall A(f);

    path.close();
    f.close();
}
