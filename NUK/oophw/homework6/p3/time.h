#ifndef TIME_H
#define TIME_H

class Time {
public:
    Time(int = 0, int = 0, int = 0); // default constructor

    void setTime(int, int, int); // set hour, minute, second
    void setHour(int); // set hour (after validation)
    void setMinute(int); // set minute (after validation)
    void setSecond(int); // set second (after validation)

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void printUniversal() const;
    void printStandard() const;

private:
    int secondsSinceMidnight; // total seconds since midnight

    int totalSeconds(int, int, int) const; // helper function to calculate total seconds
};

#endif
