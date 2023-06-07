#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        if(n==1)
        {
            cout<<"YES\n";
            continue;
        }
        for(int i=0; i<(n+1)/2; i++){
            if(a[i]<i)
            {
                cout<<"NO\n";
                goto end;
            }
        }
        if(n%2==0)
        {
            if(a[n/2]<n/2&&a[n/2-1]<n/2)
            {
                cout<<"NO\n";
                goto end;
            }
        }
        for(int i=n-1; i>=n/2; i--){
            if(a[i]<n-1-i)
            {
                cout<<"NO\n"; 
                goto end;
            }
        }
        cout<<"YES\n";
        end:;
    }
    return 0;
}
/*
1
3
0 0 0
*/