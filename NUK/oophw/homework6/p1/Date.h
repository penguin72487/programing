#include <iostream>
#ifndef DATE_H
#define DATE_H
class Date
{ 
public: 
    static const int monthsPerYear = 12; // 1-12 (January-December)
    Date( int = 1, int = 1, int = 1900 ); // default constructor
    Date(Date&);
    void print() const; // print date in month/day/year format
    ~Date(); // provided to confirm destruction order
    void nextDay();
    friend std::ostream& operator<<(std::ostream& out, const Date& d);

private: 
    int month; // 1-12 (January-December) 
    int day; // 1-31 based on month
    int year; // any year

    // utility function to check if day is proper for month and year
    int checkDay( int ) const; 
}; // end class Date

#endif