#include "passing_values.h"

#include <iostream>
#include <vector>

namespace passing_values {
  void examples() {
    int x = 5;

    pass_by_value(x); // Won't change x
    std::cout << x << std::endl;

    // NOTE Passing a pointer to x
    pass_by_pointer(&x); // Will change x
    std::cout << x << std::endl;

    std::vector<int> int_vec{ 1, 2, 3 };

    pass_by_value_vec(int_vec);
    std::cout << int_vec.size() << std::endl;

    pass_by_pointer_vec(&int_vec);
    std::cout << int_vec.size() << std::endl;

    std::vector<std::string> v_str{ "Hello", "World" };

    pass_by_value_vec_str(v_str);

    std::cout << v_str.size() << std::endl;
  }
}

/// NOTE This function will not change the value of x, instead it accepts a
/// *copy* of x This applies to every type, so even vectors passed by value
/// will be copied
void pass_by_value(int x) { x = 10; }

/// NOTE This function will change the value of x, because it accepts a
/// *reference* to x
void pass_by_pointer(int *x_ref) { *x_ref = 10; }

void pass_by_value_vec(std::vector<int> vec) { vec.push_back(10); }

void pass_by_pointer_vec(std::vector<int> *vec_ref) { vec_ref->push_back(10); }

/// The same applies to a vector of strings, vec_str will be deep copied
void pass_by_value_vec_str(std::vector<std::string> vec_str) {
  vec_str.clear();
}
