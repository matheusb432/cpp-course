#pragma once

#include <string>
#include <string_view>

namespace util {
    // ? It's better to use std::string_view instead of a const ref to string
    int get_input(const std::string& prompt);
}
