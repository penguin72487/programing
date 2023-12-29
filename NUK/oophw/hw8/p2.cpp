#include <iostream>
#include <string>

// 基礎類別 Account
class Account {
protected:
    double balance;

public:
    Account(double initialBalance) : balance(initialBalance) {
        if (initialBalance < 0.0) {
            std::cerr << "Error: Initial balance cannot be negative. Setting to 0.0." << std::endl;
            balance = 0.0;
        }
    }

    virtual void credit(double amount) {
        balance += amount; // 加上存款
    }

    virtual bool debit(double amount) {
        if (amount > balance) {
            std::cerr << "Debit amount exceeded account balance." << std::endl;
            return false; // 取款失敗
        }
        balance -= amount; // 減去取款
        return true; // 取款成功
    }

    double getBalance() const {
        return balance;
    }

    virtual ~Account() {} // 虛擬析構函數
};

// 衍生類別 SavingsAccount
class SavingsAccount : public Account {
private:
    double interestRate; // 利率

public:
    SavingsAccount(double initialBalance, double interestRate)
        : Account(initialBalance), interestRate(interestRate) {}

    // 計算利息
    double calculateInterest() const {
        return balance * interestRate;
    }
};

// 衍生類別 CheckingAccount
class CheckingAccount : public Account {
private:
    double feePerTransaction; // 每筆交易的費用

public:
    CheckingAccount(double initialBalance, double feePerTransaction)
        : Account(initialBalance), feePerTransaction(feePerTransaction) {}

    // 覆寫 credit 函數以收取費用
    void credit(double amount) override {
        Account::credit(amount); // 先進行正常的存款
        balance -= feePerTransaction; // 然後收取費用
    }

    // 覆寫 debit 函數以收取費用
    bool debit(double amount) override {
        if (!Account::debit(amount)) return false; // 如果正常取款失敗，則返回false
        balance -= feePerTransaction; // 收取費用
        return true; // 如果成功，返回true
    }
};

// 主函數
int main() {
    SavingsAccount savings(100.0, 0.03); // 100元存款，3%利率
    CheckingAccount checking(100.0, 1.0); // 100元存款，每筆交易1元費用

    // 進行交易的測試
    savings.credit(50.0); // 存入50元
    savings.debit(20.0); // 取出20元
    std::cout << "Savings Account balance: $" << savings.getBalance() << std::endl;
    std::cout << "Interest earned: $" << savings.calculateInterest() << std::endl;

    checking.credit(50.0); // 存入50元
    checking.debit(20.0); // 取出20元
    std::cout << "Checking Account balance: $" << checking.getBalance() << std::endl;

    return 0;
}
