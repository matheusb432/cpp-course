#include "util.h"
#include "linked_list.h"
#include <iostream>
#include <iomanip>

namespace linked_list {
    void example() {
        const int len{util::get_input("enter the linked list size: ")};
        Node<double> tail{};
        Node<double>* head{&tail};

        for (int i = 0; i < len; ++i) {
            printf("node @ %d -> ", i);
            std::cin >> head->data;
            head->next = static_cast<Node<double>*>(malloc(sizeof(Node<double>)));
            head = head->next;
            head->data = 0;
            head->next = nullptr;
        }

        print_list(&tail);
    }

    template <typename T>
    void print_list(const Node<T>* tail) {
        printf("linked list is: \n");
        while (tail->next != nullptr) {
            std::cout << "| " << tail->data << " | -> ";
            tail = tail->next;
        }
        std::cout << std::endl;
    }
}
