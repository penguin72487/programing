#include<iostream>
using namespace std;
int f(int n)
{
    if(n<10)
    {
        return n;
    }
    int sum = 0;
    while(n)
    {
        sum += n % 10;
        n /= 10;
    }
    return f(sum);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    while(cin>>n&&n!=0)
    {
        cout << f(n)<<"\n";
    }
    return 0;
}