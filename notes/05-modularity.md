# C++ Modularity 🎮

C++ can achieve modularity through the use of _namespaces_, _header files_, and _header guards_.

## Namespaces

A _namespace_ is a region that allows you to declare names inside of it for the purpose of disambiguation.

- Any name that is not defined inside a class, function, or a namespace is considered to be part of the global namespace (or global scope).

- It's possible to add `using` directives inside functions for more succinct code.

- `using` directives should never be used in the global namespace of header files.

## Header Files

- Header files from `std` should be included without the `.h` file extension

- Each file should explicitly #include all of the header files it needs to compile. Do not rely on headers included transitively from other headers.

- If your header files are written properly and #include everything they need, the order of inclusion shouldn’t matter.

- Do **not** define variables and functions in header files.

### Header Guards

- _Header guards_ should be used to ensure header files only get defined once.

- Header guards prevent duplicate inclusions because the first time a guard is encountered, the guard macro isn’t defined, so the guarded content is included. Past that point, the guard macro is defined, so any subsequent copies of the guarded content are excluded.

```cpp
#ifndef MY_FILE
#define MY_FILE

// content here

#endif
```

In modern C++, `#pragma once` can be used instead, but it may not work on esoteric platforms:

```cpp
#pragma once

// your code here
```

## Linkage

Variables or functions with _internal linkage_ can only be used within the file that they're declared in. _External linkage_ means they're accessible outside of their file.

- static members have _internal linkage_

- extern members have _external linkage_
