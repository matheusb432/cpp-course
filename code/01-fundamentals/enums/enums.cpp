

#include <iostream>
#include <string>
#include <vector>
#include "unscoped_enums.h"

using std::cin;
using std::cout;
using std::string;
using std::vector;

// NOTE Scoped enums with the `class` keyword
enum class Item { Milk = 350, Bread = 250, Apple = 132, Orange = 100 };
// ? The inferred underlying type is `int` here
// enum class Item : int { Milk = 350, Bread = 250, Apple = 132, Orange = 100 };

bool is_valid_item(Item item);

std::ostream &operator<<(std::ostream &os, Item item) {
  // ? Type is inferred to `int`
  auto value = static_cast<std::underlying_type_t<Item>>(item);

  switch (item) {
    // ? Acessing the value of a scoped enum with the scope resolution operator
    case Item::Milk:
      os << "Milk";
      break;
    case Item::Bread:
      os << "Bread";
      break;
    case Item::Apple:
      os << "Apple";
      break;
    case Item::Orange:
      os << "Orange";
      break;
    default:
      os << "Unknown item";
  }
  os << " : " << value;
  return os;
}

bool is_valid_item(Item item) {
  switch (item) {
    case Item::Milk:
    case Item::Bread:
    case Item::Apple:
    case Item::Orange:
      return true;
    default:
      return false;
  }
}

void display_list_scoped(const vector<Item> &items) {
  cout << "Grocery List: " << std::endl;
  int invalid_item_count{};
  int valid_item_count{};
  for (auto item : items) {
    cout << item << std::endl;

    if (is_valid_item(item)) {
      valid_item_count++;
    } else {
      invalid_item_count++;
    }
  }
  cout << std::endl;
  cout << "Valid items: " << valid_item_count << std::endl;
  cout << "Invalid items: " << invalid_item_count << std::endl;
  cout << "Total items: " << items.size() << std::endl;
}

void test1_scoped() {
  cout << "==== Test 1 Scoped ==== " << std::endl;
  vector<Item> items{ Item::Milk, Item::Milk, Item::Bread, Item::Orange };

  int helicopter{ 1000 };

  // ! Generates compiler err
  // items.push_back(helicopter);
  items.push_back(Item(helicopter)); // ? Invalid item
  items.push_back(Item(350));        // ? Valid item

  display_list_scoped(items);
}

void scoped_enums() {
  test1_scoped();
}

int main() {
  unscoped_enums();
  scoped_enums();
}
