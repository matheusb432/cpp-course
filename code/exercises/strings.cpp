#include "strings.h"

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

  std::cout
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

  std::cout << formatted_full_name;
}

void cpp_strings_2() {
  string journal_entry_1{ "Isaac Newton" };
  string journal_entry_2{ "Leibniz" };

  journal_entry_1.erase(0, 6);

  if (journal_entry_1 > journal_entry_2) {
    journal_entry_1.swap(journal_entry_2);
  }

  std::cout << journal_entry_1 << "\n" << journal_entry_2;
}