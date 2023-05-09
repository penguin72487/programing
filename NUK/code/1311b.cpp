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
        for(auto& it:a)
        {
            cin>>it;
        }
        for(auto& it:p)
        {
            cin>>it;
        }
        sort(p.begin(), p.end());
        for(auto& i:p){
            --i;
        }
        p.push_back(n);
        int op=p[0];

        for(int i=1; i<m+1; i++){
            if(p[i]>p[i-1]+1){
                sort(a.begin()+op, a.begin()+p[i-1]+2);
                op=p[i];
            }
        }
        //sort(a.begin()+op, a.begin()+op+2);
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