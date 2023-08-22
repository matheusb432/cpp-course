# Object-Oriented Programming in C++ 🎮

## Classes

### Class Friends

_Class Friends_ are functions or classes that are allowed to access private members of a class.

- Class friends are declared using the `friend` keyword.

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
