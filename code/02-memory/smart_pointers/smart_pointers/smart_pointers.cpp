#include "Account.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

void unique_ptrs();
void shared_ptrs();
void weak_ptrs();

int main() {
    // unique_ptrs();
    // shared_ptrs();
    weak_ptrs();
}

void unique_ptrs() {
    vector<unique_ptr<int>> ptrs;

    unique_ptr<int> ptr_a{new int{100}};
    // NOTE `make_unique` is a better way to create a unique_ptr
    auto ptr_b = make_unique<int>(200);
    auto ptr_c = make_unique<int>(250);

    // ! Causes compiler error since a unique_ptr can't be copied
    // ptrs.push_back(ptr);
    // ? `move` is used to transfer ownership of the pointer to the vector
    ptrs.push_back(std::move(ptr_a));
    ptrs.push_back(std::move(ptr_b));
    ptrs.push_back(std::move(ptr_c));

    // ! Causes compiler error since a unique_ptr can't be copied
    // for (auto val_ptr : ptrs) {
    // NOTE unique_ptr *must* be passed by reference to loops or functions
    for (const auto& val_ptr : ptrs) {
        cout << *val_ptr << endl;
    }

    unique_ptr<Account> acc_p1{new Account{100}};
    // NOTE The `make_unique` arguments are passed to the `Account` constructor
    auto acc_p2 = make_unique<Account>(250);

    // ? The overloaded -> operator is used to access the object's members
    cout << "Balance: " << acc_p1->get_balance() << endl;
    acc_p1->deposit(1000);
    acc_p1->withdraw(500);
    cout << "Balance: " << acc_p1->get_balance() << endl;

    // ? `delete` is not needed, as the pointer is destroyed when it goes out of scope
}

void shared_ptrs() {
    // shared_ptr<int> p1{new int{100}};
    // NOTE Creating a shared_ptr with `make_shared` 
    auto p1 = make_shared<int>(100);
    cout << "shared_ptr count = " << p1.use_count() << endl;
    cout << "*p1 = " << *p1 << endl;
    cout << "p1 = " << p1 << endl;

    {
        // NOTE Initializing a shared_ptr with another shared_ptr increases the reference count
        shared_ptr<int> p2{p1};

        // ? p2 points to the same address as p1, so this mutates the same object
        *p2 += 50;
        cout << "shared_ptr count = " << p1.use_count() << endl;
    }

    cout << "shared_ptr count = " << p1.use_count() << endl;
    cout << "*p1 = " << *p1 << endl;

    // NOTE shared_ptr::reset() decrements the reference count and deletes the object if the count is 0
    p1.reset();

    cout << "shared_ptr count = " << p1.use_count() << endl;
    // ? p1 is now a `nullptr` (address 0)
    cout << "p1 = " << p1 << endl;
}

class B;


class A {
    shared_ptr<B> b_ptr;

public:
    void set_b(shared_ptr<B>& b) {
        b_ptr = b;
    }

    A() {
        cout << "A constructor" << endl;
    }

    ~A() {
        cout << "A destructor" << endl;
    }
};

class B {
    // NOTE Using a weak_ptr prevents a circular reference memory leak
    weak_ptr<A> a_ptr;

public:
    void set_a(shared_ptr<A>& a) {
        a_ptr = a;
    }

    B() {
        cout << "B constructor" << endl;
    }

    ~B() {
        // ? Won't every be called if `a_ptr` is a `shared_ptr`
        cout << "B destructor" << endl;
    }
};

void weak_ptrs() {
    auto a = make_shared<A>();
    auto b = make_shared<B>();
    a->set_b(b);
    // ? `a` gets inferred as a `weak_ptr`
    b->set_a(a);
}
