#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline-limit=10000,section-anchors,profile-values,profile-reorder-functions,tracer,vpt,rename-registers,move-loop-invariants,unswitch-loops,function-sections,data-sections,branch-target-load-optimize,btr-bb-exclusive")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#define endl "\n"
using namespace std;
void swap1(int* a, int* b);
void swap2(int& a, int& b);
void swap3(int& a, int& b);
void swap4(int* a, int* b);

int main(){

    int a = 1; 
    int b = 2;
    
    cout << "a=" << a << "; b=" << b << endl; 
    
    // swap by address
    swap1(&a, &b);
    cout << "a=" << a << "; b=" << b << endl;
    
    // swap by value
    swap2(a, b);
    cout << "a=" << a << "; b=" << b << endl;

    // swap by reference
    swap3(a, b);
    cout << "a=" << a << "; b=" << b << endl;

    a = 1;
    b = 2;
    // swap  pointer
    cout << "a=" << &a << "; b=" << &b << endl;
    swap4(&a, &b);
    cout << "a=" << a << "; b=" << b << endl;
    cout << "a=" << &a << "; b=" << &b << endl;



}

void swap1(int* a, int* b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

void swap2(int& a, int& b){
    int tmp = b;
    b = a; 
    a = tmp;
}

void swap3(int& a, int& b){
    int& tmp = b;
    b = a;
    a = tmp;
}

void swap4(int* a, int* b){
    int* tmp = b;
    b = a;
    a = tmp;
}