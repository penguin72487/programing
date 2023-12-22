// fig20_06.cpp
// Introducing polymorphism, virtual functions and dynamic binding.
#include <iostream>
#include <iomanip>
#include "CommissionEmployee.cpp"
#include "BasePlusCommissionEmployee.cpp"
using namespace std;

int main() {
    // create base-class object
    CommissionEmployee commissionEmployee("Sue", "Jones", "222-22-2222", 10000, .06);

    // create base-class pointer
    CommissionEmployee *commissionEmployeePtr = nullptr;

    // create derived-class object
    BasePlusCommissionEmployee basePlusCommissionEmployee("Bob", "Lewis", "333-33-3333", 5000, .04, 300);

    // create derived-class pointer
    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = nullptr;

    // set floating-point output formatting
    cout << fixed << setprecision(2);

    // output objects using static binding
    cout << "Invoking print function on base-class and derived-class\nobjects with static binding\n";
    commissionEmployee.print();
    cout << "\n";
    basePlusCommissionEmployee.print();
    cout << "\n";

    // output objects using dynamic binding
    cout << "Invoking print function on base-class and derived-class\nobjects with dynamic binding\n";
    // base-class pointer to base-class object
    commissionEmployeePtr = &commissionEmployee;
    cout << "Calling virtual function print with base-class pointer\nto base-class object invokes base-class print function:\n";
    commissionEmployeePtr->print();
    cout << "\n";

    // derived-class pointer to derived-class object
    basePlusCommissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "Calling virtual function print with derived-class pointer\nto derived-class object invokes derived-class print function:\n";
    basePlusCommissionEmployeePtr->print();
    cout << "\n";

    // base-class pointer to derived-class object
    commissionEmployeePtr = &basePlusCommissionEmployee;
    cout << "Calling virtual function print with base-class pointer\nto derived-class object invokes derived-class print function:\n";
    commissionEmployeePtr->print();
    cout << "\n";

    return 0;
}
