#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, m, op;
        cin>>n>>m>>op;
        op--;
        vector<pair<int,char>> l(m);
        for(auto &[a,b]:l){
            cin>>a>>b;
        }
        set<int> q;
        q.insert(op);
        for(auto [dist, dir]:l){
            set<int> q_Next;
            for(auto i:q){
                int cur_R = i+dist;
                int cur_L = i-dist;
                cur_R = (cur_R+n)%n;
                cur_L = (cur_L+n)%n;
                if(dir=='0'){
                    q_Next.insert(cur_R);
                }
                else if(dir=='1'){
                    q_Next.insert(cur_L);
                }
                else{
                    q_Next.insert(cur_R);
                    q_Next.insert(cur_L);
                }
            }
            q = q_Next;
        }
        cout<<q.size()<<endl;
        for(auto i:q){
            cout<<i+1<<" ";
        }
        cout<<endl;

    }
    return 0;
}