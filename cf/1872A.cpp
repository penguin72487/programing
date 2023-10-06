#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        int diff=abs(a-b);
        cout<<diff/(c*2)+(diff%(c*2)>0)<<"\n";
    }
    return 0;
}