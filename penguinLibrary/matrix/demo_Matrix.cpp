#include<iostream>
#include"matrix.hpp"
using namespace std;

unsigned long long fib(unsigned long long n)
{
    matrix<unsigned long long> A(2, 2);A= {1, 1, 1, 0};
    matrix<unsigned long long> B(2, 2,{1, 1, 1, 0});
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
    matrix<long long> A(2,2,{{2, 1}, {3, 9}});
    A = {{2, 1}, {3, 9}};
    cout<<A<<"\n";
}