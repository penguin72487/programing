#include<iostream>
#include<set>
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        set<int> l;
        bool flag = 0;
        for(int i=0,tmp; i<n; i++){
            cin >> tmp;
            if(l.find(tmp) != l.end()){
                flag = true;
                continue;
            }
            l.insert(tmp);
        }
        cout<<(flag?"NO\n":"YES\n");

    }
    return 0;
}