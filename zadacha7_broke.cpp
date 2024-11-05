#include <iostream>

double* allocateMemory() {
    // Выделение памяти для переменной типа double
    double* ptr = new double;
    *ptr = 42.42;  // Присваиваем значение
    return ptr;  // Возвращаем указатель
}

int main() {
    // Цикл, который вызывает функцию 10 000 000 раз
    for (int i = 0; i < 10000000; ++i) {
        int* ptr = allocateMemory();
        // Распечатываем значение в ячейке памяти
        std::cout << *ptr << std::endl;
        // Не освобождаем память
    }

    // Ожидаем ввода пользователя, чтобы приостановить выполнение программы
    std::cin.get();

    return 0;
}
