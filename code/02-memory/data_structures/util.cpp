#include "util.h"
#include <string>
#include <string_view>
#include <iostream>


namespace util {
    int get_input(const std::string& prompt) {
        int input{};
        while (true) {
            std::cout << prompt;
            std::cin >> input;

            // NOTE Initializing a variable in a conditional is a C++17 feature. (why though?)
            if (const bool did_fail = std::cin.fail(); !did_fail) {
                break;
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input - Must be an integer\n";
        }
        return input;
    }
}
