#pragma once

class Account {
    double balance;

public:
    double get_balance() const {
        return balance;
    }

    void withdraw(double amount);
    void deposit(double amount);

    Account(double balance);
    ~Account();
};
