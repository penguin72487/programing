#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[n];
        int b[n];
        //int sum = 0;
        int num = 0;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<n; i++){
            
        }
        if(num==0)
        {
            cout << "0 0\n";
        }
        else {
            cout << *max_element(b,b+n)<<" "<< *max_element(a, a + n) - *max_element(b, b + n) << " " << "\n";
        }
        
    }
    return 0;
}