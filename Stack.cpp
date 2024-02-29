#include "Stack.h"

using namespace CS303;

CS303::Stack::Stack() {
}

void Stack::push(int value) {
    items.push_back(value);
}

void Stack::pop() {
    items.pop_back();
}

int& Stack::top() {
    return items.back();
}

bool Stack::empty() {
    return items.empty();
}

double Stack::average() {
    double sum = 0;
    for (std::size_t i = 0; i < items.size(); i++) {
        sum += items[i];
    }
    return sum / items.size();
}

void Stack::print() {
    for (std::size_t i = 0; i < items.size(); i++) {
        std::cout << items[i] << " ";
    }
    std::cout << std::endl;
}

Stack::~Stack() {
}