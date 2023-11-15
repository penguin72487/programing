#include <iostream>
#include <string>
#include <tuple>
using namespace std;
class GradeBook {
public:
    GradeBook(string name);
    virtual void setGradeBook(string name);
    virtual string getCourseBook();

    virtual void setProfessor(string name);
    virtual string getProfessor();
    
    virtual void setDate( int month, int day, int year);
    virtual void setDate(tuple<int, int, int> date);
    virtual void setDay(int day);
    virtual void setMonth(int month);
    virtual void setYear(int year);
    virtual int getDay();
    virtual int getMonth();
    virtual int getYear();
    virtual tuple<int, int, int> getDate();


    virtual void displayMessage();
private:
    string courseBook;
    string professor;
    tuple<int, int, int> date;//month, day, year
};