#include "functions.h"
#include "strings.h"
#include "basic_io.h"
#include "control_flow.h"

#include <iostream>

int main() {
  say_hi();
  sallys_dogs();
  date_of_birth();
  employee_profile();
  carpet_cleaning_service();
  assignment_operator();
  arithmetic_operators(5);
  logical_operators(16, true, true, false);
  can_you_drive(16, true);
  std::cout << calculate_sum();
  c_math_functions();

  std::cout << std::endl;
}