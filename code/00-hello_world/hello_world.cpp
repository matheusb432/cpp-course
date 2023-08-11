// ? Preprocessor directive to add the standard input/output stream library.
#include <iostream>

// NOTE to compile run "g++ hello_world.cpp -o hello_world.exe" on a CLI, then run "hello_world.exe"
int main() {
    // ? Writing to the standard output stream.
    std::cout << "Hello World!" << std::endl;

    int a, b;

    std::cout << "Enter two integers: " << std::endl;

    // ? Reading two inputs from cin at once, user input must be separated by a space so the buffer is cleared.
    std::cin >> a >> b;

    // NOTE This will result in undefined behavior (UB) if `a` or `b` are not integers.
    // ? In more detail, if the user enters a non-integer value, the input stream will be in a failed state.
    // ? So std::cout will try to access memory that it shouldn't, which is UB.
    std::cout << "a: " << a << " & b:" << b << std::endl;

    double c;

    std::cout << "Enter a double: " << std::endl;

    std::cin >> c;

    std::cout << "c: " << c << std::endl;

    // ? Starting from C++11, this line can be omitted.
    return 0;
}