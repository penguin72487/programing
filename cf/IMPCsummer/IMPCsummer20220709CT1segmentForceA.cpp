#include<iostream>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    ++n;
    //long double rad= (n / 2.0);
    if(n==0)
    {
        cout << 0 << "\n";
    }
    else if(n&1)
    {
        cout << n << "\n";
    }
    else
    {
        cout<<(n>>1) << "\n";
    }

}