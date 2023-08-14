#include <iostream>
// ? Including climits to get `sizeof` for integer types
#include <climits>

using std::cin;
using std::cout;
using std::endl;

// ? Global variables can be accessed and mutated anywhere in the program
int global_var{ 10 };

// ? Get change amount for a given integer
void section_8_challenge() {
  cout << "Enter an amount in cents: ";
  int amount_in_cents{};
  cin >> amount_in_cents;

  cout << "You can provide this change as follows" << endl;

  int balance{ amount_in_cents };

  int dollars = balance / 100;
  // ? Equivalent to `balance = balance % 100`
  balance %= 100;
  int quarters = balance / 25;
  balance %= 25;
  int dimes = balance / 10;
  balance %= 10;
  int nickels = balance / 5;
  balance %= 5;

  int pennies = balance;

  cout << "dollars:" << dollars << endl;
  cout << "quarters:" << quarters << endl;
  cout << "dimes:" << dimes << endl;
  cout << "nickels:" << nickels << endl;
  cout << "pennies:" << pennies << endl;
}

// TODO move each section into its own file
int main() {
  // Variables
  /*
  cout << "Global var: " << global_var << endl;

  // ? Different ways to initialize variables
  int x = 5;
  int y(10);
  int z{ 20 };

  int age;

  // ! Acessing unintialized memory causes undefined behavior (UB)
  // cout << age << endl;

  cout << "Enter the width of the room: ";
  int room_width{ 0 };
  cin >> room_width;

  cout << "Enter the length of the room: ";
  int room_length{ 0 };
  cin >> room_length;

  cout << "The area of the room is " << room_width * room_length << "m"
       << endl;

  // ? Character types
  char middle_initial{ 'J' };

  // ? Integer types
  unsigned short int exam_score{ 55 };

  int countries_represented{ 65 };

  long people_in_florida{ 20610000 };
  // * The single quotes can make it easier to read large numbers (C++14)
  // NOTE The list initialization will error if this overflows (if the variable
  // was a long instead of a long long)
  long long people_on_earth { 7'600'000'000 };

  // ? Floating point types
  float car_payment{ 401.23 };

  double pi{ 3.14159 };

  // * (2.7 * 10^120)
  long double large_amount{ 2.7e120 };

  // ? Boolean types
  bool game_over{ false };
  // NOTE bools will print as 0 or 1
  cout << "The value of gameOver is " << game_over << endl;

  // ? Overflow example
  short value1{ 30000 };
  short value2{ 1000 };
  short product{ value1 * value2 };

  // NOTE will overflow into a negative number in this instance
  cout << "The product of " << value1 << " and " << value2 << " is " << product
       << endl;

  // ? sizeof operator - depends on specific c++ version and compiler
  cout << "char: " << sizeof(char) << " bytes" << endl;
  cout << "int: " << sizeof(int) << " bytes" << endl;
  cout << "unsigned int: " << sizeof(unsigned int) << " bytes" << endl;
  cout << "short: " << sizeof(short) << " bytes" << endl;
  cout << "long: " << sizeof(long) << " bytes" << endl;
  cout << "long long: " << sizeof(long long) << " bytes" << endl;

  cout << "========================" << endl;

  cout << "float: " << sizeof(float) << " bytes" << endl;
  cout << "double: " << sizeof(double) << " bytes" << endl;
  cout << "long double: " << sizeof(long double) << " bytes" << endl;

  cout << "========================" << endl;

  cout << "Minimum values:" << endl;

  cout << "char: " << CHAR_MIN << endl;
  cout << "int: " << INT_MIN << endl;
  cout << "short: " << SHRT_MIN << endl;
  cout << "long: " << LONG_MIN << endl;
  cout << "long long: " << LLONG_MIN << endl;

  cout << "========================" << endl;

  cout << "Maximum values:" << endl;

  cout << "char: " << CHAR_MAX << endl;
  cout << "int: " << INT_MAX << endl;
  cout << "short: " << SHRT_MAX << endl;
  cout << "long: " << LONG_MAX << endl;
  cout << "long long: " << LLONG_MAX << endl;

  cout << "========================" << endl;

  cout << "sizeof using variable names" << endl;

  int age{ 21 };
  cout << "age is " << sizeof(age) << " bytes" << endl;
  // NOTE sizeof is an operator, not a function, so the parentheses are
  optional cout << "age is " << sizeof age << " bytes" << endl;

  double wage{ 22.24 };
  cout << "wage is " << sizeof(wage) << " bytes" << endl;
  cout << "wage is " << sizeof wage << " bytes" << endl;

  // ? Constants
  const double price_per_room{ 30.0 };

  // Variables

  // Statements and Operators

  int total{};
  int num1{}, num2{}, num3{};
  const int count{ 3 };

  cout << "Enter 3 integers separated by spaces: ";
  cin >> num1 >> num2 >> num3;

  total = num1 + num2 + num3;

  double average{ 0.0 };

  // NOTE Casting to double to get a double result
  average = static_cast<double>(total) / count;

  cout << "The 3 numbers were: " << num1 << ", " << num2 << ", " << num3
       << endl;
  cout << "The sum of the numbers is: " << total << endl;
  cout << "The average of the numbers is: " << average << endl;

  // ?  Displaying bool as true or false
  cout << std::boolalpha;
  cout << "true: " << true << endl;
  cout << "false: " << false << endl;

  // ?  Displaying bool as 1 or 0 (default)
  cout << std::noboolalpha;
  cout << "true: " << true << endl;
  cout << "false: " << false << endl;

  // ? Compound assignment operators
  int counter{ 10 };
  counter += 5; // 15

  counter *= 3; // 45
  counter /= 5; // 9

  cout << counter << endl;
  */
  section_8_challenge();
  // Statements and Operators
}