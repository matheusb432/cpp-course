#include "dynamic_array.h"
#include "util.h"
#include "linked_list.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <vector>

// NOTE Alternate function syntax, equivalent to `double fifth_of_val(..)`
auto fifth_of_val(const int x) -> double {
    return x / 5.0;
}

template <typename T>
class Multiplier {
    T num{};

public:
    Multiplier(int n): num{n} {
    }

    // NOTE Creating a functor (function object) via operator overloading
    int operator()(int n) const {
        return n * num;
    }
};

// NOTE Accepting a lambda as a parameter
void exec_lambda_twice(const std::function<void(int)>& fn) {
    fn(1);
    fn(2);
}

int main() {
    // dynamic_array::example();
    // linked_list::example();

    exec_lambda_twice([](const int x) {
        std::cout << "Exec from lambda: " << x << std::endl;
    });

    // NOTE std::map is a red-black tree, works like a hash map
    std::map<std::string, double> hash_map{
        {"Hello", 30.5},
        {"World", 532.1}
    };

    std::cout << "@ Hello: " << hash_map.at("Hello") << std::endl;
    // NOTE Type must be a const reference to avoid copying
    for (const auto& kvp : hash_map) {
        std::cout << kvp.first << " -> " << kvp.second << std::endl;
    }

    std::vector<int> vec1{1, 2, 3, 4, 5};

    auto print_val = [](const double x) {
        std::cout << x << "\t";
    };

    std::cout << "vec1:" << std::endl;
    // NOTE Using STL algorithms with closures
    // NOTE using `cbegin()` gets a const iterator, won't allow you to modify the container
    std::for_each(vec1.cbegin(), vec1.cend(), print_val);
    std::cout << std::endl;
    const Multiplier<int> doubler{2};
    std::cout << doubler(10) << std::endl;

    // ? Passing a functor to `std::ranges::transform`
    std::ranges::transform(vec1, vec1.begin(), doubler);
    std::cout << "Doubled:" << std::endl;
    std::ranges::for_each(vec1, print_val);
    std::cout << std::endl;

    // NOTE Creating a new vector by initializing it with a range, then setting each value
    std::vector<double> new_vec(vec1.size());
    std::ranges::transform(vec1.cbegin(), vec1.cend(), new_vec.begin(), [](const int x) {
        return x + 10;
    });
    std::cout << "Added 10:" << std::endl;
    std::ranges::for_each(new_vec, print_val);
    std::cout << std::endl;

    int idx{};
    // NOTE capturing by reference with `[&]`
    std::ranges::for_each(std::as_const(vec1), [&](const int x) {
        new_vec[idx] *= 5;
        idx++;
    });
    std::cout << "Multiplyied by 5:" << std::endl;
    std::ranges::for_each(new_vec, print_val);
    std::cout << std::endl;

    // NOTE Creating a new vector from mapping an existing one
    std::vector<double> mapped_vec{};

    std::ranges::transform(std::as_const(vec1),
                           // ? `back_inserter` is a function that returns an iterator that inserts at the end of a container
                           std::back_inserter(mapped_vec),
                           // ? Passing a function pointer to as the closure
                           fifth_of_val);
    std::cout << "Mapped vector with fifth of doubled values:" << std::endl;
    std::ranges::for_each(mapped_vec, print_val);
    std::cout << std::endl;
}
