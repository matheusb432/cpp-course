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

- The `new` operator is used to allocate memory on the heap, it returns a pointer to the allocated memory.

```cpp
int* ptr{ new int }; // ptr is now a pointer to an int on the heap
```

## References

_References_ are aliases for variables. They're used to pass variables to functions without copying them.

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
