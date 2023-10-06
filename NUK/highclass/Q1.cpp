#include<iostream>
using namespace std;
void swap(long long& a,long long& b)
{
    a^=b^=a^=b;
}
long double fibC(long long* n)
{
    cout << n << "\n";
    long long fib[] = {0, 1};
    for(int i = 0; i < *n; i++)
    {
        swap(fib[0], fib[1]);
        fib[1] = fib[0] + fib[1];
    }
    return (long double)((long double)fib[1]/(long double)fib[0]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    long long n = 91;
    cout << &n << "\n";
    cout << fibC(&n)<<"\n";

    return 0;
}