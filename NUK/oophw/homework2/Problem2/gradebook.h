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
    virtual void displayMessage();
private:
    string courseBook;
    string professor;
};