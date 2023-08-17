#include "functions.h"

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// ? Using recursion
int sum_of_digits(int n) {
  int next = n % 10;
  if (next == n)
    return next;

  return next + sum_of_digits(n / 10);
}

// ? Using C stdlib math fns
void c_math_functions() {
  double bill_total{ 102.78 };
  int number_of_guests{ 5 };

  double individual_bill = bill_total / number_of_guests;

  int individual_bill_1 = floor(individual_bill);
  int individual_bill_2 = round(individual_bill);
  double individual_bill_3 = ceil(individual_bill * 100) / 100;

  cout << "The individual bill at location 1 will be $" << individual_bill_1
       << "\n"
       << "The individual bill at location 2 will be $" << individual_bill_2
       << "\n"
       << "The individual bill at location 3 will be $" << individual_bill_3;
}

void temperature_conversion(double fahrenheit_temperature) {
  double celsius_temperature = fahrenheit_to_celsius(fahrenheit_temperature);
  double kelvin_temperature = fahrenheit_to_kelvin(fahrenheit_temperature);

  cout << "The fahrenheit temperature " << fahrenheit_temperature
       << " degrees is equivalent to " << celsius_temperature
       << " degrees celsius and " << kelvin_temperature << " degrees kelvin.";
}

double fahrenheit_to_celsius(double temperature) {
  return round(((temperature - 32) * 5) / 9);
}

double fahrenheit_to_kelvin(double temperature) {
  return round(((temperature - 32) * 5) / 9 + 273);
}

void modify_grocery_list() {
  print_grocery_list();
  print_grocery_list(5);
  print_grocery_list(7, 11);
}

void print_grocery_list(int apples, int oranges, int mangos) {
  cout << apples << " apples"
       << "\n"
       << oranges << " oranges"
       << "\n"
       << mangos << " mangos"
       << "\n";
}