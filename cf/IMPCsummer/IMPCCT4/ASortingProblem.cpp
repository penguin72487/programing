#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin >> n;
    int val[n];
    int correct_Dist[n];
    for(int i=0; i<n; i++){
        cin>>val[i];
        correct_Dist[i] = abs(i-val[i]+1);
    }
    return 0;
}
