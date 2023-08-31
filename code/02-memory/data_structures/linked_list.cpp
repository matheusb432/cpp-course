#include <iostream>
#include "util.h"

#include "linked_list.h"

namespace linked_list {
    void example() {
        int len{util::get_input("enter the linked list size: ")};
        Node tail{};
        Node* head{&tail};

        for (int i = 0; i < len; ++i) {
            printf("node @ %d -> ", i);
            std::cin >> head->data;
            head->next = (Node*)malloc(sizeof(Node));
            head = head->next;
            head->data = 0;
            head->next = nullptr;
        }

        printf("linked list is: \n");
        Node* curr{&tail};
        while (curr->next != nullptr) {
            printf("| %d | -> ", curr->data);
            curr = curr->next;
        }
        std::cout << std::endl;
    }
}
