// BasePlusCommissionEmployee.cpp
#include "BasePlusCommissionEmployee.h"
#include <iostream>
using namespace std;

// Constructor
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, 
                                                       const string &ssn, double sales, 
                                                       double rate, double salary)
    : CommissionEmployee(first, last, ssn, sales, rate), baseSalary(salary) {}

// Setter
void BasePlusCommissionEmployee::setBaseSalary(double salary) {
    baseSalary = salary;
}

// Getter
double BasePlusCommissionEmployee::getBaseSalary() const {
    return baseSalary;
}

// earnings
double BasePlusCommissionEmployee::earnings() const {
    return getBaseSalary() + CommissionEmployee::earnings();
}

// print
void BasePlusCommissionEmployee::print() const {
    CommissionEmployee::print();
    cout << "base salary: " << getBaseSalary() << endl;
}
