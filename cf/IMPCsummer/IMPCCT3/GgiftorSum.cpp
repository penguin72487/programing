#include <iostream>
using namespace std;
int main(){
cin.tie(0)->sync_with_stdio(0);
cout.tie(0);

int t;
cin >> t;
while(t--){
    int n;
    cin>> n;
    int ans = 0;
    for(int i=0;i<n;i++){
        int tmp;
        cin>> tmp;
        ans|=tmp;
    }
    cout<<ans<<"\n";
}

return 0;
}