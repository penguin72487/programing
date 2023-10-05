#include <iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int a;
    cin>>a;
    cout <<( a |(1ull<<31))<< "\n";

    return 0;
}