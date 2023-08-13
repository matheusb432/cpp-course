# C++ Fundamentals 🎮

- Prefer ‘\n’ over std::endl when outputting text to the console, as endl flushes the buffer after inserting a line break

- The assignment operator returns the value it assigned to, so "x = 5" returns 5.

## The main() function

The `main()` function is the entry point of every C++ program. Starting from _C++11_ onwards, it's possible to omit the `return 0;` statement at the end of the `main()` function.

- A return value of 0 indicates that the program has terminated successfully, while a non-zero return value indicates an error.

- The `main()` function can take two parameters: `argc` and `argv`. `argc` is the number of command-line arguments passed to the program, and `argv` is an array of strings containing the command-line arguments.

## Linker Errors

_Linker errors_ occur when the linker is unable to find the definition of a function or variable that was declared in a different file. A project can still compile successfully even if it contains linker errors, but it won't be able to run.

- For example, if we declare a function in `main.cpp`, but define it in `other.cpp`, the linker will be unable to find the definition of that function, and will throw a _linker error_.

```cpp
extern int x; // Declaration

int main()
{
    std::cout << x << std::endl; // Linker error
    return 0;
}
```

## Operators

- `::` - scope resolution operator, used to access members of a namespace, class, or structure
- `<<` - stream insertion operator, used to insert data into a stream (e.g. `std::cout`)
- `>>` - stream extraction operator, used to extract data from a stream (e.g. `std::cin`)

## Preprocessor Directives

_Preprocessor directives_ are commands that are executed by the preprocessor before the code is compiled. They all start with a `#` symbol.

The _C++ preprocessor_ is a program that processes the source code before it passes through the compiler. It takes the source code as input and produces output that is fed into the compiler.

- The preprocessor does not understand C++ syntax, it only understands preprocessor directives.

- `#include` - used to include the contents of a header file in a source file (e.g. `#include <iostream>`)
- `#define` - used to define a macro (e.g. `#define PI 3.14`)
- `#ifdef` - used to check if a macro is defined (e.g. `#ifdef PI`)

## Namespaces

_Namespaces_ are used to group related code together. They can be used to prevent name collisions, and to organize code into logical groups.

- `std` is the namespace that contains all the standard library functions.

- `using namespace std;` is used to bring **all** the names from the `std` namespace into the current scope, it enables more succinct code, but can be overkill.

```cpp

#include <iostream>

// Before
int main()
{
    std::cout << "Hello World!" << std::endl;

    int some_num;
    std::cin >> some_num;
}

// After
using namespace std;

int main()
{
    // `cout` is already in the current scope
    cout << "Hello World!" << endl;

    int some_num;
    cin >> some_num;
}
```

- `using std::cout;` - used to bring a specific name from the `std` namespace into the current scope. It's generally more ideal than  `using namespace std;`.

```cpp
using std::cout;
using std::endl;
using std::cin;

// ...
```

## Basic I/O

- `cout` - standard output stream, outputs to the console by default
- `cin` - standard input stream, used to read data from the console
  - `cin >> x;` - reads data from the console and stores it in `x`
  - can fail if the input is invalid, errors should be checked with `cin.fail()`
- `cerr` - standard error stream, used to output error messages to the console

## Variables

_Variables_ are an **abstraction for a memory location**. They're are used to store data in memory.

- The `sizeof()` operator can be used to get the size of a variable in bytes.

- The `auto` keyword can be used to automatically deduce the type of a variable from its initializer.

```cpp
// NOTE Syntax for variable initialization
int age = 21; // Copy initialization (or c-like) 
int age(21); // Direct initialization (or constructor)
// * Is often better than copy initialization because it prevents narrowing conversions
int age{ 21 }; // Uniform initialization (or list initialization, introduced in C++11)

auto x = 5; // x is an int
auto y = 5.0; // y is a double
```

- Variables enable moving data in memory in a more convenient way than just using their memory addresses. In _Assembly_, the equivalent of binding to a variable would be moving a value to a memory location (e.g. `mov eax, 5`).

- Initializing variables with `{}` sets them to their default value, so `int x {}` sets x to 0. It's often best practice to do so as reading uninitialized variables can cause UB.

### Constants

_Constants_ are variables whose value cannot be changed after initialization. They are declared with the `const` keyword.

- Constants should be used whenever possible in place of literals, as they make the code more readable and maintainable at no performance cost since they are _inlined_ by the compiler.

```cpp
const int MAX = 100;
```

## Undefined Behavior

_Undefined behavior_ (often abbreviated UB) is the result of executing code whose behavior is not well-defined. (e.g. reading an uninitialized variable)

Code implementing undefined behavior may:

- produce different results every time it is run.
- consistently produces the same incorrect result.
- behave inconsistently (sometimes produces the correct result, sometimes not).
- seem like it’s working but produces incorrect results later in the program.
- crash, either immediately or later.
- work on some compilers but not others.
- work until you change some other seemingly unrelated code.

So basically: _"Undefined behavior is like a box of chocolates. You never know what you’re going to get!"_
