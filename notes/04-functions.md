# C++ Functions 🎮

- Failure to return a value from a value-returning function will cause UB.

- A parameter without a name is called an _unnamed parameter_, it's useful to indicate that the function won't use the provided arguments:

```cpp
void doSomething(int)
{
}
```

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
