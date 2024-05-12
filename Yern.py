import numpy as np

# Define the initial conditions and parameters
S0 = 1735
ratio = 3.03 / 100
Fee = 0.2  # ada 0.2 atom 0.04
total_seconds = 365 * 24 * 60 * 60  # total seconds in a year

max_value = S0
optimal_frequency = total_seconds  # Start with the longest possible interval (once a year)

# Test different compounding frequencies (from once a year to once every second)
for interval in range(1, total_seconds + 1):
    num_compounds = total_seconds // interval
    Sn = S0
    for _ in range(num_compounds):
        Sn = Sn * (1 + ratio / num_compounds) - Fee
    if Sn > max_value:
        max_value = Sn
        optimal_frequency = interval

print(f"Optimal compounding interval in seconds: {optimal_frequency}, Maximum value: {max_value}")
