#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <random>

// 獲取當前時間的奈秒部分
auto now = std::chrono::high_resolution_clock::now();
auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(now.time_since_epoch()).count();

using namespace std;

string generate_large_number(int size) {
    string num = "";
    for (int i = 0; i < size; i++) {
        num += to_string(rand() % 10);
    }
    return num;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    srand(nanos);  // Seed for random number generator
    const int digit_count = 1000000;  // Modify as needed

    string num1 = generate_large_number(digit_count);
    string num2 = generate_large_number(digit_count);

    ofstream out_file("ex-in.txt");
    if (out_file.is_open()) {
        out_file << num1 << endl;
        out_file << "+" << endl;
        out_file << num2 << endl;
        out_file << "=" << endl;
        out_file << "STOP" << endl;
        out_file.close();
    } else {
        cerr << "Unable to open file for writing." << endl;
        return 1;
    }

    return 0;
}
