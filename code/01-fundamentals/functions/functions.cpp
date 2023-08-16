#include "passing_values.h"
#include "array_args.h"
#include "passing_refs.h"

#include <iostream>
#include <vector>

int main() {
  // passing_values::examples();
  // array_args::examples();
  int x{ 10 }, y{ 20 };
  std::cout << "x: " << x << ", y: " << y << '\n';
  passing_refs::swap(x, y);
  std::cout << "x: " << x << ", y: " << y << '\n';

  std::string str = "hello world";

  // ? Mutating the string by reference
  passing_refs::print_str(str);
  passing_refs::emphasize_str(str);
  passing_refs::print_str(str);

  std::vector<int> data{ 1, 2, 3, 4, 5 };

  passing_refs::print_vector(data);
  passing_refs::increment_vector(data);
  passing_refs::print_vector(data);
}
