#include<iostream>
using namespace std;
int main(){
    int t;
    cout << "please input number of second: ";
    cin >> t; // 
    cout << t / 3600<<"H ";
    t%= 3600;
    cout << t / 60<<"M ";
    t %= 60;
    cout << t << "S\n";
    return 0;
}