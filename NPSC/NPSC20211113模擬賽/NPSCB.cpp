#include<iostream>
using namespace std;
int main()
{
    int x;
    cin >> x;
    if(x==0)
    {
        cout << "0 0\n";
    }
    else if(x>1000)
    {
        cout << "1000 " << x - 1000 << "\n";
    }
    else
    {
        cout <<x-1<< " 1\n";
    }
}