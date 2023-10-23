#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline-limit=10000,section-anchors,profile-values,profile-reorder-functions,tracer,vpt,rename-registers,move-loop-invariants,unswitch-loops,function-sections,data-sections,branch-target-load-optimize,btr-bb-exclusive")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
using namespace std;

int multipleByValue(int count) {
    count *= count;
    return count;
}

void multipleByReference(int &count) {
    count *= count;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int count = 6;
    int count2 = 15;
    cout << "count = " << count << "\n";
    cout << "count2 = " << count2 << "\n";
    
    return 0;
}