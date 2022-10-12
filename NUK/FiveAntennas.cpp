#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int a[6];
    cin >> *a>>*(a+1)>>*(a+2)>>*(a+3)>>*(a+4)>>*(a+5);
    if(*(a+4)-*a>*(a+5))
    {
        cout << ":(\n";
    }
    else 
    {
        cout<<"Yay!\n";
    }

    return 0;
}