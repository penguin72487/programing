#include<iostream>
using namespace std;
string intob(long long n){
    string s="";
    if(n>0)
    {
        s = intob(n >> 1);
        s.push_back(n%2+'0');
        return  s;
    }
    //s += "0";
    return s ;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cout<<intob(10)<<"\n";
    return 0;
}