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
4. The function's local variables are popped off the stack in _LIFO_ order
    > This is also called _stack unwinding_
5. Finally, the function's return value is placed in a register if it exists.

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

## Recursive Functions

_Recursive functions_ are functions that call themselves. Their behavior in C++ is much like in other languages.

- Using recursion are often more expensive than using loops due to the overhead of allocating stack frames and the compiler not being able to optimize them easily. If performance is critical, their behavior can be replicated using loops.

## Lambdas

_Lambdas_ (or _closures_) are anonymous functions that capture their environment.

- lambdas are preferred over normal functions when we need a trivial, one-off function to pass as an argument to some other function.

- The captured variables of a lambda are **clones** of the outer scope variables, not the actual variables.
- By default, variables are captured by `const` value, so they're immutable unless the `mutable` keyword is added after the closure's parameters.

> the captured variables will still only be mutable for the closure's scope, the original variable will not be mutated.

- To mutate a captured variable, it should be passed by reference `&`.

- _Default captures_ can be used to auto generate a list of captures for the closure.

```cpp
int health{ 33 };
int armor{ 100 };
std::vector<CEnemy> enemies{};

// Capture enemies by reference and everything else by value.
[=, &enemies](){};

// Capture armor by value and everything else by reference.
[&, armor](){};
```
