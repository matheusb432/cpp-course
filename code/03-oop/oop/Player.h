#pragma once

#include <iostream>
#include <string>

using namespace std;

class Player {
private:
public:
  string name;
  int health;
  int xp;

  void talk(string text);
  bool is_dead();
  void set_name(string val);
  // NOTE Default constructor args
  // Player(string name = "None", int health = 100, int xp = 0);
  Player();
  Player(string name);
  Player(string name, int health);
  Player(string name, int health, int xp);
  // NOTE Copy constructor, gets called when a Player object is copied
  Player(const Player& source);

  ~Player();
};
