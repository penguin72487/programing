def Sn_function(n, S0, ratio, Fee):
    Sn = S0
    for i in range(1, int(n) + 1):
        Sn = Sn * (1 + ratio / i) - Fee
    return Sn

def derivative(f, x, h=0.001):
    return (f(x + h) - f(x - h)) / (2 * h)

def second_derivative(f, x, h=0.001):
    return (f(x + h) - 2 * f(x) + f(x - h)) / (h**2)

def newton_method_for_maximum(f, x0, tolerance=1e-5, max_iter=1000):
    x = x0
    for _ in range(max_iter):
        f_prime = derivative(f, x)
        f_double_prime = second_derivative(f, x)
        if f_double_prime == 0:
            break
        x_new = x - f_prime / f_double_prime
        if abs(x_new - x) < tolerance:
            break
        x = x_new
    return x, f(x)

# Parameters
S0 = 1735
ratio = 3.03 / 100
Fee = 0.2
initial_guess = 1  # Initial guess for n

# Applying Newton's method
optimal_n, max_value = newton_method_for_maximum(lambda n: Sn_function(n, S0, ratio, Fee), initial_guess)
print(int(optimal_n), max_value)
