#include <iostream>
// ? Including climits to get `sizeof` for integer types
#include <climits>

using std::cin;
using std::cout;
using std::endl;

// ? Global variables can be accessed and mutated anywhere in the program
int global_var{ 10 };

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
  */

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
  // NOTE sizeof is an operator, not a function, so the parentheses are optional
  cout << "age is " << sizeof age << " bytes" << endl;

  double wage{ 22.24 };
  cout << "wage is " << sizeof(wage) << " bytes" << endl;
  cout << "wage is " << sizeof wage << " bytes" << endl;

  // ? Constants
  const double price_per_room{ 30.0 };

  // Variables
}