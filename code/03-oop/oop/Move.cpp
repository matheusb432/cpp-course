#include "Move.h"

#include <iostream>
using namespace std;

Move::Move(Move&& source) : data(source.data) {
    // NOTE It's important to null the source pointer, as it's now a dangling pointer
    source.data = nullptr;
}
