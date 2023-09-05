#include "io_demo.h"
#include <iostream>
#include <iomanip>

namespace io_demo {
    void example() {
        // ? `noboolalpha` is the default, shows 1/0 instead of true/false
        std::cout << std::noboolalpha;
        std::cout << "noboolalpha - default true : " << true << std::endl;
        std::cout << "noboolalpha - default false : " << false << std::endl;

        // ? `boolalpha` shows true/false instead of 1/0
        std::cout << std::boolalpha;
        std::cout << "boolalpha - default true : " << true << std::endl;
        std::cout << "boolalpha - default false : " << false << std::endl;

        // ? Displaying numbers as decimals, hex
        std::cout << std::showbase;
        std::cout << "15 as dec: " << std::dec << 15 << std::endl;
        std::cout << "15 as hex: " << std::hex << 15 << std::endl;

        // ? Showing floating point with 2 precision
        std::cout << "PI with default precision: " << 3.14159 << std::endl;
        std::cout << std::setprecision(2);
        std::cout << "PI with precision 2: " << std::fixed << 3.14159 << std::endl;
    }
}
