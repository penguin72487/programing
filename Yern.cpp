#include <iostream>
#include <cmath>

int main() {
    double S0 = 41.32;// atom 40 ada 1735
    double ratio = 16.99 / 100;//16.99 3.03
    double Fee = 0.04+0.026;//0.04 0.2
    int total_seconds = 365 * 24 * 60 * 60;  // Total seconds in a year

    double max_value = S0;
    int optimal_frequency = total_seconds;

    for (int interval = 1; interval <= total_seconds; ++interval) {
        int num_compounds = total_seconds / interval;
        double Sn = S0;
        for (int i = 0; i < num_compounds; ++i) {
            Sn = Sn * (1 + ratio / num_compounds) - Fee;
        }
        if (Sn > max_value) {
            max_value = Sn;
            optimal_frequency = interval;
        }
    }

    std::cout << "Optimal compounding interval in seconds: " << optimal_frequency 
              << ", Maximum value: " << max_value << std::endl;
    
    std::cout << "Optimal compounding interval in minutes: " << double(optimal_frequency) / 60.0
              << ", Maximum value: " << max_value << std::endl;
    std::cout << "Optimal compounding interval in hours: " << double(optimal_frequency) / 3600.0 
              << ", Maximum value: " << max_value << std::endl;
    std::cout << "Optimal compounding interval in days: " << double(optimal_frequency) / 86400.0
                << ", Maximum value: " << max_value << std::endl;


    return 0;
}
