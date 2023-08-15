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

void can_you_drive_elif(int age) {
  int years_to_drive = 16 - age;
  if (years_to_drive > 0) {
    cout << "Sorry, come back in " << years_to_drive << " years";

    return;
  }

  cout << "Yes - you can drive!";
}

void can_you_drive(int age, bool has_car) {
  int years_to_drive = 16 - age;

  if (years_to_drive > 0) {
    cout << "Sorry, come back in " << years_to_drive
         << " years and be sure you own a car when you come back.";

    return;
  }

  cout << (has_car ? "Yes - you can drive!"
                   : "Sorry, you need to buy a car before you can drive!");
}

void display_day(int day_code) {
  switch (day_code) {
    case 0:
      cout << "Sunday";
      break;
    case 1:
      cout << "Monday";
      break;
    case 2:
      cout << "Tuesday";
      break;
    case 3:
      cout << "Wednesday";
      break;
    case 4:
      cout << "Thursday";
      break;
    case 5:
      cout << "Friday";
      break;
    case 6:
      cout << "Saturday";
      break;
    default:
      cout << "Error - illegal day code";
  }
}

int calculate_sum() {
  int sum{};

  for (int i = 1; i <= 15; i++) {
    // NOTE Ternary expressions should have parentheses to avoid any order of
    // operations bugs
    sum += ((i % 2 == 1) ? i : 0);
  }

  return sum;
}

int main() {
  cout << "Results:" << endl;

  // say_hi();
  // sallys_dogs();
  // date_of_birth();
  // employee_profile();
  // carpet_cleaning_service();
  // assignment_operator();
  // arithmetic_operators(5);
  // logical_operators(16, true, true, false);
  // can_you_drive(16, true);
  cout << calculate_sum();

  cout << endl;
}