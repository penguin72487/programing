#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(auto &i:a){
            cin>>i;
        }
        for(int i=0;i<n-2;i++){
            if(a[i]<0){
                cout<<"NO"<<endl;
                goto end;
            }
            int ratio = a[i];
            a[i] = 0;
            a[i+1]-=2*ratio;
            a[i+2]-=ratio;
        }
        if(*max_element(a.begin(), a.end())==0&&*min_element(a.begin(), a.end())==0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        end:;
    }
    return 0;
}

/*
1
4
1 1 1 1


*/