#ifndef APP_DOG_H
#define APP_DOG_H

#include <string>

using std::string;

class Dog {
private:
  string name;
  int age;

public:
  string get_name();
  void set_name(string value);
  int get_age();
  void set_age(int value);
  int get_human_years();
  string speak();
};

#endif