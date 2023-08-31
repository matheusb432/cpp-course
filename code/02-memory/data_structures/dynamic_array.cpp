#include <iostream>
#include "util.h"

#include "dynamic_array.h"

namespace dynamic_array {
    void example() {
        const int len{util::get_input("enter the arr len: ")};

        int* arr = static_cast<int*>(malloc(sizeof(int) * len));
        for (int i = 0; i < len; i++) {
            printf("enter value @ %d -> ", i);
            std::cin >> *(arr + i);
        }

        printf("arr is: \n");
        for (int i = 0; i < len; ++i) {
            const int* addr = arr + i;

            printf("%p: %d\n", (void*)addr, *addr);
        }

        free(arr);
    }
}
