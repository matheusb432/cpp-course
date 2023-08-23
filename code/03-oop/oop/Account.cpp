#include "Account.h"
#include <string>

using std::string;

// NOTE Implementing class methods with `ClassName::`
bool Account::deposit(double amount) {
  // ? `balance` here is an Account field
  // balance += amount;
  // ? `this` refers to the current object instance
  this->balance += amount;
  return true;
}

bool Account::withdraw(double amount) {
  if (balance - amount >= 0) {
    balance -= amount;
    return true;
  }
  return false;
}