#include <iostream>
#include "gradebook.h"
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline-limit=10000,section-anchors,profile-values,profile-reorder-functions,tracer,vpt,rename-registers,move-loop-invariants,unswitch-loops,function-sections,data-sections,branch-target-load-optimize,btr-bb-exclusive")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
// #pragma comment(linker, "/stack:200000000")
#define endl "\n"
using namespace std;
GradeBook::GradeBook(string name) : courseBook(name){}

void GradeBook::setGradeBook(string name) {
    courseBook = name;
}
string GradeBook::getCourseBook() {
    return courseBook;
}

void GradeBook::setProfessor(string name) {
    professor = name;
}
string GradeBook::getProfessor() {
    return professor;
}

void GradeBook::setDate(int _month, int _day, int _year) {
    setMonth(_month);
    setDay(_day);
    setYear(_year);
}
void GradeBook::setDate(tuple<int, int, int> _date) {
    auto [_month, _day, _year] = _date;
    setDate(_month, _day, _year);
}
void GradeBook::setMonth(int _month) {
    if(_month > 12 || _month < 1)
        _month = 1;

    get<0>(date) = _month;
}
void GradeBook::setDay(int _day) {
    if(_day > 31 || _day < 1)
        _day = 1;

    get<1>(date) = _day;
}
void GradeBook::setYear(int _year) {
    if(_year < 1)
        _year = 1;

    get<2>(date) = _year;
}

int GradeBook::getMonth() {
    return get<0>(date);
}
int GradeBook::getDay() {
    return get<1>(date);
}
int GradeBook::getYear() {
    return get<2>(date);
}
tuple<int, int, int> GradeBook::getDate() {
    return date;
}

void GradeBook::displayMessage() {
    cout << "Course Book: " << getCourseBook() <<". This course ispresented by "<<getProfessor() <<". "<<getMonth()<<"/"<<getDay()<<"/"<<getYear()<<"."<<endl;
}