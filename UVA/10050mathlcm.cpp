#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int day;
        cin >> day;
        int days[day + 1];
        fill(days, days+day+1,0);
        int n;
        cin >> n;
        int a[n]; 
        for(int i=0; i<n; i++){
            cin>>a[i];
            for(int j=1; j*a[i]<=day; j++){
                days[j*a[i]] |= 1;
                if((j*a[i])%7==6||(j*a[i])%7==0)
                {
                    days[j*a[i]] &= 0;
                }
            }
        }
        cout << accumulate(days, days + day + 1, 0ll)<<"\n";
}
    return 0;
}