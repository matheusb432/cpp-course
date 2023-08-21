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

- `int8_t` and `u_int8_t` may be interpreted as characters in certain scenarios, to avoid unpredictable bugs, **they shouldn't be used**.

## Type Casting

- Avoid using C-style casts.

### Numeric Promotions

A _numeric promotion_ (or _safe conversion_) is a type conversion of narrower numeric types (e.g. char) to wider numeric types (e.g. int, double) that can be processed efficiently and is less likely to have a result that overflows.

- All numeric promotions are _value-preserving_ - The converted value will always be equal to the source value

### Narrowing conversions

A _narrowing conversion_ is a potentially **unsafe** numeric conversion where the destination type may not be able to hold all the values of the source type.

- This can result in data loss, and happens when converting to narrower types (e.g. float to integral type, double to float, long to int,. ...)

- Avoid narrowing conversions whenever possible.

## Type Aliases

- Name your type aliases starting with a capital letter and do not use a suffix.

- Prefer type aliases over typedefs.

- Use type aliases only when they provide a clear benefit to code quality.

```cpp
// C equivalent
typedef long Distance;
// C++ type alias, is preferred.
using Distance = long;

// Alias for complex type
using VectPairSI = std::vector<std::pair<std::string, int>>
```

## Type Inference

_Type Inference_ (or type deduction) can be used with the `auto` keyword to infer certain types.

- Use type deduction for variables whenever it's equivalent to the inferred type.

- Normal functions should not use type deductions, as it can make for confusing signatures.
