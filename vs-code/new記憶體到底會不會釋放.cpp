#include<iostream>
using namespace std;
int main()
{
    cout.tie(0)->sync_with_stdio(0);
    for (int i = 0; i < 2147483647;++i)
    {
        cout << i << " ";
        int *tmp = new int[1000000];
        tmp[1] = 1;
    }
}