#include <iostream>
#include <vector>
#include <string>

using std::endl;
using std::string;
using std::vector;

void basics();
void dynamic_mem();

int main() {
  // basics();
  dynamic_mem();
}

void basics() {
  int x{ 5 };
  int y{ 10 };
  double z{ 3.15 };
  vector<string> vec{ "hello", "worlddd" };
  // NOTE pointers  MUST be initialized or else they will point to garbage
  int *ptr{};
  // NOTE nullptr is address 0, and the default initialization for pointers
  // ? Dereferencing a null pointer will cause a runtime error
  double *ptr2{ nullptr };
  vector<string> *ptr3{ nullptr };

  std::cout << "ptr: " << ptr << endl;
  std::cout << "ptr2: " << ptr2 << endl;
  std::cout << "&x: " << &x << endl;

  std::cout << "assigning ptr to &x..." << endl;
  ptr = { &x };
  std::cout << "assigning ptr3 to &vec..." << endl;
  ptr3 = &vec;

  std::cout << "ptr: " << ptr << endl;
  std::cout << "*ptr: " << *ptr << endl;

  // NOTE Raw pointers have the same size regardless of what they point to
  std::cout << "sizeof(ptr): " << sizeof(ptr) << endl;
  std::cout << "sizeof(ptr2): " << sizeof(ptr2) << endl;
  std::cout << "sizeof(ptr3): " << sizeof(ptr3) << endl;

  std::cout << "sizeof(*ptr): " << sizeof(*ptr) << endl;
  std::cout << "sizeof(*ptr2): " << sizeof(*ptr2) << endl;
  // ? As `vector<string>` is itself a pointer, it's size will also be the same
  // no matter how many elements it contains
  std::cout << "sizeof(*ptr3): " << sizeof(*ptr3) << endl;

  std::cout << "Increment *ptr by 10..." << endl;
  // ? Changing the value of the pointer's data
  *ptr += 10;

  std::cout << "x: " << x << endl;

  std::cout << "assigning ptr to &y...." << endl;
  // ? Changing what data `ptr` points to
  ptr = &y;

  std::cout << "ptr: " << ptr << endl;
  std::cout << "&z:" << &z << endl;
}

void dynamic_mem() {
  int *int_ptr{};
  // NOTE `new int` allocates an int on the heap
  int_ptr = new int;
  std::cout << int_ptr << endl;

  *int_ptr = 100;
  std::cout << "100 *int_ptr: " << *int_ptr << endl;

  // NOTE By losing a reference to heap allocated memory, the data on the
  // heap cannot be freed, creating a memory leak.
  // int_ptr = nullptr;

  // NOTE To free the memory, we must use `delete`
  delete int_ptr;
  // ! Past this point, the pointer is now invalid and accessing it will cause UB

  size_t size{};
  std::cout << "How many ints do you want to allocate? ";
  std::cin >> size;

  // ? Allocating an array on the heap
  int *arr_ptr{ new int[size] };

  for (size_t i{ 0 }; i < size; i++) {
    arr_ptr[i] = 10 + i;
  }

  std::cout << "allocated array: " << endl;
  for (size_t i{ 0 }; i < size; i++) {
    // ? Indexing offsets the pointer by the amount of bytes needed to store
    // it's data, as this is an int pointer, it will offset by 4 bytes
    std::cout << "&arr_ptr[" << i << "]: " << &arr_ptr[i];
    std::cout << " ";
    std::cout << "arr_ptr[" << i << "]: " << arr_ptr[i] << endl;
  }
  std::cout << endl;

  /* * Actual result example, moving 4 bytes in contiguous memory:
    &arr_ptr[0]: 000001B89E373B00 arr_ptr[0]: 10
    &arr_ptr[1]: 000001B89E373B04 arr_ptr[1]: 11
    &arr_ptr[2]: 000001B89E373B08 arr_ptr[2]: 12
    &arr_ptr[3]: 000001B89E373B0C arr_ptr[3]: 13
    &arr_ptr[4]: 000001B89E373B10 arr_ptr[4]: 14
  */

  // ? Dereferencing the pointer will return the first element of the array
  std::cout << "*arr_ptr:" << *arr_ptr << endl;
  // ? Pointer arithmetic can be used instead of indexing
  std::cout << "*(arr_ptr + 1): " << *(arr_ptr + 1) << endl;
  std::cout << "*(arr_ptr + 2): " << *(arr_ptr + 2) << endl;

  delete[] arr_ptr;
}