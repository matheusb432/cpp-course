#include "Account.h"
#include  <iostream>

void Account::withdraw(double amount) {
    balance -= amount;
}

void Account::deposit(double amount) {
    balance += amount;
}

Account::Account(double balance): balance{balance} {
}

Account::~Account() {
    std::cout << "DTOR: Account dtor called" << std::endl;
}
