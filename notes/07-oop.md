# Object-Oriented Programming in C++ 🎮

## Structs

_Structs_ are a way to group related data together. They're similar to classes, but they have a few key differences:

- Structs are public by default, whereas classes are private by default.
- Structs don't have access modifiers (public, private, protected).

```cpp
struct Vector3 {
    float x, y, z;
};
```

- Use structs for passive objects with public access, and classes for active objects with private access.
- Avoid declaring methods for structs, as they're not meant to be used for active objects.

## Classes

- In C++, it's common to separate the declaration of a class from its implementation, creating a pattern similar to interfaces.

```cpp
// MyClass.h
class MyClass {
public:
    void my_method();
};

// MyClass.cpp
#include "MyClass.h"

void MyClass::my_method() {
    // ...
}
```

- Derived classes constructors are executed in the order of inheritance, from the base class to the derived class.
- Derived classes destructors are executed in the reverse order of inheritance, from the derived class to the base class.

- the `final` keyword can be used to prevent a class from being inherited from, or a method from being overriden, it can also improve compiler optimization.

```cpp
class MyClass final {
    // ...
};
```

### Abstract Classes

_Abstract classes_ are classes that cannot be instantiated, they're used to provide a common interface for a family of classes.

- Abstract classes are declared by having at least one _pure virtual method_, which are methods that have no implementation.
- The equivalent of an _interface_ in C++ is a class with only pure virtual methods.

```cpp
// Abstract class, no keyword needed
class Shape {
public:
    // ? Pure virtual method
    virtual void draw() = 0;
    virtual void rotate() = 0;
    // NOTE Virtual destructor is needed for polymorphic classes
    virtual ~Shape() {}
};

// Concrete class that derives from `Shape`
class Square : public Shape {
public:
    void draw() override {
        // ...
    }

    void rotate() override {
        // ...
    }
};
```

### `this` pointer

The `this` pointer is a pointer that points to the current object. It contains the address of the object that the method was called on and can only be used in class scope.

- Can be dereferenced (`*this`) to yield the current object.

```cpp
void Account::set_balance(double bal) {
    balance = bal; // `this->balance = bal;` is implied
}

int Account::compare_balance(const Account& other) {
    if (this == &other) {
        std::cout << "Same objects" << std::endl;
    } 
}
```

### Constructors

- _Constructor initialization lists_ are used to initialize member variables before the body of the constructor is executed. This can lead to more efficient code as the default constructors for the member variables are not called.

```cpp
// ? `foo` is initialized before the body of the constructor is executed
MyClass::MyClass(int foo, int bar) : foo { foo } { /* ... */ }
```

- _Delegating constructors_ are constructors that call another constructor of the same class.

```cpp
// ? Invokes the constructor that takes two arguments
MyClass::MyClass() : MyClass{ 0, 0 } { /* ... */ }
```

- _Copy constructors_ are constructors that take a reference to an object of the same class as an argument. They take a _constant reference_ to prevent the object from being modified and then create a copy of the object.
- Objects are _shallow copied_, so raw pointers will point to the same memory address, but member objects will be copied.

```cpp
// ? fn that needs a **copy** of an object
void display(MyClass my_object) { /* ... */ }

// ? fn that returns a **copy** of an object
MyClass create() {
    MyClass my_object;
    return my_object;
}

// ? Copy constructor declaration
MyClass(const MyClass& source);

// ? Copy constructor definition
MyClass::MyClass(const MyClass& source) : { name { source.name }, age { source.age }}  { /* ... */ }
```

- _Move constructors_ are constructors that move the resource of an object into another object. They take an _r-value reference_ to an object of the same class as an argument. They're used to avoid expensive copies and to transfer ownership of resources.

```cpp
// ? fn that needs a **copy** of an object
void display(MyClass my_object) { /* ... */ }

// ? fn that returns a **copy** of an object
MyClass create() {
    MyClass my_object;
    return my_object;
}

// ? Move constructor declaration
MyClass(MyClass&& source);
```

### Destructors

_Destructors_ are special member methods that are called when an object is destroyed.

- They're invoked automatically when an object goes out of scope, or when `delete` is called on a pointer to an object.

- Destructors are useful for releasing resources that were allocated by the object to prevent memory leaks.

```cpp
class Player {
public:
    // ? Constructor
    Player();
    // ? Destructor
    ~Player();
};
```

### Class Friends

_Class Friends_ are functions or classes that are allowed to access private members of a class.

- Class friends are declared using the `friend` keyword.
- Class friends **should be used judiciously** as they can break encapsulation and can make code harder to maintain, some engineers even consider them an anti-pattern.

```cpp
class Player {
private:
    // ? `OtherClass` will have access to private members of `Player`
    friend class OtherClass;

    int health;
    int xp;
public:
    // ...
};
```

### Accessing Members

- Class members (attributes and methods) are private by default.
- Members can be accessed using the `.` operator if they're an object, or the `->` operator if they're a pointer.

```cpp
class MyClass {
public:
    int public_attribute;
};

int main() {
    MyClass my_object;
    my_object.public_attribute = 5;

    MyClass* my_pointer = &my_object;
    my_pointer->public_attribute = 5;
    // Is equivalent to
    // (*my_pointer).public_attribute = 5;
}
```

## Templates

_Templates_ are a feature of C++ that allow you to write generic code that can be used with any type.

- The compiler can use a single template to generate a family of related functions or classes, each using a different set of types.
