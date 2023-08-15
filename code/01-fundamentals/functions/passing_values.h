#pragma once
#include <vector>
#include <string>

namespace passing_values {
  void examples();
}
void pass_by_value(int x);
void pass_by_pointer(int *x_ref);
void pass_by_value_vec(std::vector<int> vec);
void pass_by_pointer_vec(std::vector<int> *vec_ref);
void pass_by_value_vec_str(std::vector<std::string> vec_str);