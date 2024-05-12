#include <iostream>
#include <cmath>

int main() {
    double S0 = 220;
    double ratio = 69 / 100.0;
    double Fee = 0.06;
    double slip = 1.16 / 100.0;
    int total_seconds = 365 * 24 * 60 * 60;  // Total seconds in a year

    double max_value = S0;
    int optimal_frequency = total_seconds;
    int interval = 86400; // Test daily compounding

    int num_compounds = total_seconds / interval;
    double Sn = S0;
    std::cout << "Starting Sn: " << Sn << std::endl;

    for (int i = 0; i < num_compounds; ++i) {
        Sn = Sn * (1 + ratio * (1 - slip) / num_compounds) - Fee;
        if (i < 10) { // Print the first 10 compounding steps to debug
            std::cout << "Compound " << i + 1 << ": Sn = " << Sn << std::endl;
        }
    }

    if (Sn > max_value) {
        max_value = Sn;
        optimal_frequency = interval;
    }

    std::cout << "Optimal compounding interval in seconds: " << optimal_frequency
              << ", Maximum value: " << max_value << std::endl;

    return 0;
}
