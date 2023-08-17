#pragma once

#include <vector>

using std::vector;

namespace cli_app {
  enum MenuOption : char {
    PRINT_NUMBERS = 'P',
    FIND_NUMBER = 'F',
    ADD_NUMBER = 'A',
    DISPLAY_MEAN = 'M',
    DISPLAY_SMALLEST = 'S',
    DISPLAY_LARGEST = 'L',
    QUIT = 'Q'
  };

  void print_menu();
  void print_numbers(const vector<double> &numbers);
  int find_indexof(const vector<double> &numbers);
  void add_number(vector<double> &numbers);
  void display_mean(const vector<double> &numbers);
  void display_smallest(const vector<double> &numbers);
  void display_largest(const vector<double> &numbers);
}