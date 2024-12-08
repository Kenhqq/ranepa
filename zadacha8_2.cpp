#include <iostream>

// Макрос для создания функции с заданным именем и возвращаемым значением
#define CREATE_FUNCTION(name, value) \
    int func_##name() { return value; }

CREATE_FUNCTION(abcd, 12) // Создаст функцию int func_abcd() { return 12; }

int main() {
    std::cout << "Результат вызова func_abcd: " << func_abcd() << std::endl;
    return 0;
}
