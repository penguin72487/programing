#include<iostream>
using namespace std;
int main(){
    int xor_Sum = 0;
    for(int i = 0,tmp; i <11;++i)
    {
        cout << i+1 << "th interger: ";
        cin >> tmp;
        xor_Sum^=tmp;
    }
    cout << xor_Sum << "\n";
    return 0;
}