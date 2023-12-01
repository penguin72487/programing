#include <iostream>
#include "time.cpp"
using namespace std;

int main() {
    Time t1; // all arguments defaulted
    Time t2(2); // hour specified; minute and second defaulted
    Time t3(21, 34); // hour and minute specified; second defaulted
    Time t4(12, 25, 42); // hour, minute and second specified
    Time t5(27, 74, 99); // all bad values specified

    cout << "Constructed with:\n\n";
    cout << "t1: all arguments defaulted\n ";
    t1.printUniversal(); // 00:00:00
    cout << "\n ";
    t1.printStandard(); // 12:00:00 AM
    cout << "\n\n";

    cout << "t2: hour specified; minute and second defaulted\n ";
    t2.printUniversal(); // 02:00:00
    cout << "\n ";
    t2.printStandard(); // 2:00:00 AM
    cout << "\n\n";

    cout << "t3: hour and minute specified; second defaulted\n ";
    t3.printUniversal(); // 21:34:00
    cout << "\n ";
    t3.printStandard(); // 9:34:00 PM
    cout << "\n\n";

    cout << "t4: hour, minute and second specified\n ";
    t4.printUniversal(); // 12:25:42
    cout << "\n ";
    t4.printStandard(); // 12:25:42 PM
    cout << "\n\n";

    cout << "t5: all invalid values specified\n ";
    t5.printUniversal(); // 00:00:00
    cout << "\n ";
    t5.printStandard(); // 12:00:00 AM
    cout << endl;

    return 0;
}
