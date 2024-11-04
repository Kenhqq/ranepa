#include <iostream>
#include <bitset> // для отображения двоичного представления

int main() {
    // Пример работы с побитовым сдвигом на 64 битной системе
    int a = -8; // Знаковое значение
    unsigned int b = 4; // Положительное значение

    // Сдвиг вправо
    int rightShifted = a >> 1;
    // Выводим значения
    std::cout << "Исходное значение: " << a << " (в двоичном): " << std::bitset<8>(a) << std::endl;
    std::cout << "Сдвиг вправо на 1: " << rightShifted << " (в двоичном): " << std::bitset<8>(rightShifted) << std::endl;

    // Сдвиг влево
    int leftShifted = b << 1;
    std::cout << "Исходное значение (b): " << b << " (в двоичном): " << std::bitset<8>(b) << std::endl;
    std::cout << "Сдвиг влево на 1: " << leftShifted << " (в двоичном): " << std::bitset<8>(leftShifted) << std::endl;

    // Пример побитовых операций 
    unsigned int c = 14; // 1110 в двоичном
    unsigned int d = 3;  // 0011 в двоичном

    unsigned int andResult = c & d; // Побитовое И
    unsigned int orResult = c | d;  // Побитовое ИЛИ
    unsigned int xorResult = c ^ d; // Побитовое исключающее ИЛИ
    unsigned int notResult = ~c;     // Побитовая инверсия

    // Выводим результаты
    std::cout << "" << std::endl;
    std::cout << "Побитовое И: " << andResult << " (в двоичном): " << std::bitset<8>(andResult) << std::endl;
    std::cout << "Побитовое ИЛИ: " << orResult << " (в двоичном): " << std::bitset<8>(orResult) << std::endl;
    std::cout << "Побитовое исключающее ИЛИ: " << xorResult << " (в двоичном): " << std::bitset<8>(xorResult) << std::endl;
    std::cout << "Побитовая инверсия: " << notResult << " (в двоичном): " << std::bitset<8>(notResult) << std::endl;

    return 0;
}
