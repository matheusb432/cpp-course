#pragma once

#include <string>

using std::string;

class Account {
public:
  // NOTE Setting default values for class attributes
  string name{ "Account" };
  double balance{ 4.2 };

  // NOTE Declaring methods in the class definition on the header file
  bool deposit(double amount);
  bool withdraw(double amount);
};