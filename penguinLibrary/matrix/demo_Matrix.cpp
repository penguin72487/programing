#include<iostream>
#include"matrix.hpp"
using namespace std;

long long fib(long long n)
{
    matrix<long long> A(2, 2);A= {1, 1, 1, 0};
    matrix<long long> B(2, 2) = {1, 1, 1, 0};
    if(n==0)
    {
        return 0;
    }
    if(n==1)
    {
        return 1;
    }
    n -= 2;
    while(n)
    {
        if(n&1)
        {
            A *= B;
        }
        B *= B;
        n>>=1;
    }
    return A[0][0];
}
int main(){
    int n;
    cin >> n;
    cout << fib(n) << "\n";
}