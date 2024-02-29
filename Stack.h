#pragma once

#include <vector>
#include <iostream>

namespace CS303 {
    class Stack {
    private:
        std::vector<int> items;
    public:
        Stack();
        void push(int value);
        void pop();
        int& top();
        bool empty();
        double average();
        void print();
        ~Stack();
    };
}