// CommissionEmployee.cpp
#include "CommissionEmployee.h"
#include <iostream>
using namespace std;

// Constructor
CommissionEmployee::CommissionEmployee(const string &first, const string &last, 
                                       const string &ssn, double sales, double rate) 
    : firstName(first), lastName(last), socialSecurityNumber(ssn), 
      grossSales(sales), commissionRate(rate) {}

// Setters
void CommissionEmployee::setFirstName(const string &first) {
    firstName = first;
}
void CommissionEmployee::setLastName(const string &last) {
    lastName = last;
}
void CommissionEmployee::setSocialSecurityNumber(const string &ssn) {
    socialSecurityNumber = ssn;
}
void CommissionEmployee::setGrossSales(double sales) {
    grossSales = sales;
}
void CommissionEmployee::setCommissionRate(double rate) {
    commissionRate = rate;
}

// Getters
string CommissionEmployee::getFirstName() const {
    return firstName;
}
string CommissionEmployee::getLastName() const {
    return lastName;
}
string CommissionEmployee::getSocialSecurityNumber() const {
    return socialSecurityNumber;
}
double CommissionEmployee::getGrossSales() const {
    return grossSales;
}
double CommissionEmployee::getCommissionRate() const {
    return commissionRate;
}

// earnings
double CommissionEmployee::earnings() const {
    return getCommissionRate() * getGrossSales();
}

// print
void CommissionEmployee::print() const {
    cout << "commission employee: " << getFirstName() << ' ' << getLastName() 
         << "\nsocial security number: " << getSocialSecurityNumber() 
         << "\ngross sales: " << getGrossSales() 
         << "\ncommission rate: " << getCommissionRate() << endl;
}
