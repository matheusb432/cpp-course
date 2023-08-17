# C++ Types 🎮

## Primitive Types

_Primitive types_ are the most basic types in C++. They are the building blocks for all other types. Some of them are:

- _character types_ - are used to represent characters (e.g. `char`, `wchar_t`).
- _numerical integer types_ - are used to represent integers (e.g. `int`, `long`, `short`, `long long`) and their unsigned counterparts (e.g. `unsigned int`, `unsigned long`, ...).
- _floating-point types_ - are used to represent real numbers (e.g. `float`, `double`, `long double`).

- **The size and precision of the types is often compiler-dependent**. The `sizeof()` operator can be used to get the size of a type in bytes.

- `size_t` is a platform-dependent unsigned integer. (like `usize` in Rust)

- Signed integer overflow results in UB. While unsigned integer overflows results in _modulo wrapping_

- Favor **signed numbers over unsigned numbers**, and avoid mixing signed with unsigned in operations, as unexpected and hard to debug bugs often happen.

- Favor **double over float** unless space is at a premium, as the lack of precision in a float will often lead to inaccuracies.
