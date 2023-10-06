#include<iostream>
using namespace std;
void print_address(int*& n)
{
    cout << n << "\n";
    (*n)++;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n = 99;
    int *p = &n;
    cout<<p<<"\n";
    print_address(p);
    cout<<n<<"\n";

    return 0;
}