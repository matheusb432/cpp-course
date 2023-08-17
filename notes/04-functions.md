# C++ Functions 🎮

- Failure to return a value from a value-returning function will cause UB.

- A parameter without a name is called an _unnamed parameter_, it's useful to indicate that the function won't use the provided arguments:

```cpp
void foo(int);
```

## How Functions Work At a Low Level

- Functions use the _function call stack_ to store their local variables and parameters via a _stack frame_.

When a function is called, the following happens:

1. The function's parameters are pushed onto the stack in reverse order.
2. The function's local variables are pushed onto the stack.
3. The function's code is executed.
4. The function's local variables are popped off the stack in _LIFO_ order.

- If a function allocates too much data on the stack, it can cause a _stack overflow_ since the stack size is finite

- As functions must allocate _stack frames_ to be executed, they have a small amount of overhead. This is why _inline functions_ are useful.

## Function Prototypes

_Function prototypes_, or _Forward Declarations_, they are used to tell the compiler about the existence of a function before it's used.

```cpp
// Declaring the header file
#include "add.h"

int main()
{
    // Function call
    int result{ add(5, 6) };
    return 0;
}

// Function prototype (add.h)
int add(int x, int y);

// Function definition (add.cpp)
int add(int x, int y)
{
    return x + y;
}
```

## Inline Functions

_Inline functions_ are used to avoid the overhead of function calls. They are defined in the header file and are expanded by the compiler.

```cpp
inline int add(int x, int y) { return x + y; }
```

- Inline functions are useful for small functions that are called frequently, but they can cause an increase in the binary size if they are too large.

- Sometimes the compiler inlines functions automatically, this is called _implicit inlining_.
