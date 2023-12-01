#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
class SavingsAccount {
private:
    double savingsBalance;

public:
    static double annualInterestRate;

    SavingsAccount(double balance) : savingsBalance(balance) {}

    void calculateMonthlyInterest() {
        savingsBalance += (savingsBalance * annualInterestRate / 12.0);
    }

    static void modifyInterestRate(double newInterestRate) {
        annualInterestRate = newInterestRate;
    }

    double getBalance() const {
        return savingsBalance;
    }
};

double SavingsAccount::annualInterestRate = 0.0;
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cout.tie(0);
    SavingsAccount saver1(2000.00);
    SavingsAccount saver2(3000.00);

    SavingsAccount::modifyInterestRate(0.03); // 設定年利率為 3%

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    cout << "Saver 1 balance: $" << saver1.getBalance() << endl;
    cout << "Saver 2 balance: $" << saver2.getBalance() << endl;

    SavingsAccount::modifyInterestRate(0.04); // 設定年利率為 4%

    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    cout << "Saver 1 balance: $" << saver1.getBalance() << endl;
    cout << "Saver 2 balance: $" << saver2.getBalance() << endl;

    return 0;
}
