#include <iostream>
#include "bank_account.hpp"
#include "thread_safe_queue.hpp"

int main() {
    BankAccount acc("Alice", 100.0);
    acc.deposit(50.0);
    std::cout << "Balance: " << acc.get_balance() << "\n";

    ThreadSafeQueue<int> q;
    q.push(10);
    q.push(20);
    
    if (auto val = q.pop()) std::cout << "Popped: " << *val << "\n";
    if (auto val = q.pop()) std::cout << "Popped: " << *val << "\n";
    return 0;
}
