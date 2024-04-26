#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        long long a, b, m;
        cin>>a>>b>>m;
        cout<<m/a + m/b+2<<endl;
    }
    return 0;
}