
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

// get first name
string BasePlusCommissionEmployee::getFirstName() const {
    return firstName;
} // end function getFirstName

// set last name
void BasePlusCommissionEmployee::setLastName(const string &last) {
    lastName = last; // should validate
} // end function setLastName

// get last name
string BasePlusCommissionEmployee::getLastName() const {
    return lastName;
} // end function getLastName

// set social security number
void BasePlusCommissionEmployee::setSocialSecurityNumber(const string &ssn) {
    socialSecurityNumber = ssn; // should validate
} // end function setSocialSecurityNumber

// get social security number
string BasePlusCommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
} // end function getSocialSecurityNumber

// set gross sales
void BasePlusCommissionEmployee::setGrossSales(double sales) {
    grossSales = sales < 0.0 ? 0.0 : sales;
} // end function setGrossSales

// get gross sales
double BasePlusCommissionEmployee::getGrossSales() const {
    return grossSales;
} // end function getGrossSales

// set commission rate
void BasePlusCommissionEmployee::setCommissionRate(double rate) {
    commissionRate = (rate > 0.0 && rate < 1.0) ? rate : 0.0;
} // end function setCommissionRate

// get commission rate
double BasePlusCommissionEmployee::getCommissionRate() const {
    return commissionRate;
} // end function getCommissionRate

// set base salary
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = salary < 0.0 ? 0.0 : salary;
} // end function setBaseSalary

// get base salary
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
