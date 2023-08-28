#include "Account.h"
#include "Player.h"
#include "Shallow.h"
#include "Move.h"
#include <iostream>
#include <string>
#include <vector>

#include "Deep.h"


using namespace std;

void classes_and_objs();
void ctors_and_dtors();
void move_semantics();

int main() {
    classes_and_objs();
    // ctors_and_dtors();
    // move_semantics();
}

void display_some_attr(const Player& p) {
    // NOTE `get_some_attr` must be a const method to be called on a const object 
    cout << p.get_some_attr() << endl;
}

void classes_and_objs() {
    cout << "Player static method call: " << Player::get_num_players() << endl;
    // NOTE By default, uninitialized classes have garbage data for all props
    Player p1;
    Player* p_p1{&p1};

    display_some_attr(p1);

    cout << "Player static method call: " << Player::get_num_players() << endl;

    // ? Accessing object member with the dot operator
    p1.health = 100;
    // ? Accessing object pointer member with the arrow operator
    p_p1->health += 50;
    p1.name = "player 1";

    p1.talk("hello there");
    p_p1->talk("ptr hello there");

    Player hero;

    Player players[]{p1, hero};

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
    auto acc{new Account()};
    acc->name = "My account";
    acc->balance = 1000;

    cout << "Account: " << acc->name << " (" << acc->balance << ")" << endl;
    // ? Equivalent
    acc->balance += 10;
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

// ? Will create a copy of the object and call it's copy constructor
void display_shallow(Shallow s) {
    cout << s.get_data_value() << endl;
}

void display_deep(Deep d) {
    cout << d.get_data_value() << endl;
}

void ctors_and_dtors() {
    {
        // ? These will be freed from memory when the scope ends
        // ? Order will be `p3,p2,p1` since the stack is LIFO
        Player p1{"p1"};
        Player p2{"p2"};
        Player p3{"p3"};

        display_player(p3);
    }

    // ? Valid syntax since the default ctor is defined
    auto enemy = new Player;
    enemy->set_name("Enemy");

    auto level_boss = new Player("Level Boss", 1000, 300);
    level_boss->set_name("Level Boss");

    auto another_enemy = new Player{"Some Enemy", 300};

    display_player(*another_enemy);

    // ? Deleting the objects to call the destructor
    delete enemy;
    delete another_enemy;
    delete level_boss;

    Shallow obj1{100};
    // ! Copying the object will cause a double free
    // display_shallow(obj1);

    Deep obj2{100};
    display_deep(obj2);
}

void move_semantics() {
    vector<Move> vec;

    cout << "vec capacity: " << vec.capacity() << endl;

    // NOTE Will call the move ctor, and only free the memory once even if the vector resizes many times
    // ? The copy ctor also won't be called when the vector resizes.
    vec.push_back(Move{10});
    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});

    cout << "vec capacity: " << vec.capacity() << endl;
}
