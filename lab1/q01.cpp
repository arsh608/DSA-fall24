#include <iostream>

class BankAccount {
private:
    double *accountBalance;
public:
    BankAccount() : accountBalance(new double(0.0)) {}
    BankAccount(double initialBalance) : accountBalance(new double(initialBalance)) {}
    BankAccount(const BankAccount& source) : accountBalance(new double(*source.accountBalance)) {}

    bool withdraw(double amount) {
        if (amount > *accountBalance) return false;
        *accountBalance -= amount;
        return true;
    }

    void displayBalance() const { 
        std::cout << *accountBalance << std::endl; 
    }

    ~BankAccount() {
        delete accountBalance;
    }
};

int main() {
    BankAccount firstAccount;
    BankAccount secondAccount(1000.0);
    BankAccount thirdAccount(secondAccount);

    thirdAccount.withdraw(200);

    firstAccount.displayBalance();
    secondAccount.displayBalance();
    thirdAccount.displayBalance();

    return 0;
}
