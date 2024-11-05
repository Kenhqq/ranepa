#include <iostream>

int* allocateMemory() {
    int* ptr = new int;
    *ptr = 42;
    return ptr;
}

int main() {
    for (int i = 0; i < 10000000; ++i) {
        int* ptr = allocateMemory();
        std::cout << *ptr << std::endl;
        delete ptr;  // Освобождаем память
    }

    std::cin.get();
    return 0;
}
