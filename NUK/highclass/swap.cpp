#include<iostream>
using namespace std;
void swap(int & a,int & b)
{
    a^=b^=a^=b;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int a = 3,b=3;
    swap(a, b);
    cout << a << " " << b << "\n";

    return 0;
}