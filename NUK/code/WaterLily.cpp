#include<iostream>
#include<iomanip>
using namespace std;

int main() {
    
    // cin.tie(0)->sync_with_stdio(0);
    // cout.tie(0);

    float h = 0, l = 0;
    float x = 0;

    cin >> h >> l;
    
    x = (l * l - h * h) / 2*h;

    printf("%.3f\n",x);
    cout << setprecision(4) << 3.1415926 << "\n";

    return 0;
}