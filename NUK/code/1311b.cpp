#include<bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<int> a(n);
        vector<int> p(m);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        for(int i=0; i<m; i++){
            cin>>p[i];
        }
        sort(p.begin(), p.end());
        for(auto& i:p){
            --i;
        }
        int op=p[0];

        for(int i=1; i<m; i++){
            if(p[i]!=p[i-1]+1){
                
            }
        }
        sort(a.begin()+p[m-1], a.end());
        bool flag=true;
        for(int i=0; i<n-1; i++){
            if(a[i]>a[i+1]){
                flag=false;
                break;
            }
        }
        cout<<(flag?"YES":"NO")<<"\n";
    }
    return 0;
}