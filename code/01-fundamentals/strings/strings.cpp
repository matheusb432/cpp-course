#include "letter_pyramid.h";
#include "challenges.h";

#include <iostream>
#include <cstring>
#include <cctype>
// NOTE <iostream> includes <string>, but it's still good practice to include
// it even if redundant.
#include <string>

using namespace std;

int main() {
  // ? C-Style strings

  // NOTE The inferred array size is 9, 8 chars + null terminator char (\0)
  char city[9] = "New York";
  cout << city << endl;
  // NOTE Updating a C-Style string, often better to just use C++ strings
  strcpy_s(city, "Chicago");
  cout << city << endl;

  // ? `{}` Inits the string to a null-terminated string
  char str[80]{};

  strcat_s(str, "Hello");
  cout << str << "\nlen: " << strlen(str) << endl;
  cout << "Enter a value for str: ";
  // ? `cin.getline()` Replaces the passed char array
  cin.getline(str, 80);
  cout << str << endl;

  // ? C++ strings
  std::string s0;
  // `std::` is not needed since `using namespace std;` is in scope
  string s1{ "Apple" };
  string s2{ "Banana" };

  // ? s0 is already initialized so UB won't happen
  cout << "s0: " << s0 << " | len: " << s0.length() << endl;
  cout << "s1: " << s1 << " | len: " << s1.length() << endl;

  // ? Comparing strings by ASCII value
  if (s1 < s2) {
    cout << s1 << " is less than " << s2 << endl;
  } else {
    cout << s1 << " is greater than " << s2 << endl;
  }

  // ? Concatenating strings, must have at least one `std::string`
  s1 += " and " + s2 + " are both fruits.";
  cout << "s1: " << s1 << " | len: " << s1.length() << endl;

  // ? Assigning strings
  s1 = "Other str";

  cout << "s1: " << s1 << " | len: " << s1.length() << endl;

  // ? Iterating over strings
  for (char c : s1) {
    cout << c << endl;
  }

  for (int c_ascii : s1) {
    cout << c_ascii << endl;
  }
  section_10_challenge();
  letter_pyramid("");
  letter_pyramid("AB");
  letter_pyramid("ABC");
  letter_pyramid("12345");
  letter_pyramid("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
}
