#include <iostream>
#include <algorithm>
using namespace std;
int main(){
cin.tie(0)->sync_with_stdio(0);
cout.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        cout<<arr[n-1]+arr[n-2]<<"\n";
    }

return 0;
}