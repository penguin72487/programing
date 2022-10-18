#include<iostream>
using namespace std;
void gray(int now,int n,string s){
    if(n==now)
    {
        cout << s<<"\n";
        return;
    }
    gray(now+1,n,"0"+s);
    gray(now+1,n,"1"+s);
    
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    gray(1, n, string("0"));

    return 0;
}