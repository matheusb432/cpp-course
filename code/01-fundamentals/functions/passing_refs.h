#pragma once

#include <string>
#include <vector>

namespace passing_refs {
  void examples();
  void swap(int &a, int &b);
  void emphasize_str(std::string &str);
  void print_str(const std::string &str);
  void print_vector(const std::vector<int> &data);
  void increment_vector(std::vector<int> &data);
}