#include "Dog.h"
#include <string>

using std::string;

string Dog::get_name() {
  return this->name;
}

void Dog::set_name(string value) {
  this->name = value;
}

int Dog::get_age() {
  return this->age;
}

void Dog::set_age(int value) {
  this->age = value;
}

int Dog::get_human_years() {
  return age * 7;
}

string Dog::speak() {
  return "Woof";
}
