#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    float n1=n-1;
    float n2=n-2;
    float x = n2 / n1;
    cout << 1.0f - x * x << "\n";
}