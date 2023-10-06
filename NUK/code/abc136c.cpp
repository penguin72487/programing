#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin>>n;
    long long a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int count_O=0;
    for (int i = 1; i < n;++i)
    {
        if(a[i-1]>a[i]){
            count_O++;
            if(a[i-1]-a[i]>1){
                cout<<"No\n";
                return 0;
            }
        }
    }
    cout<<"Yes\n";
        return 0;
}