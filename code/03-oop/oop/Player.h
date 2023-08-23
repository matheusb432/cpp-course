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
  Player();
  Player(string name);
  Player(string name, int health, int xp);

  ~Player();
};