#include <iostream>
#include <vector>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;

void basics();
void dynamic_mem();
void pass_by_ref();
void ref_return();
void refs();

int main() {
  // basics();
  // dynamic_mem();
  // pass_by_ref();
  // ref_return();
  refs();
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

void double_data(int *i_ptr);

// ! It's better to pass by reference than by pointer
void double_data(int *i_ptr) {
  *i_ptr *= 2;
}

// NOTE Best practice is to use references instead of pointers for fns
void double_data_ref(int &i_ref) {
  i_ref *= 2;
}

void pass_by_ref() {
  int value{ 10 };
  int *i_ptr{};

  cout << "value: " << value << endl;
  // NOTE simply passing the reference is equivalent to passing the pointer
  double_data(&value);
  // NOTE Passing by reference is implicitly dereferenced
  double_data_ref(value);
  cout << "value after double_data & double_data_ref: " << value << endl;

  i_ptr = &value;

  double_data(i_ptr);
  // NOTE It's not possible to pass a pointer as a reference argument
  // ? This leads to safer code as pointers can point to invalid memory
  // double_data_ref(i_ptr);

  cout << "value: " << value << endl;
}

int *largest(int *i_ptr1, int *i_ptr2);
int *create_arr(size_t size, int init_val = 0);

// ? Returning a pointer from a function
// NOTE ! NEVER return a pointer to a local variable as
// they'll be deallocated once the function stack frame is popped
int *largest(int *i_ptr1, int *i_ptr2) {
  return *i_ptr1 > *i_ptr2 ? i_ptr1 : i_ptr2;
}

int *create_arr(size_t size, int init_val) {
  int *arr_ptr{};

  // NOTE `new int[size]` allocates an array of ints on the heap
  // ? If `size` is 10, this allocates 4 * 10 = 40 bytes
  arr_ptr = new int[size];

  for (size_t i = 0; i < size; i++) {
    // ? Both *(arr_ptr + 1) and arr[i] are equivalent
    //*(arr_ptr + i) = init_val;
    arr_ptr[i] = init_val;
  }

  // ? It's valid to return a pointer to heap allocated memory
  // ! It must be manually freed with `delete[]` or a memory leak will occur
  return arr_ptr;
}

void ref_return() {
  int x{ 10 };
  int y{ 15 };

  // ! This compiles but will cause a runtime error, it would not compile if
  // the arguments were references
  // int *will_crash{ largest(&x, nullptr) };

  int *largest_ptr{ largest(&x, &y) }; // returns pointer to y

  cout << "largest is: " << *largest_ptr << endl;

  int arr_size = 10;
  int *new_arr = create_arr(arr_size, 5);

  for (size_t i = 0; i < arr_size; i++) {
    cout << "*(new_arr + " << i << " ) is " << *(new_arr + i) << endl;
  }

  // ! The heap memory must be freed to not cause a memory leak
  delete[] new_arr;
}

void refs() {
  int x{10};
  int &ref{x};

  x = 15;

  cout << "x: " << x << endl;
  cout << "ref: " << ref << endl;

  // ? Changing the value of the reference will change the value of the variable and vice versa
  ref = 20;

  cout << "x: " << x << endl;
  cout << "ref: " << ref << endl;


}