# C++ Advanced Types 🎮

## Views

_Views_ are (often) readonly references to objects, they provide **non-owning access to data**.

- Modifying an object invalidates all _views_ into that object.

## Strings

- Prefer `std::string_view` over `std::string` when you need a read-only string, especially for function parameters.

- `std::string_view` provides a **read-only "view" of a string**, similar to an immutable borrow in Rust, while `std::string` would be the owned version of a string.

- _string views_ are useful for getting substrings from a string without copying data, similar to Rust's &str

## Enumerations

_Enumerations_ or _enums_ are a type that models a set of constant integral values.

- Enums are useful for improving readability and type safety at no runtime cost.
- Enums have implicit initialization, starting at 0 and incrementing by 1 for each value.
- _anonymous enums_, which are enums without names, are useful for defining constants, similar to Rust's `const` keyword, but they provide no type safety.

```cpp
int state;
std::cin >> state;

// Without enums, these are confusing magic numbers
if (state == 0) { ... } 
else if (state == 1) { ... } 
else if (state == 2) { ... }

// With enums, these are clear and readable
enum State { EngineFailure, InclementWeather, Nominal };

int user_input;
std::cin >> user_input;
State state = State(user_input);

if (state == EngineFailure) { ... } 
else if (state == InclementWeather) { ... } 
else if (state == Nominal) { ... }
```

### Unscoped Enums

_Unscoped enums_ are enums that are not scoped to a class or namespace.

- Unscoped enums are implicitly convertible to their underlying type, which is `int` by default.
- Unscoped enums are not type safe, and can be compared to any integer value.

```cpp
// Unscoped enum example
enum State { EngineFailure, InclementWeather, Nominal };
```

### Scoped Enums

_Scoped enums_ are enums that are scoped to a class or namespace.

- Scoped enums are not implicitly convertible to their underlying type, and must be explicitly casted.
- Scoped enums are type safe, and can only be compared to values of the same enum type.

```cpp
// `class` keyword makes this a scoped enum
enum class State { EngineFailure, InclementWeather, Nominal };
enum class Action : int { Idle, Accelerate, Decelerate };
```

## Structs

_Structs_ are a compound data type that groups together variables of different types.

- It's best to provide a default value for all members. This ensures that your members will be initialized even if the variable definition doesn’t include an initializer list.

- The size of a struct is not always the sum of the size of all its members, this is due to _padding_ as it reinforces memory alignment in contiguous memory word-sized blocks (32 bits or 64 bits depending on CPU).

```cpp
// Foo1 can have size 12
struct Foo1
{
    short a{}; // will have 2 bytes of padding after a
    int b{};
    short c{}; // will have 2 bytes of padding after c
};

// Foo2 can have size 8
struct Foo2
{
    int b{};
    short a{};
    short c{};
};
```
