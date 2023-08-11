#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// ? Global variables can be accessed and mutated anywhere in the program
int global_var{ 10 };

// TODO move each section into its own file
int main() {
  // Variables

  cout << "Global var: " << global_var << endl;

  // ? Different ways to initialize variables
  int x = 5;
  int y(10);
  int z{ 20 };

  int age;

  // ! Acessing unintialized memory causes undefined behavior (UB)
  // cout << age << endl;

  cout << "Enter the width of the room: ";
  int room_width{ 0 };
  cin >> room_width;

  cout << "Enter the length of the room: ";
  int room_length{ 0 };
  cin >> room_length;

  cout << "The area of the room is " << room_width * room_length << "m"
       << endl;

  // Variables
}