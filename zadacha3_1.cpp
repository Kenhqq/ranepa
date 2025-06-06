#include <iostream>
#include <bitset> // Для отображения двоичного представления

int main() {
    // Пример работы с побитовым сдвигом на знаковом типе данных
    int a = -8; // Знаковое значение (в двоичном: 11111111 11111111 11111111 11111000)
    int b = 4;  // Положительное значение (в двоичном: 00000000 00000000 00000000 00000100)

    // Сдвиг вправо для отрицательного числа
    int rightShifted = a >> 1; // Сдвиг вправо
    // Ожидаемое поведение: старший бит (бит знака) будет продублирован
    std::cout << "Исходное значение a: " << a << " (в двоичном): " << std::bitset<32>(a) << std::endl;
    std::cout << "Сдвиг вправо на 1: " << rightShifted << " (в двоичном): " << std::bitset<32>(rightShifted) << std::endl;

    // Сдвиг влево для положительного числа
    int leftShifted = b << 1; // Сдвиг влево
    // Ожидаемое поведение: при сдвиге влево значение увеличивается.
    std::cout << "Исходное значение b: " << b << " (в двоичном): " << std::bitset<32>(b) << std::endl;
    std::cout << "Сдвиг влево на 1: " << leftShifted << " (в двоичном): " << std::bitset<32>(leftShifted) << std::endl;

    // Исследуем поведение при сдвиге влево, когда затрагивается бит знака
    int overflowShift = b << 30; // Сдвиг влево на 30 бит
    std::cout << "Сдвиг влево на 30: " << overflowShift << " (в двоичном): " << std::bitset<32>(overflowShift) << std::endl;

    // Пример побитовых операций с знаковыми типами
    int c = 14; // 00000000 00000000 00000000 00001110 в двоичном
    int d = 3;  // 00000000 00000000 00000000 00000011 в двоичном

    int andResult = c & d; // Побитовое И
    int orResult = c | d;  // Побитовое ИЛИ
    int xorResult = c ^ d; // Побитовое исключающее ИЛИ
    int notResult = ~c;     // Побитовая инверсия

    // Выводим результаты
    std::cout << "\nРезультаты побитовых операций:" << std::endl;
    std::cout << "Побитовое И: " << andResult << " (в двоичном): " << std::bitset<32>(andResult) << std::endl;
    std::cout << "Побитовое ИЛИ: " << orResult << " (в двоичном): " << std::bitset<32>(orResult) << std::endl;
    std::cout << "Побитовое исключающее ИЛИ: " << xorResult << " (в двоичном): " << std::bitset<32>(xorResult) << std::endl;
    std::cout << "Побитовая инверсия: " << notResult << " (в двоичном): " << std::bitset<32>(notResult) << std::endl;

    return 0;
}


