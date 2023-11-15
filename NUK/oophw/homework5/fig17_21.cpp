
// Fig. 17.21: fig17_21.cpp
// Demonstrating composition--an object with member objects. 
#include <iostream> 
#include "Employee.cpp" // Employee class definition
using namespace std; 

int main()
{
    Date birth( 7, 24, 1949 );
    Date hire( 3, 12, 1988 );
    Employee manager( "Bob", "Blue", birth, hire );

    Date birthMe(10,29,1919);
    Date hireMe(8, 7, 2004);
    Employee me("penguin", "Chien", birthMe, hireMe);
    cout << endl;
    manager.print();
    return 0;
} // end main
