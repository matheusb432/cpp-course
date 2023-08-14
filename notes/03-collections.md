# C++ Collections 🎮

## Arrays

_Arrays_ are used to store an indexed collection of elements of the same type. They're data structures with a **fixed size** that are stored in the _stack_ by default.

- Arrays are stored in **contiguous memory** and are very efficient in terms of memory usage.

- The size of an array must be known at compile-time, however, it can have in-place mutations.

- Arrays do not have any built-in _bounds checking_. **Accessing an element outside of the bounds of an array results in UB**.

```cpp
// ? Syntax for array initialization
int arr[5] { 1, 2, 3, 4, 5 };
int high_scores[10] { 3, 5 }; // The rest of the elements are initialized to 0

int another_arr[] { 1, 2, 3 }; // size is 3
```

## Vectors

_Vectors_ are used to store an indexed collection of elements of the same type. They're data structures with a **dynamic size** that are stored in the _heap_ by default.

- Vectors are also stored in **contiguous memory**, however, they can be _resized_ at runtime whenever values are added or removed.
  - **Vector resizing is an expensive operation**, because it requires allocating a new block of memory and copying the elements from the old block to the new one.

- Vectors are an OOP abstraction (a _template class_) over arrays. They have a lot of useful methods and are generally easier to work with than arrays.

- Vectors have built-in _bounds checking_ via the `at()` method. **Accessing an element outside of the bounds of a vector results in an exception**.
  - Accessing elements using the `[]` operator doesn't perform bounds checking.

```cpp
using std::vector;

// ? Syntax for vector initialization
vector<int> vec { 1, 2, 3, 4, 5 };

vector<int> another_vec; // empty vector
vector<int> another_vec2(5); // vector with 5 elements, all initialized to 0
```
