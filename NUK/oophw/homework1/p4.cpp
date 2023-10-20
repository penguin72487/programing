#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline-limit=10000,section-anchors,profile-values,profile-reorder-functions,tracer,vpt,rename-registers,move-loop-invariants,unswitch-loops,function-sections,data-sections,branch-target-load-optimize,btr-bb-exclusive")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
//using namespace std;
using std::cin;
using std::cout;
template <typename T>
void swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    int a = 1, b = 2;
    cout<<a<<" "<<b<<"\n";
    swap(a, b);
    cout<<a<<" "<<b<<"\n";
    char c = 'a', d = 'b';
    cout<<c<<" "<<d<<"\n";
    swap(c, d);
    cout<<c<<" "<<d<<"\n";
    float e = 1.1, f = 2.2;
    cout<<e<<" "<<f<<"\n";
    swap(e, f);
    cout<<e<<" "<<f<<"\n";
    
    
    return 0;
}