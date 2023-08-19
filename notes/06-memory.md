# C++ Memory Management 🎮

## Pointers

_Pointers_ are variables that store the address of another variable.

```cpp
int x{ 5 };
int* ptr{ &x }; // ptr is now the address of x
```

- The `&` operator is used to get the address of a variable
- The `*` operator is used to _dereference_ a pointer, it gets the value of the variable it points to.1
- The `nullptr` is the null pointer literal, it's of address 0.

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

## Dynamic Memory Allocation

_Dynamic memory allocation_ is the process of allocating memory at runtime. It's an essential technique for creating data structures.

- To handle vectors, C++ allocates pointers on the stack of a fixed size, that point to dynamic data on the _heap_, this guarantees that the vector's pointer and metadata will always be of the same size, even if it's resized.

- The `new` operator is used to allocate memory on the heap, it returns a pointer to the allocated memory.

```cpp
int* ptr{ new int }; // ptr is now a pointer to an int on the heap
```

## Views

_Views_ are (often) readonly references to objects, they provide non-owning access to data.

- Modifying an object invalidates all _views_ into that object.

## Strings

- Prefer `std::string_view` over std::string when you need a read-only string, especially for function parameters.

- `std::string_view` provides a read-only "view" of a string, similar to an immutable borrow in Rust, while std::string would be the owned version of a string.

- string views are useful for getting substrings from a string without copying data, similar to Rust's &str
