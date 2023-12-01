// Fig. 19.8: BasePlusCommissionEmployee.cpp
// Class BasePlusCommissionEmployee member-function definitions.
#include <iostream>
#include "BasePlusCommissionEmployee.h"
using namespace std;

// constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(
    const string &first, const string &last, const string &ssn,
    double sales, double rate, double salary )
{
    firstName = first; // should validate
    lastName = last; // should validate
    socialSecurityNumber = ssn; // should validate
    setGrossSales(sales); // validate and store gross sales
    setCommissionRate(rate); // validate and store commission rate
    setBaseSalary(salary); // validate and store base salary
} // end BasePlusCommissionEmployee constructor

// set first name
void BasePlusCommissionEmployee::setFirstName(const string &first) {
    firstName = first; // should validate
} // end function setFirstName

// ... (其他成員函數的實作)

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = (salary < 0.0) ? 0.0 : salary;
} // end function setBaseSalary

// return base salary
double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
} // end function getBaseSalary

// calculate earnings
double BasePlusCommissionEmployee::earnings() const {
    return baseSalary + (commissionRate * grossSales);
} // end function earnings

// print BasePlusCommissionEmployee object
void BasePlusCommissionEmployee::print() const {
    cout << "base-salaried commission employee: " << firstName << ' '
         << lastName << "\nsocial security number: " << socialSecurityNumber
         << "\ngross sales: " << grossSales
         << "\ncommission rate: " << commissionRate
         << "\nbase salary: " << baseSalary;
} // end function print
