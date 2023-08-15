#include "array_args.h"
#include <iostream>

namespace array_args {
  void examples() {
    int arr[] = { 1, 2, 3, 4, 5 };
    print_array(arr, 5);
    increment_array(arr, 5);
    increment_array(arr, 5, 2);
    print_array(arr, 5);
  }
}

void print_array(const int arr[], size_t size) {
  for (size_t i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;
}

void increment_array(int arr[], size_t size, int by_value) {
  for (size_t i = 0; i < size; i++) {
    arr[i] += by_value;
  }
}
