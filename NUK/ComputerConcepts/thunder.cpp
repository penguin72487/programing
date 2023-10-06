#include<iostream>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    for (int i = 32; i < 100;++i){
        int a = i * i;
        int s = a / 100 + a % 100;
        if(s*s ==a)
        {
            cout << a << "\n";
        }
    }
        return 0;
}