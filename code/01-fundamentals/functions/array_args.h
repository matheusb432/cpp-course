#pragma once
#include <iostream>

namespace array_args {
  void examples();
}
/// NOTE Passing a readonly reference to an array.
void print_array(const int arr[], size_t size);
/// ? Modifying an array with a function
void increment_array(int arr[], size_t size, int by_value = 1);