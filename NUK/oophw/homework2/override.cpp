#include<bits/stdc++.h>
#include "gradebook.h"
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline-limit=10000,section-anchors,profile-values,profile-reorder-functions,tracer,vpt,rename-registers,move-loop-invariants,unswitch-loops,function-sections,data-sections,branch-target-load-optimize,btr-bb-exclusive")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma comment(linker, "/stack:200000000")
#define endl "\n"
using namespace std;
GradeBook::GradeBook(string name) : courseBook(name) {}

void GradeBook::setGradeBook(string name) {
    courseBook = name;
}

string GradeBook::getCourseBook() {
    return courseBook;
}

void GradeBook::displayMessage() {
    cout << "Course Book: " << getCourseBook() << endl;
}