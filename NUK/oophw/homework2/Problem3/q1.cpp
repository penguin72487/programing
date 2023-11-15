#include<bits/stdc++.h>
#include"override.cpp"
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline-limit=10000,section-anchors,profile-values,profile-reorder-functions,tracer,vpt,rename-registers,move-loop-invariants,unswitch-loops,function-sections,data-sections,branch-target-load-optimize,btr-bb-exclusive")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#define endl "\n"
using namespace std;
int main(){
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    GradeBook gradeBook1("CS101 Introduction to C++ Programming");
    GradeBook gradeBook2("CS102 Data Structures in C++");
    GradeBook gradeBook3("CS103 Graph, tree and set");
    gradeBook1.setProfessor("Prof. Chen");
    gradeBook2.setProfessor("Prof. Lin");
    gradeBook3.setProfessor("Prof. Wang");
    gradeBook1.setDate(1, 1, 2021);
    gradeBook2.setDate(2, 2, 2021);
    gradeBook3.setDate(-7, 3, 2021);
    
    gradeBook1.displayMessage();
    gradeBook2.displayMessage();
    gradeBook3.displayMessage();

    
    return 0;
}