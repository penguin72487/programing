#include<iostream>
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
        bool b[n];
        bool zero=0;
        bool one=0;
        bool sorted=1;
        cin >> a[0];
        for(int i = 1; i < n; i++){
            cin >> a[i];
            if(a[i]<a[i-1])
            {
                sorted = 0;
            }
        }
        for(int i = 0; i < n; i++){
            cin>>b[i];
            zero = (zero | (b[i]^1));
            one = (one | b[i]);
        }
        if(sorted)
        {
            cout << "Yes\n";
        }
        else if(one&&zero)
        {
            cout<<"Yes\n";
        } 
        else 
        {
            cout<<"No\n";
        }


    }
    return 0;
}