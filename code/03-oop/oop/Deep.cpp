#include "Deep.h"


#include <iostream>
using namespace std;

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

// NOTE This makes a deep copy and allocates memory for the int pointer
Deep::Deep(const Deep& source) : Deep(*source.data) {
    cout << "COPY_CTOR: deep copy" << endl;
}

Deep::~Deep() {
    delete data;
    cout << "DTOR: freeing data..." << endl;
}
