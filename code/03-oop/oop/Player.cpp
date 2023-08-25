#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

void Player::talk(string text) {
  cout << name << "says: " << text << endl;
}

bool Player::is_dead() {
  return this->health <= 0;
}

void Player::set_name(string val) {
  name = val;
}

// NOTE The default constructor is called when no args are passed to the class
Player::Player() {
  cout << "no args ctor" << endl;
}

// NOTE Constructor implementation
Player::Player(string name) {
  this->name = name;
  // ? The object is implicitly created, no value is returned here.
}

// Player::Player(string name, int health, int xp) {
//   this->name = name;
//   this->health = health;
//   this->xp = xp;
// }
// NOTE Constructor initialization list, more efficient than the above
Player::Player(string name_val, int health_val, int xp_val)
    : name{ name_val }, health{ health_val }, xp{ xp_val } {
  cout << "ctor with args" << endl;
}

Player::Player(const Player& source)
    : name{ source.name }, health{ source.health }, xp{ source.xp } {
  cout << "COPY_CTOR: made copy of " << source.name << endl;
}

// NOTE Delegate constructor, calls the above ctor with the specified args
Player::Player(string name, int health) : Player{ name, health, 0 } {}

// NOTE Destructor will be called whenever a Player object is freed memory
Player::~Player() {
  cout << "DTOR: freeing player '" << this->name << "' from memory..." << endl;
}
