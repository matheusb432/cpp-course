# C++ Memory Management 🎮

- _Memory leaks_ are also called _orphaned memory_.

## Pointers

_Pointers_ are variables that store the address of another variable.

```cpp
int x{ 5 };
int* ptr{ &x }; // ptr is now the address of x
```

- The `&` operator is used to get the address of a variable
- The `*` operator is used to _dereference_ a pointer, it gets the value of the variable it points to.1
- The `nullptr` is the null pointer literal, it's of address 0.

- Avoid using void pointers (`void*`) as they effectively allow you to avoid type checking.
- Avoid using pointers to pointers as they're complex and dangerous.

### Pointer Arithmetic

_Pointer arithmetic_ is the process of adding or subtracting an integer to a pointer.

```cpp
int x{ 5 };
int y{ 6 };

int* ptr{ &x };
int* ptr2{ &y };
ptr++; // ptr is now the address of y

bool b{ ptr == ptr2 }; // true
ptr--; // ptr is now the address of x

b = ptr == ptr2; // false
```

- Incrementing/Decrementing should only be used with pointers that point to an array, or the address of a variable.

- Pointer equality can be used to see if two references point to the same variable.

### Consts and Pointers

- A `const` pointer to a variable can't have it's reference changed, and a pointer `const` variable can't have it's value changed.

```cpp
int x{ 5 };

int *const ptr{ &x }; // ptr is a const pointer to an int
*ptr = 6; // valid
ptr = &y; // invalid

const int *ptr2{ &x }; // ptr2 is a pointer to a const int
*ptr2 = 6; // invalid
ptr2 = &y; // valid

const int *const ptr3{ &x }; // can't change the value or reference
```

### Dangling Pointers

_Dangling pointers_ are pointers that point to invalid memory, such as freed memory or memory that's out of scope.

```cpp
int* ptr{ new int{ 5 } };
delete ptr;
*ptr = 6; // undefined behavior
```

## Dynamic Memory Allocation

_Dynamic memory allocation_ is the process of allocating memory at runtime. It's an essential technique for creating data structures.

- To handle vectors, C++ allocates pointers on the stack of a fixed size, that point to dynamic data on the _heap_, this guarantees that the vector's pointer and metadata will always be of the same size, even if it's resized.

## `new` operator

The `new` operator is used to allocate memory on the heap, it returns a pointer to the allocated memory.

```cpp
int* ptr{ new int }; // ptr is now a pointer to an int on the heap
```

- **Operator new can fail** - When requesting memory from the operating system, in rare circumstances, the operating system may not have any memory to grant the request with. When this happens C++ throws an exception, or, if specified, returns a `nullptr`.

## `delete` operator

The `delete` operator does not actually delete anything. It simply **returns the memory being pointed to back to the operating system**.

```cpp
int* ptr{ new int{ 5 } };
delete ptr; // ptr is now a dangling pointer
```

- After freeing a pointer, a best practice it to immediately set it to `nullptr` afterwards.
- Deleting a null pointer (`nullptr`) is ok, and does nothing. However, if a pointer is freed and not set to `nullptr`, deleting it causes UB.

## References

_References_ are aliases for variables. They're used to pass variables to functions without copying them.

- **references are not objects in C++**. A reference is not required to exist or occupy storage. If possible, the compiler will optimize references away by replacing all occurrences of a reference with the referent.

```cpp
vector<string> stooges{ "Larry", "Moe", "Curly" };

// `str` is a copy of the string on each iteration,
// leading to inneficient code and not modifying the original vector
for (auto str : stooges) {
    str = "Funny"; 
}

// `&str` is a reference to the string on each iteration
for (auto &str : stooges) {
    str = "Funny"; // modifies the original vector
}

// `const` makes it a read-only reference
for (auto const &str : stooges) {
    cout << str << endl;
}
```

- References are a safer way to pass pointers to functions, as they can't be `nullptr` and are still as efficient as pointers.
- References can be thought of as _constant pointers_ that are automatically dereferenced.

## L-Values & R-Values

_L-values_ and _R-values_ are terms used to describe the addressability of values. They're named after their usage in the assignment operator (Left and Right side)

- _L-values_ are values that have an address - e.g. variables or references.

- _R-values_ are values that don't have an address - e.g. literals or temporary values.

```cpp
// x is an l-value & 5 is an r-value
int x{ 5 };
// y is an l-value & x + 5 is an r-value
int y{ x + 5 };
```

## Pass by Copy vs Pass by Reference

At a low level, **everything is passed by value** (copy) - passed references either alias the object, or are pointers, and pointers are just the value of an address in memory (e.g. 0x1000), so copying the address values, (4/8 bytes on 32/64-bit systems, respectively), is always more expensive than creating a new value of a cheap type, such as a char that's 1 byte, int that's 2 or 4 bytes and so on. Not to mention the indirection overhead, too, so at copying types that are slightly bigger than pointers is still more efficient overall.

- As a good rule of thumb: **An object is cheap to copy if it uses 2 or fewer “words” of memory** (where a “word” is approximated by the size of a memory address) and it has no setup costs.

> if `sizeof(T) <= 2 * sizeof(void*)`, then T is 2 or fewer words of memory.

- **Prefer pass by value for objects that are cheap to copy, and pass by const reference for objects that are expensive to copy**. If you’re not sure whether an object is cheap or expensive to copy, favor pass by const reference.

- This is also why `string_view` is preferred over `const string&`, it's inexpensive to copy string_view as it has around 2 words of memory, and accessing it directly is faster than the double indirection with the reference to a string.

## Return by reference

- Static variables can be returned by a const reference, basically creating singletons, like so:

```cpp
const string& getProgramName()
{
    static const std::string s_programName { "Calculator" }; // has static duration, destroyed at end of program

    return programName;
}
```

- Avoid returning references to non-const local static variables.

## Shallow vs Deep Copy

In C++, objects are _shallow copied_ by default, meaning that pointers will point to the same memory address, but member objects will be copied.

- _Shallow copy_, or _memberwise copy_, is the process of copying the members of an object to another object. It's the default behavior of the copy constructor and assignment operator.
- C++'s shallow copying behavior is slightly different from some higher-level languages, where objects are not copied in shallow copies, but rather referenced.

- _Deep copying_ is the process of copying the members and the data of objects that pointers point to. It's not recommended to use raw pointers as member variables, as it can lead to increase complexity and memory leaks.

```cpp
class Shallow {
private:
    int* data;

};
```

## Move Semantics

_Move semantics_ is the process of moving resources from one object to another. It's used to avoid expensive copies and to transfer ownership of resources.

- Copy constructors deep copying can have a significant performance impact when copying large objects, so _Move constructors_ are used to move an object's resources into another.
- C++ compilers may optimize copying away by using _copy elision_, this can be extremely efficient.
- _r-value references_ are used in move semantics, they're references that can only bind to r-values.
