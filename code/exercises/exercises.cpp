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

void carpet_cleaning_service() {
  const int SMALL_ROOM_COST{ 25 };
  const int LARGE_ROOM_COST{ 35 };
  const double TAX_RATE{ 0.06 };
  const int ESTIMATE_EXPIRY{ 30 };

  // ? {} will initialize it to 0
  int small_rooms{};
  cout << "How many small rooms would you like cleaned? ";
  cin >> small_rooms;

  int large_rooms{};
  cout << "How many large rooms would you like cleaned? ";
  cin >> large_rooms;

  double cost
    = (small_rooms * SMALL_ROOM_COST) + (large_rooms * LARGE_ROOM_COST);
  double tax_cost = cost * TAX_RATE;
  double total = cost + tax_cost;

  cout << "Estimate for carpet cleaning service" << endl;
  cout << "Number of small rooms: " << small_rooms << endl;
  cout << "Number of large rooms: " << large_rooms << endl;
  cout << "Price per small room: $" << SMALL_ROOM_COST << endl;
  cout << "Price per large room: $" << LARGE_ROOM_COST << endl;
  cout << "Cost: $" << cost << endl;
  cout << "Tax: $" << tax_cost << endl;

  cout << "=============================" << endl;
  cout << "Total estimate: $" << total << endl;
  cout << "This estimate is valid for " << ESTIMATE_EXPIRY << " days" << endl;
}

void assignment_operator() {
  int num1{ 13 };
  int num2{};

  num1 = { 5 };
  num2 = { num1 };

  cout << num1 << " " << num2;
}

int arithmetic_operators(int number) {
  int original_number{ number };

  number = { number * 2 };
  number = { number + 9 };
  number = { number - 3 };
  number = { number / 2 };
  number = { number - original_number };
  number = { number % 3 };

  cout << number << endl;

  return number;
}

// ? One liner logical operators exercise.
// ? Must be:
// ? 1. 18 or older OR 15 and have parental consent
// ? 2. have valid ssn (== true)
// ? 3. not have accidents (== false)
void logical_operators(int age, bool parental_consent, bool ssn,
                       bool accidents) {
  if ((age >= 18 || (age > 15 && parental_consent)) && ssn && !accidents)
    cout << "Yes, you can work.";

  return;
}

int main() {
  cout << "Results:" << endl;

  say_hi();
  sallys_dogs();
  date_of_birth();
  employee_profile();
  carpet_cleaning_service();
  assignment_operator();
  arithmetic_operators(5);
  logical_operators(16, true, true, false);

  cout << endl;
}