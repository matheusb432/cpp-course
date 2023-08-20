# C++ Advanced Types 🎮

## Views

_Views_ are (often) readonly references to objects, they provide non-owning access to data.

- Modifying an object invalidates all _views_ into that object.

## Strings

- Prefer `std::string_view` over `std::string` when you need a read-only string, especially for function parameters.

- `std::string_view` provides a read-only "view" of a string, similar to an immutable borrow in Rust, while `std::string` would be the owned version of a string.

- _string views_ are useful for getting substrings from a string without copying data, similar to Rust's &str
