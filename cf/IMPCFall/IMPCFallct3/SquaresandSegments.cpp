#include<iostream>
#include<cmath>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int segment = sqrt(n);
    int now = segment * segment;
    cout << 2 * segment + (n - now+segment-1) / (segment)<<"\n";
    return 0;
}