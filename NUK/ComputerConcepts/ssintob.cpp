#include<iostream>
#include<sstream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    stringstream ss;
    ss << hex << n;
    cout<<ss.str()<<"\n";
    return 0;
}