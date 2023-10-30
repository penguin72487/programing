#include<bits/stdc++.h>
#include"sales.cpp"
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline-limit=10000,ection-anchors,profile-values,profile-reorder-functions,tracer,vpt,rename-registers,move-loop-invariants,unswitch-loops,function-sections,data-sections,branch-target-load-optimize,btr-bb-exclusive")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#define endl "\n"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    SalesPerson s;
    cout << s.totalAnnualSales() << endl;


    return 0;
}