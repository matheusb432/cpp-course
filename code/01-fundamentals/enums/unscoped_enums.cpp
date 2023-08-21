#include "unscoped_enums.h";

#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;
//
// void test1();
// void test2();
// void test3();

// enum Direction { North, South, East, West };

// string direction_to_string(Direction direction);

string direction_to_string(Direction direction) {
  string result;
  switch (direction) {
    case North:
      result = "North";
      break;
    case South:
      result = "South";
      break;
    case East:
      result = "East";
      break;
    case West:
      result = "West";
      break;
    default:
      result = "Unknown direction";
  }
  return result;
}

void test1() {
  cout << "==== Test 1 ==== " << std::endl;
  Direction direction{ North };
  cout << "direction: " << direction << "\n";
  cout << direction_to_string(direction) << "\n";

  direction = West;
  cout << "direction: " << direction << "\n";
  cout << direction_to_string(direction) << "\n";

  // NOTE Casting an int to invalid enum value, unscoped enums allow this
  direction = Direction(100);
  cout << "direction: " << direction << "\n";
  cout << direction_to_string(direction) << "\n";
}

// enum GroceryItem { Apple, Orange, Banana, Grape };

// bool is_valid_grocery_item(GroceryItem grocery_item);

// NOTE Overloading the << (insertion) operator with enums
std::ostream &operator<<(std::ostream &os, GroceryItem grocery_item) {
  switch (grocery_item) {
    case Apple:
      os << "Apple";
      break;
    case Orange:
      os << "Orange";
      break;
    case Banana:
      os << "Banana";
      break;
    case Grape:
      os << "Grape";
      break;
    default:
      os << "Unknown grocery item";
  }
  return os;
}

bool is_valid_grocery_item(GroceryItem grocery_item) {
  switch (grocery_item) {
    case Apple:
    case Orange:
    case Banana:
    case Grape:
      return true;
    default:
      return false;
  }
}

void test2() {
  cout << "==== Test 2 ==== " << std::endl;
  vector<GroceryItem> grocery_list{ Apple, Apple, Banana, Orange };

  // ! Generates compiler err
  // GroceryItem item = 100;

  int helicopter{ 1000 };

  // ! Adds invalid item
  grocery_list.push_back(GroceryItem(helicopter));
  // ? Adds valid item
  grocery_list.push_back(GroceryItem(1));

  for (auto item : grocery_list) {
    cout << item << std::endl;
  }
}

//// NOTE Using an `Unknown` enum value to represent an invalid enum value
// enum State { EngineFailure, InclementWeather, Nominal, Unknown };
// enum Sequence { Abort, Hold, Launch };

// NOTE Overloading the >> (extraction) operator with enums
std::istream &operator>>(std::istream &is, State &state) {
  // ! Also works
  // int user_input;
  std::underlying_type_t<State> user_input;
  is >> user_input;

  switch (user_input) {
    case EngineFailure:
    case InclementWeather:
    case Nominal:
    case Unknown:
      state = State(user_input);
      break;
    default:
      cout << "Invalid state, setting to Unknown" << std::endl;
      state = Unknown;
  }

  return is;
}

std::ostream &operator<<(std::ostream &os, Sequence sequence) {
  switch (sequence) {
    case Abort:
      os << "Abort";
      break;
    case Hold:
      os << "Hold";
      break;
    case Launch:
      os << "Launch";
      break;
    default:
      os << "Unknown sequence";
  }
  return os;
}

void initiate(Sequence sequence) {
  cout << "Initiating " << sequence << " sequence!" << std::endl;
}

void test3() {
  cout << "==== Test 3 ==== " << std::endl;

  State state;
  cout << "Enter state: ";
  cin >> state;

  switch (state) {
    case EngineFailure:
      initiate(Abort);
      break;
    case InclementWeather:
      initiate(Hold);
      break;
    case Nominal:
      initiate(Launch);
      break;
    case Unknown:
      cout << "Unknown state, aborting!" << std::endl;
      break;
  }
}

void unscoped_enums() {
  test1();
  test2();
  test3();
}