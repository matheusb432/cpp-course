#include "pointers.h"

#include <string>

using std::string;

void swap_pointers(int *ptr1, int *ptr2) {
  int temp = *ptr1;
  *ptr1 = *ptr2;
  *ptr2 = temp;

  // ? Without temp variable
  //*ptr1 = *ptr1 + *ptr2;
  //*ptr2 = *ptr1 - *ptr2;
  //*ptr1 = *ptr1 - *ptr2;
}

void multiply_with_pointer(int *ptr, int multiplier) {
  *ptr *= multiplier;
}

int find_max_element(int *arr, int size) {
  int max{ arr[0] };
  for (int i = 1; i < size; i++) {
    if (max > arr[i])
      continue;

    max = arr[i];
  }

  return max;
}

// ? Reversing an array using raw pointers
void reverse_array(int *arr, int size) {
  for (int i = 0; i < (size / 2); i++) {
    // ? equivalent to:
    // swap_pointers(arr + i, arr + size - i - 1);

    int *lhs_ptr = arr + i;
    int *rhs_ptr = arr + size - i - 1;

    int temp = *lhs_ptr;
    *lhs_ptr = *rhs_ptr;
    *rhs_ptr = temp;
  }
}

// ? Reversing string characters with pointers
string reverse_string(const string &str) {
  string reversed;

  const char *start = str.c_str();
  const char *end = str.c_str() + str.size() - 1;

  while (end >= start) {
    reversed.push_back(*end);
    end--;
  }

  return reversed;
}
