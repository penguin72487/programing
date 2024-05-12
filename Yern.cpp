#include <iostream>
#include <iomanip>  // Include for std::setprecision
#define endl "\n"
int main() {
    long double S0 = 220.0; // 初始金額
    long double ratio = 69.0 / 100.0; // 年化回報率
    long double Fee = 0.06; // 手續費
    long double slip = 1.16 / 100.0; // 滑點
    int total_seconds = 365 * 24 * 60 * 60; // 一年的總秒數

    long double max_value = S0;
    int optimal_frequency = total_seconds;

    for (int interval = 1; interval <= total_seconds; ++interval) {
        int num_compounds = total_seconds / interval;
        long double Sn = S0;
        for (int i = 0; i < num_compounds; ++i) {
            long double growth_factor = 1 + (ratio * (1 - slip) / static_cast<long double>(num_compounds));
            Sn = Sn * growth_factor - Fee;
        }
        if (Sn > max_value) {
            max_value = Sn;
            optimal_frequency = interval;
        }
    }

    std::cout << std::fixed << std::setprecision(2)
              << "Optimal compounding interval in seconds: " << optimal_frequency 
              << ", Maximum value: " << max_value << endl;
    
    std::cout << "Optimal compounding interval in minutes: " << (long double)(optimal_frequency) / 60.0
              << ", Maximum value: " << max_value << endl;
    std::cout << "Optimal compounding interval in hours: " << (long double)(optimal_frequency) / 3600.0 
              << ", Maximum value: " << max_value << endl;
    std::cout << "Optimal compounding interval in days: " << (long double)(optimal_frequency) / 86400.0
                << ", Maximum value: " << max_value << endl;

    return 0;
}
