#include <iostream>
#include <cstring>
#include <cctype>
// NOTE <iostream> includes <string>, but it's still good practice to include
// it even if redundant.
#include <string>

using namespace std;

void strings_and_functions() {
  char first_name[] = "Bjarne";
  char last_name[] = "Stroustrup";
  char whole_name[20]{};

  strcpy_s(whole_name, first_name);
  strcat_s(whole_name, last_name);

  // ? auto will infer `size_t`
  auto first_name_length = strlen(first_name);
  auto last_name_length = strlen(last_name);
  auto whole_name_length = strlen(whole_name);

  cout
    << "The length of the first name, " << first_name << ", is "
    << first_name_length << " letters long and the length of the last name, "
    << last_name << ", is " << last_name_length
    << " letters long. This means that the length of the whole name must be "
    << whole_name_length << " letters long.";
}

void cpp_strings() {
  string unformatted_full_name{ "StephenHawking" };
  string first_name{ unformatted_full_name, 0, 7 };
  string last_name = unformatted_full_name.substr(7);

  string formatted_full_name = first_name + " " + last_name;

  cout << formatted_full_name;
}

void cpp_strings_2() {
  string journal_entry_1{ "Isaac Newton" };
  string journal_entry_2{ "Leibniz" };

  journal_entry_1.erase(0, 6);

  if (journal_entry_1 > journal_entry_2) {
    journal_entry_1.swap(journal_entry_2);
  }

  cout << journal_entry_1 << "\n" << journal_entry_2;
}

// ? Simple encryption algorithm
void section_10_challenge() {
  string alphabet{ "_ abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ" };
  string key{ " _XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr" };

  cout << "Enter your secret message: ";
  // ? uncomment for simple testing:
  // string input{ "I'll meet you at billy's house at 10AM" };
  string input{};
  getline(cin, input);

  cout << "Encrypting message..." << endl;
  string encrypted{};

  for (char c : input) {
    // NOTE `find()` returns the index of the first substring match or `npos`
    size_t position = alphabet.find(c);
    // NOTE `npos` can be used to check if a char was found
    bool did_find = position != string::npos;

    encrypted += did_find ? key.at(position) : c;
  }
  cout << "Encrypted message: " << encrypted << endl;

  cout << "Decrypting message..." << endl;
  string decrypted{};

  for (char c : encrypted) {
    size_t position = key.find(c);
    bool did_find = position != string::npos;

    decrypted += did_find ? alphabet.at(position) : c;
  }
  cout << "Decrypted message: " << decrypted << endl;
}

int main() {
  /* ? C-Style strings

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

  strings_and_functions();
  */

  /* ? C++ strings
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
  */
  section_10_challenge();
}
