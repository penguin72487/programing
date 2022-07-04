#include <iostream>
#include<numeric>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t-->0){
        int n;
        cin >> n;
        int tree[n];
        for(int i=0; i<n; i++){
            cin>>tree[i];
        }
        adjacent_difference(tree,tree+n,tree);
        
    }
}