# Smart Pointers in C++ 🎮

_Smart pointers_ are a type of pointer that automatically manages the memory of the object it points to, they're pointers with additional functionality and metadata.

## Issues with raw pointers

Raw pointers are error-prone, they can be easily misused and cause a variety of issues

- Memory leaks are common when using raw pointers, as they don't automatically release the memory they point to.
- It's often unclear who owns the memory pointed to by a raw pointer, which can lead to double frees and dangling pointers.
- Raw pointers don't provide any information about the memory they point to, such as its type or size.
- Dangerous bugs can occur with raw pointers, such as UB that doesn't cause a crash, and potentially corrupts data or causes security issues.

To solve these issues, _smart pointers_ were introduced in C++11.

## General

- Smart pointers are basically wrapper classes that contain and manage a raw pointer. They're included in the `<memory>` header.
- They adhere to _RAII_ (_Resource Acquisition Is Initialization_) principles, so they automatically manage the memory they point to.
  - _RAII_ in the context of smart pointers means that the heap memory allocation (the resource acquisition) happens in the constructor (initialization), and the heap memory deallocation happens in the destructor.
- Smart pointers can only point to heap-allocated memory, as they're destroyed when they go out of scope.
- Smart pointers overload the `->` and `*` operators, so they can mostly be used like raw pointers, however pointer arithmetic isn't supported.

## `unique_ptr<T>`

`unique_ptr<T>` is a simple, efficient smart pointer that owns and manages the memory it points to.

- It points to an object of type `T` on the heap, and it ca nbe the only owner of that object, as such, this pointer cannot be assigned or copied, but it **can** be moved.
- When the pointer is destroyed, the object is freed.

```cpp
std::unique_ptr<Account> p1 {new Account {"Larry"}};

// ? The overloaded -> operator is used to access the object's members
p1->deposit(1000);
p1->withdraw(500);

// `delete` is not needed, as the pointer is destroyed when it goes out of scope
```

- The unique_ptr class deleted the `operator=` and copy constructor, so trying to reassign or copy a unique_ptr will result in a compiler error.
- However, unique_ptrs can be moved, so they can be returned from functions and passed as arguments.

## `shared_ptr<T>`

`shared_ptr<T>` is a smart pointer that provides shared ownership of heap objects.

- It points to an object of type `T` on the heap, and it can be one of many owners of that object, as such, this pointer can be assigned, copied, and moved.
- It's handled via a _reference counting_ model, similar to `Rc<T>` in Rust.
- When the reference count of the object reaches 0, the object is freed.

## `weak_ptr<T>`

`weak_ptr<T>` is a smart pointer that provides non-owning "weak" references to heap objects.

- It's always created from a `shared_ptr<T>`, and it can be used to prevent strong reference cycles which could prevent the object from being freed. (Similar to `Rc<T>` and `Weak<T>` in Rust)
- the pointer being _weak_ means that it **doesn't contribute to the reference count of the object**, so it doesn't prevent the object from being freed.
