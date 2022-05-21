#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
    long double ans=0;
    //long double a=1;
    long double p=0.02; //now probability
    long double ark = 1;
    for (int i = 0; i < 50;++i){
        ans += p*ark;
        ark *= (1 - p);
    }
    cout << ark << "\n";
    cout << ans << "\n";
    for (int i = 0; i < 50;++i){
        p += 0.02;
        ans += p*ark;
        ark *= (1 - p);
        cout << i + 51 << "\n";
        cout <<"ark: " << ark << "\n";
        cout <<"ans: " << ans << "\n";
    }
    cout << ark << "\n";
    cout << ans << "\n";
}