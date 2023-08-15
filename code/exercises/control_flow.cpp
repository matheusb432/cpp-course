#include "control_flow.h"

#include <iostream>

using namespace std;

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