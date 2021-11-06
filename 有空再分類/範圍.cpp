#include <iostream>
#include <climits>

using namespace std;

int main()
{

    cout << "int is "       <<sizeof(int)       << " bytes." << endl;
    cout << "short is "     <<sizeof(short)     << " bytes." << endl;
    cout << "long is "      <<sizeof(long)      << " bytes." << endl;
    cout << "long long is " <<sizeof(long long) << " bytes." << endl;
    cout << endl;


    cout << "*****Maximum values:*****" << endl;
    cout << "int: "                 << INT_MAX          << endl;
    cout << "short: "               << SHRT_MAX         << endl;
    cout << "long: "                << LONG_MAX         << endl;
    cout << "long long: "           << LLONG_MAX        << endl;
    cout << "long long: "           << LONG_LONG_MAX    << endl;//和上一個相同
    cout << "char: "                << CHAR_MAX         << endl;
    cout << "signed char: "         << SCHAR_MAX        << endl;
    cout << "unsigned char: "       << CHAR_MAX         << endl;
    cout << "unsigned short: "      << USHRT_MAX        << endl;
//    cout << "unsigned int: "        << UNIT_MAX         << endl;//報錯
    cout << "unsigned long: "       << ULONG_MAX        << endl;
    cout << "unsigned long long: "  << ULLONG_MAX       << endl;
    cout << "unsigned long long: "  << ULONG_LONG_MAX   << endl;//和上一個相同
    cout << endl;


    cout << "*****Minimum values:*****" << endl;
    cout << "int: "         << INT_MIN          << endl;
    cout << "short: "       << SHRT_MIN         << endl;
    cout << "long: "        << LONG_MIN         << endl;
    cout << "long long: "   << LLONG_MIN        << endl;
    cout << "long long: "   << LONG_LONG_MIN    << endl;//和上一個相同
    cout << "char: "        << CHAR_MIN         << endl;
    cout << "signed char: " << SCHAR_MIN        << endl;
    cout << endl;


    cout<<"Bits per byte = "<<CHAR_BIT<<endl;


    return 0;
}
