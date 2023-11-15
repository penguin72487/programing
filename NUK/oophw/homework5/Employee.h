
// Fig. 17.19: Employee.h
// Employee class definition. 
// Member functions defined in Employee.cpp. 
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string> 
#include "Date.cpp" // include Date class definition
using namespace std; 

class Employee
{
public: 
    Employee( const string &first, const string &last,
              Date &birth,Date &hire );
    void print() const; 
    ~Employee(); // provided to confirm destruction order

private:  
    string firstName; 
    string lastName; 
    const Date birthDate; // composition: member object
    const Date hireDate; // composition: member object
}; // end class Employee

#endif
