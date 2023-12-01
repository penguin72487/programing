#include <iostream>
#include <iomanip>
#include "time.h"
using namespace std;

Time::Time(int hr, int min, int sec) {
    setTime(hr, min, sec);
}

void Time::setTime(int h, int m, int s) {
    setHour(h);
    setMinute(m);
    setSecond(s);
    totalSeconds(h, m, s);
}

void Time::setHour(int h) {
    h = (h >= 0 && h < 24) ? h : 0; // validate hour
    int m = getMinute();
    int s = getSecond();
    secondsSinceMidnight = totalSeconds(h, m, s);
}

void Time::setMinute(int m) {
    m = (m >= 0 && m < 60) ? m : 0; // validate minute
    int h = getHour();
    int s = getSecond();
    secondsSinceMidnight = totalSeconds(h, m, s);
}

void Time::setSecond(int s) {
    s = (s >= 0 && s < 60) ? s : 0; // validate second
    int h = getHour();
    int m = getMinute();
    secondsSinceMidnight = totalSeconds(h, m, s);
}

int Time::getHour() const {
    return secondsSinceMidnight / 3600;
}

int Time::getMinute() const {
    return (secondsSinceMidnight % 3600) / 60;
}

int Time::getSecond() const {
    return secondsSinceMidnight % 60;
}

void Time::printUniversal() const {
    cout << setfill('0') << setw(2) << getHour() << ":"
         << setw(2) << getMinute() << ":" << setw(2) << getSecond();
}

void Time::printStandard() const {
    int hour = getHour();
    cout << ((hour == 0 || hour == 12) ? 12 : hour % 12)
         << ":" << setfill('0') << setw(2) << getMinute()
         << ":" << setw(2) << getSecond() << (hour < 12 ? " AM" : " PM");
}

int Time::totalSeconds(int h, int m, int s) const {
    return h * 3600 + m * 60 + s;
}
