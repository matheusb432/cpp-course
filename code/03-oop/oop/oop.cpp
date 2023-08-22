#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Player {
public:
  // ? class attributes (props)
  string name;
  int health;
  int xp;

  // ? class methods
  void talk(string text) {
    cout << name << "says: " << text << endl;
  }
  bool is_dead();
};

class Account {
public:
  // NOTE Setting default values for class attributes
  string name{ "Account" };
  double balance{ 4.2 };

  bool deposit(double);
  bool withdraw(double);
};

int main() {
  // NOTE By default, uninitialized classes have garbage data for all props
  Player p1;
  Player *p_p1{ &p1 };

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

  Player *enemy{};
  // ? Creating an object on the heap
  // ? The object inits with default values, in this case 0 for ints and "" for
  // string
  enemy = new Player();

  // ? Will initialize with the default attribute values
  Account *acc{ new Account() };
  acc->name = "My account";
  acc->balance = 1000;

  cout << "Account: " << acc->name << " (" << acc->balance << ")" << endl;
  // ? Equivalent
  (*acc).balance += 10;
  cout << "Account: " << acc->name << " (" << acc->balance << ")" << endl;
}
