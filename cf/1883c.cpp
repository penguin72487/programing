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
        vector<int> a(n);
        for(auto& it:a){
            cin>>it;
        }
        sort(a.begin(), a.end());
        map<int, int> mp;
        for(int i=2;i*i<=k*k;i++){
            if(k%i==0){
                mp[i]=0;
                while(k%i==0){
                    mp[i]++;
                    k/=i;
                }
            }
        }
        if(k>1){
            mp[k]=1;
        }


        
    }
    return 0;
}