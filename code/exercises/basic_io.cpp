#include "basic_io.h";

#include <iostream>

using namespace std;

void say_hi() { cout << "Hi Frank!"; }

void sallys_dogs() {
  int x{ 3 };

  cout << "Sally has " << x << " dogs." << endl;
}

// ? Receive inputs via `cin` in a `m d yyyy` format
void date_of_birth() {
  int m{};
  int d{};
  int y{};

  cout << "enter date in m d yyyy: ";
  cin >> m >> d >> y;

  cout << m << " " << d << " " << y << endl;
}

// ? Receive inputs and initialize others
void employee_profile() {
  int age;
  double hourly_wage{ 23.5 };
  string name;

  cout << "Enter name and age: ";

  cin >> name >> age;

  cout << name << " " << age << " " << hourly_wage << endl;
}

void carpet_cleaning_service() {
  const int SMALL_ROOM_COST{ 25 };
  const int LARGE_ROOM_COST{ 35 };
  const double TAX_RATE{ 0.06 };
  const int ESTIMATE_EXPIRY{ 30 };

  // ? {} will initialize it to 0
  int small_rooms{};
  cout << "How many small rooms would you like cleaned? ";
  cin >> small_rooms;

  int large_rooms{};
  cout << "How many large rooms would you like cleaned? ";
  cin >> large_rooms;

  double cost
    = (small_rooms * SMALL_ROOM_COST) + (large_rooms * LARGE_ROOM_COST);
  double tax_cost = cost * TAX_RATE;
  double total = cost + tax_cost;

  cout << "Estimate for carpet cleaning service" << endl;
  cout << "Number of small rooms: " << small_rooms << endl;
  cout << "Number of large rooms: " << large_rooms << endl;
  cout << "Price per small room: $" << SMALL_ROOM_COST << endl;
  cout << "Price per large room: $" << LARGE_ROOM_COST << endl;
  cout << "Cost: $" << cost << endl;
  cout << "Tax: $" << tax_cost << endl;

  cout << "=============================" << endl;
  cout << "Total estimate: $" << total << endl;
  cout << "This estimate is valid for " << ESTIMATE_EXPIRY << " days" << endl;
}