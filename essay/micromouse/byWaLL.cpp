#include <iostream>
#include <fstream>
#include "Wall.h"
using namespace std;
ofstream path("maze0Path.txt");
fstream f("maze0.txt");

int main()
{
    cout.tie(0);
    cin.tie(0)->sync_with_stdio(0);
    int n, m;
    f >> n >> m;
    wall A(n, m, f);

path.close();
f.close();
}
