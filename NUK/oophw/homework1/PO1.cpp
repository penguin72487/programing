#include <bits/stdc++.h>
using namespace std;

const int BUFFER_SIZE = 1 << 20;
char buffer[BUFFER_SIZE];
int position = 0;

inline void flush() {
    fwrite(buffer, 1, position, stdout);
    position = 0;
}

inline void print(const char* str) {
    for (int i = 0; str[i]; ++i) {
        if (position == BUFFER_SIZE) {
            flush();
        }
        buffer[position++] = str[i];
    }
}

inline void print(long long x) {
    char buf[20];
    int len = 0;
    while (x) {
        buf[len++] = '0' + x % 10;
        x /= 10;
    }
    for (int i = len - 1; i >= 0; --i) {
        if (position == BUFFER_SIZE) {
            flush();
        }
        buffer[position++] = buf[i];
    }
}

#define cube_macro(x) x * x * x  // macro 

long long cube_regular(const long long& s) { return s * s * s; } // function
inline long long cube_inline(const long long& s) { return s * s * s; } //inline function

double diffclock(clock_t& clock1, clock_t& clock2) {
    return double(clock1 - clock2) / CLOCKS_PER_SEC;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double re_avg = 0, in_avg = 0, ma_avg = 0;
    vector<double> re_time, in_time, ma_time;

    int t = 10, kt = 3000;
    for (int i = 0; i < t; ++i) {
        clock_t begin = clock();
        for (long long k = 1; k < kt; ++k) {
            print("The side length of your cube: ");
            print(k);
            print("\nVolume of cube with side ");
            print(k);
            print(" is ");
            print(cube_regular(k));
            print("\n");
        }
        clock_t end = clock();
        double elapsed_secs = diffclock(end, begin);
        re_avg += elapsed_secs / t;
        re_time.push_back(elapsed_secs);
    }
    flush();  // Don't forget to flush the buffer

    for (int i = 0;i< t;++i) {
        clock_t begin = clock();
        for (long long k = 1; k < kt; ++k) {
            print("The side length of your cube: ");
            print(k);
            print("\nVolume of cube with side ");
            print(k);
            print(" is ");
            print(cube_inline(k));
            print("\n");
        }
        clock_t end = clock();
        double elapsed_secs = diffclock(end, begin);
        in_avg += elapsed_secs / t;
        in_time.push_back(elapsed_secs);
    }
    flush();  // Don't forget to flush the buffer
    for(int i = 0; i < t; ++i) {
        clock_t begin = clock();
        for (long long k = 1; k < kt; ++k) {
            print("The side length of your cube: ");
            print(k);
            print("\nVolume of cube with side ");
            print(k);
            print(" is ");
            print(cube_macro(k));
            print("\n");
        }
        clock_t end = clock();
        double elapsed_secs = diffclock(end, begin);
        ma_avg += elapsed_secs / t;
        ma_time.push_back(elapsed_secs);
    }
    flush();  // Don't forget to flush the buffer
    for (int i = 0; i < t;++i)
    {
        cout<<i<<"st run: "<<re_time[i]<<"seconds\n";
    }
    cout << "Then compute Avg_regular and you get the average of these 10 numbers =" << re_avg << "\n";
    for(int i = 0; i < t;++i)
    {
        cout<<i<<"st run: "<<in_time[i]<<"seconds\n";
    }
    cout << "Then compute Avg_inline and you get the average of these 10 numbers =" << in_avg << "\n";
    for(int i = 0; i < t;++i)
    {
        cout<<i<<"st run: "<<ma_time[i]<<"seconds\n";
    }
    cout << "Then compute Avg_macro and you get the average of these 10 numbers =" << ma_avg << "\n";

    return 0;
}
