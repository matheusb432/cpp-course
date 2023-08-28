#include "Move.h"

#include <iostream>
using namespace std;

Move::Move(int d) {
    data = new int;
    *data = d;
    cout << "CTOR: " << *data << endl;
}

Move::Move(const Move& source) : Move(*source.data) {
    cout << "COPY_CTOR: deep copy for: " << *data << endl;
}

Move::~Move() {
    if (data != nullptr) {
        cout << "DTOR: freeing data for: " << *data << endl;
    } else {
        cout << "DTOR: nullptr in data" << endl;
    }
    delete data;
}

// NOTE Move constructor with the `noexcept` keyword
Move::Move(Move&& source) noexcept : data(source.data) {
    // NOTE It's important to null the source pointer or else a double free happens
    source.data = nullptr;
    cout << "MOVE_CTOR: moving resource: " << *data << endl;
}
