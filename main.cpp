#include "List.h"
#include "Stack.h"
#include <string>

using namespace CS303;

int main()
{
    // List
    List<std::string> list;
    list.push_back("This");
    list.push_back("is");
    list.push_back("a");
    list.push_back("test");
    list.print();

    list.pop_back();
    list.print();

    list.pop_front();
    list.print();

    list.push_front("This");
    list.print();

    list.push_back("test");
    list.print();

    list.insert(2, "a");
    list.print();

    list.remove(2);
    list.print();

    std::cout << "This found at index " << list.find("This") << std::endl;

    // Stack
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    std::cout << "Top: " << stack.top() << std::endl;

    std::cout << "Average: " << stack.average() << std::endl;

    return 0;
}