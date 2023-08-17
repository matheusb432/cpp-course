#include "passing_refs.h"
#include <string>
#include <vector>
#include <iostream>

namespace passing_refs {
   void examples() {
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
  // NOTE Accepting references as parameters to modify the original values
  void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
  }

  void emphasize_str(std::string &str) { str += "!!!"; }

  // NOTE With `const`, the parameter reference is immutable
  void print_str(const std::string &str) { std::cout << str << '\n'; }

  // NOTE Accepting references as parameters to avoid needlessly copying data
  void print_vector(const std::vector<int> &data) {
    for (auto &element : data) {
      std::cout << element << ' ';
    }
    std::cout << '\n';
  }

  void increment_vector(std::vector<int> &data) {
    for (auto &element : data) {
      element++;
    }
  }
}
