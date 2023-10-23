#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline-limit=10000,section-anchors,profile-values,profile-reorder-functions,tracer,vpt,rename-registers,move-loop-invariants,unswitch-loops,function-sections,data-sections,branch-target-load-optimize,btr-bb-exclusive")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#define endl "\n"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        map<char,int> ci_Mp;
        for(int i=0;i<n;i++){
            char c;
            cin>>c;
            ci_Mp[c]++;
        }
                int c_Odd = 0;
                for(auto i:ci_Mp){
                    c_Odd+=i.second&1;
                }
                if(c_Odd<=k+1){
                    cout<<"YES"<<endl;
                }
                else{
                    cout<<"NO"<<endl;
                }
        }
    return 0;        
}

