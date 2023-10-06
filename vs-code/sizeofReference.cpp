#include<iostream>
using namespace std;
int main()
{
    int n = 10;
    //int a[n][n];
    int **b = new int *[10];
    for (int i = 0; i < n;++i)
    {
        b[i] = new int[10];
    }
    cout << sizeof(int**) << "\n";
    for (int i = 0; i < n;++i)
    {
        delete [] b[i];
    }
    delete[] b;
}