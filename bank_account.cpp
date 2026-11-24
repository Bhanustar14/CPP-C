#include "bank_account.hpp"

BankAccount::BankAccount(std::string owner, double initial_balance) 
    : owner_(std::move(owner)), balance_(initial_balance) {
    if (initial_balance < 0) throw std::invalid_argument("Negative initial balance");
}

void BankAccount::deposit(double amount) {
    if (amount <= 0) throw std::invalid_argument("Deposit must be positive");
    balance_ += amount;
}

void BankAccount::withdraw(double amount) {
    if (amount <= 0) throw std::invalid_argument("Withdrawal must be positive");
    if (amount > balance_) throw std::runtime_error("Insufficient funds");
    balance_ -= amount;
}

double BankAccount::get_balance() const { return balance_; }
std::string BankAccount::get_owner() const { return owner_; }
