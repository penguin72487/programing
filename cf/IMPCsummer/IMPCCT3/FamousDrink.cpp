#include <iostream>
#include <algorithm>
using namespace std;
int main(){
cin.tie(0)->sync_with_stdio(0);
cout.tie(0);
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int q;
    cin >> q;
    while(q--){
        int t;
        cin >> t;
        cout << upper_bound(arr, arr + n, t)-arr << " \n";
    }

    return 0;
}