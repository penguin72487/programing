#include <iostream>
#include <string>

using namespace std;
class GradeBook {
public:
    GradeBook(string name);
    virtual void setGradeBook(string name);
    virtual string getCourseBook();
    virtual void displayMessage();
private:
    string courseBook;
};