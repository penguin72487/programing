#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int n = 10,m = 10;
    int list[n][m];
    fill(*list,*(list+n)+m,10);
    for (int i = 0; i < n;++i)
    {
        for (int j = 0; j < m;++j)
        {
            cout << list[i][j] << " ";
        }
        cout << "\n";
    }
}