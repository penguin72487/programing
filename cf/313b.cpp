#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline-limit=10000,section-anchors,profile-values,profile-reorder-functions,tracer,vpt,rename-registers,move-loop-invariants,unswitch-loops,function-sections,data-sections,branch-target-load-optimize,btr-bb-exclusive")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
// #pragma comment(linker, "/stack:200000000")
#define endl "\n"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    string s;
    cin >> s;
    vector<int> a;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1]){
            a.push_back(1);
        }
        else{
            a.push_back(0);
        }
    }
    partial_sum(a.begin(), a.end(), a.begin());
    int q;
    cin >> q;
    int l, r;
    for (int i = 0; i < q; i++){
        cin >> l >> r;
        cout << a[r-2] - a[l-1] << endl;

    }
        return 0;
}