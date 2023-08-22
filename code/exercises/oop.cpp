#include "oop.h"
#include "Dog.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ? Set name to "Spot" & age to 5 with dot operator
Dog test_dog() {
  Dog spot;

  spot.name = "Spot";
  spot.age = 5;

  return spot;
}