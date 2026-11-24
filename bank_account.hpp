#pragma once
#include <string>
#include <stdexcept>

class BankAccount {
public:
    BankAccount(std::string owner, double initial_balance);
    void deposit(double amount);
    void withdraw(double amount);
    double get_balance() const;
    std::string get_owner() const;

private:
    std::string owner_;
    double balance_;
}



