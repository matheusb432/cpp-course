#include "Account.h"
#include "Player.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void classes_and_objs();
void ctors_and_dtors();

int main() {
  // classes_and_objs();
  ctors_and_dtors();
}

void classes_and_objs() {
  // NOTE By default, uninitialized classes have garbage data for all props
  Player p1;
  Player* p_p1{ &p1 };

  // ? Accessing object member with the dot operator
  p1.health = 100;
  // ? Accessing object pointer member with the arrow operator
  p_p1->health += 50;
  p1.name = "player 1";

  p1.talk("hello there");
  p_p1->talk("ptr hello there");

  Player hero;

  Player players[]{ p1, hero };

  // ? sizeof(Player) here is the size of each class attribute
  // ? Will be sizeof(string) + sizeof(int) + sizeof(int)
  cout << "sizeof(Player): " << sizeof(Player) << endl;

  cout << players << endl;
  // ? Pointer arithmetic to offset the memory address by (sizeof(Player) * 1)
  cout << (players + 1) << endl;

  Player* enemy{};
  // ? Creating an object on the heap
  // ? The object inits with default values, in this case 0 for ints and "" for
  // string
  enemy = new Player();

  // ? Will initialize with the default attribute values
  Account* acc{ new Account() };
  acc->name = "My account";
  acc->balance = 1000;

  cout << "Account: " << acc->name << " (" << acc->balance << ")" << endl;
  // ? Equivalent
  (*acc).balance += 10;
  cout << "Account: " << acc->name << " (" << acc->balance << ")" << endl;

  // ? Calling the methods implemented in Account.cpp
  acc->withdraw(300);
  acc->deposit(100);
  cout << "Account: " << acc->name << " (" << acc->balance << ")" << endl;
}

// ? Will create a copy of the object and call it's copy constructor
void display_player(Player player_copy) {
  cout << "Player: " << player_copy.name << ", health = " << player_copy.health
       << ", xp = " << player_copy.xp << endl;
}

void ctors_and_dtors() {
  {
    // ? These will be freed from memory when the scope ends
    // ? Order will be `p3,p2,p1` since the stack is LIFO
    Player p1{ "p1" };
    Player p2{ "p2" };
    Player p3{ "p3" };

    display_player(p3);
  }

  // ? Valid syntax since the default ctor is defined
  Player* enemy = new Player;
  enemy->set_name("Enemy");

  Player* level_boss = new Player("Level Boss", 1000, 300);
  level_boss->set_name("Level Boss");

  Player* another_enemy = new Player{ "Some Enemy", 300 };

  display_player(*another_enemy);

  // ? Deleting the objects to call the destructor
  delete enemy;
  delete another_enemy;
  delete level_boss;
}