#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    long double h, l;
    cin >> h >> l;
    cout<<fixed<<setprecision(8)<< (long double) abs((l+h)*(l-h)/(2*h))<<"\n";
}