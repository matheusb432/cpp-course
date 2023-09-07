#pragma once

namespace linked_list {
    template <typename T>
    struct Node {
        T data;
        Node* next;
    };


    void example();

    template <typename T>
    void print_list(const Node<T>* tail);
}
