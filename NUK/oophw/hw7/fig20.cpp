// fig20_06.cpp
// Introducing polymorphism, virtual functions and dynamic binding.
#include <iostream>
#include <iomanip>
#include "CommissionEmployee.hpp"
#include "BasePlusCommissionEmployee.hpp"
#include <vector>
using namespace std;
void virtualViaPointer(const CommissionEmployee * const); // prototype
void virtualViaReference(const CommissionEmployee &); // prototype
int main() {
    // create base-class object
    cout << fixed << setprecision(2);
    CommissionEmployee commissionEmployee("Sue", "Jones", "222-22-2222", 10000, .06);
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);
    // output objects using static binding

    commissionEmployee.print(); // static binding
    cout << "\nearned $" << commissionEmployee.earnings() << "\n\n";
    basePlusCommissionEmployee.print(); // static binding
    cout << "\nearned $" << basePlusCommissionEmployee.earnings() << "\n\n";
    
    vector<CommissionEmployee *> employees(2);
    employees[0] = &commissionEmployee;
    employees[1] = &basePlusCommissionEmployee;
    cout << "Virtual function calls made off base-class pointers:\n\n";
    // call virtualViaPointer to print each CommissionEmployee's information and earnings using dynamic binding
    cout << "Virtual function calls made off base-class pointers:\n\n";
    // call virtualViaPointer to print each CommissionEmployee's information and earnings using dynamic binding
    for (const CommissionEmployee *employeePtr : employees) {
        virtualViaPointer(employeePtr);
    }
    // call virtualViaReference to print each CommissionEmployee's information and earnings using dynamic binding
    cout << "Virtual function calls made off base-class references:\n\n";
    // call virtualViaReference to print each CommissionEmployee's information and earnings using dynamic binding
    for (const CommissionEmployee *employeePtr : employees) {
        virtualViaReference(*employeePtr);
    }


    return 0;
}
// call CommissionEmployee virtual functions print and earnings off a base-class pointer using dynamic binding
void virtualViaPointer(const CommissionEmployee * const baseClassPtr) {
    baseClassPtr->print();
    cout << "\nearned $" << baseClassPtr->earnings() << "\n\n";
}
// call CommissionEmployee virtual functions print and earnings off a base-class reference using dynamic binding
void virtualViaReference(const CommissionEmployee &baseClassRef) {
    baseClassRef.print();
    cout << "\nearned $" << baseClassRef.earnings() << "\n\n";
}
