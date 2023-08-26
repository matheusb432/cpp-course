#include "Shallow.h"

#include <iostream>

using namespace std;

Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow& source) : data(source.data) {
    cout << "COPY_CTOR: shallow copy" << endl;
}

Shallow::~Shallow() {
    cout << "DTOR: freeing data..." << endl;
    // NOTE When a shallow copy is made, this causes a double free which leads to UB
    delete data;
}
