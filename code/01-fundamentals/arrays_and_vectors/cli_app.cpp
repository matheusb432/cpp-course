#include "cli_app.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace cli_app {

  static const int NO_INDEX = -1;

  double get_input();

  void print_menu() {
    cout << "\n" << MenuOption::PRINT_NUMBERS << ". Print numbers" << endl;
    cout << MenuOption::ADD_NUMBER << ". Add a number" << endl;
    cout << MenuOption::FIND_NUMBER << ". Find a number" << endl;
    cout << MenuOption::DISPLAY_MEAN << ". Display mean of the numbers"
         << endl;
    cout << MenuOption::DISPLAY_SMALLEST << ". Display the smallest number"
         << endl;
    cout << MenuOption::DISPLAY_LARGEST << ". Display the largest number"
         << endl;
    cout << MenuOption::QUIT << ". Quit" << endl;
    cout << "Enter your choice: ";
  }

  void print_numbers(const vector<double> &numbers) {
    if (numbers.empty()) {
      cout << "[] - The list is empty" << endl;
      return;
    }

    cout << "[ ";
    for (auto num : numbers)
      cout << num << ", ";
    cout << "]" << endl;
  }

  int find_indexof(const vector<double> &numbers) {
    cout << "Enter the number to find: ";
    auto n_to_find{ get_input() };

    for (int i = 0; i < numbers.size(); i++) {
      if (n_to_find != numbers[i])
        continue;

      cout << "Found it! " << n_to_find << " exists in numbers @ index " << i
           << endl;

      return i;
    }

    cout << "The number " << n_to_find << " was not found!" << endl;

    return NO_INDEX;
  }

  void add_number(vector<double> &numbers) {
    cout << "Enter the number to add: ";

    auto new_number{ get_input() };
    cout << "Added " << new_number << " to the list.";
    numbers.push_back(new_number);
  }
  void display_mean(const vector<double> &numbers) {
    if (numbers.empty()) {
      cout << "Unable to calculate mean - no data" << endl;
      return;
    }

    double sum{};
    for (auto num : numbers)
      sum += num;

    auto mean = sum / numbers.size();
    std::cout << "Mean is " << mean << endl;
    std::cout << "int Mean is " << static_cast<int>(mean) << endl;
  }

  void display_smallest(const vector<double> &numbers) {
    if (numbers.empty()) {
      cout << "Unable to get smallest - no data" << endl;
      return;
    }

    double smallest{ numbers.at(0) };
    for (auto num : numbers) {
      if (num > smallest)
        continue;
      smallest = num;
    }
    std::cout << "Smallest is " << smallest << endl;
  }

  void display_largest(const vector<double> &numbers) {
    if (numbers.empty()) {
      cout << "Unable to get largest - no data" << endl;
      return;
    }

    double largest{ numbers.at(0) };
    for (auto num : numbers) {
      if (num < largest)
        continue;
      largest = num;
    }
    std::cout << "Largest is " << largest << endl;
  }

  double get_input() {
    double new_number{};
    while (true) {
      cin >> new_number;

      if (cin.fail()) {
        cout << "Invalid input! Must be a double" << endl;
        cin.clear();
        continue;
      }
      break;
    }
    return new_number;
  }
}