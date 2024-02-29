#pragma once
#include <iostream>
#include <cstddef>

namespace CS303 {
    template <typename Item_Type>
    class List {
    private:
        struct Node {
            Item_Type data;
            Node* next;
        };
        Node* head;
        Node* tail;
        size_t num_items;
    public:
        List();
        void push_front(Item_Type value);
        void push_back(Item_Type value);
        void pop_front();
        void pop_back();
        int& front();
        int& back();
        bool empty();
        void insert(std::size_t index, const Item_Type& item);
        bool remove(std::size_t index);
        size_t find(const Item_Type& item);
        void print();
        ~List();
    };
}

#include "List_impl.h"