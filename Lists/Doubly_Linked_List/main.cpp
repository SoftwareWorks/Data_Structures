#include <iostream>
#include "list.h"

int main()
{
    auto list = List<int>();

    list.insert(1);
    list.insert(2);
    list.insert(3);

    auto node = list.search(3);
    list.remove(node);

    std::cout << (list.search(1) != nullptr) << std::endl;
    std::cout << (list.search(2) != nullptr) << std::endl;
    std::cout << (list.search(3) != nullptr) << std::endl;
    std::cout << (list.search(4) != nullptr) << std::endl;

    list.insertBefore(list.search(2), 4);
    std::cout << (list.search(4) != nullptr) << std::endl;

    list.insertBefore(list.search(4), 5);
    list.insertBefore(list.search(1), 6);
    std::cout << (list.search(5) != nullptr) << std::endl;
    std::cout << (list.search(6) != nullptr) << std::endl;

    return 0;
}
