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
        string s;
        cin>>s;
        vector<int> v(4);
        for(int i=0;i<s.size();i++){
            v[i]=s[i]-'0';
            if(v[i]==0)v[i]=10;
        }
        int ans = 3;
        adjacent_difference(v.begin(),v.end(),v.begin());
        for(auto i:v){
            ans+=abs(i);
        }
        cout<<ans<<endl;
    }
    return 0;
}