#include<iostream>
#include<numeric>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        long long a[n];
        for(int i=0; i<n; ++i)
        {
            cin >> a[i];
        }
        cout << abs(accumulate(a, a + n,0ll))<<"\n";
    }

    return 0;
}