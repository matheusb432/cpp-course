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

Player::Player() {
  cout << "no args ctor" << endl;
}

// NOTE Constructor implementation
Player::Player(string name) {
  this->name = name;
  // ? The object is implicitly created, no value is returned here.
}

Player::Player(string name, int health, int xp) {
  this->name = name;
  this->health = health;
  this->xp = xp;
}

// NOTE Destructor will be called whenever a Player object is freed memory
Player::~Player() {
  cout << "DTOR: freeing player '" << this->name << "' from memory..." << endl;
}
