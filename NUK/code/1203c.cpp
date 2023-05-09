#include<bits/stdc++.h>
using namespace std;
long long gcm(long long a, long long b){
    if(b==0)
        return a;
    return gcm(b, a%b);
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int n;
    cin>>n;
    long long a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    long long ans=a[0];
    for(int i=1; i<n; i++){
        ans=gcm(ans, a[i]);
    }
    int count=0;
    for(int i=1; i<=sqrt(ans); i++){
        if(ans%i==0){
            count++;
            if(i!=ans/i)
                count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}