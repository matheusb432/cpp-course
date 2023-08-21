#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

enum Direction { North, South, East, West };

enum GroceryItem { Apple, Orange, Banana, Grape };

void test1();
void test2();
void test3();
string direction_to_string(Direction direction);
bool is_valid_grocery_item(GroceryItem grocery_item);
// NOTE Using an `Unknown` enum value to represent an invalid enum value
enum State { EngineFailure, InclementWeather, Nominal, Unknown };
enum Sequence { Abort, Hold, Launch };
void initiate(Sequence sequence);
void unscoped_enums();