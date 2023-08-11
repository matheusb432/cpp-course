#include <iostream>

using namespace std;

// ? For the basic exercises I won't add the instructions.

void say_hi() { cout << "Hi Frank!"; }

void sallys_dogs() {
  int x{ 3 };

  cout << "Sally has " << x << " dogs.";
}

// ? Receive inputs via `cin` in a `m d yyyy` format
void date_of_birth() {
  int m{};
  int d{};
  int y{};

  cin >> m >> d >> y;

  cout << m << " " << d << " " << y;
}

// ? Receive inputs and initialize others
void employee_profile() {
  int age;
  double hourly_wage{ 23.5 };
  string name;

  cin >> name >> age;

  cout << name << " " << age << " " << hourly_wage;
}

int main() {
  cout << "Results:" << endl;

  say_hi();
  sallys_dogs();
  date_of_birth();
  employee_profile();

  cout << endl;
}