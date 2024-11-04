#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>

void printBinary(float num) { // Принимает веществ число
    unsigned char* bytePointer = reinterpret_cast<unsigned char*>(&num);  // Указатель на число как на массив байтов
    for (int i = sizeof(float) - 1; i >= 0; --i) { // Два вложенных цикла, внешний проходит по байтам числа (с последнего к первому), а внутренний по битам каждого байта (с последнего к первому)
        for (int j = 7; j >= 0; --j) {
            std::cout << ((bytePointer[i] >> j) & 1); //Сдвигает байт i вправо на j позиций и применяет побитовый AND с 1, чтобы получить значение конкретного бита. Этот бит выводится на экран
        }
    }
    std::cout << std::endl;
}

int main() {
    int studentNumber = 16;
    
    // Формируем вещественное число вида n.n
    float num = static_cast<float>(studentNumber) + studentNumber / 100.0f; // 16 -> 16.16

    // Выводим результат
    std::cout << "Число: " << std::fixed << std::setprecision(2) << num << std::endl;

    // Выводим бинарное представление в формате IEEE 754
    std::cout << "Бинарное представление (IEEE 754): ";
    printBinary(num);

    // Для проверки точности
    float exactValue = static_cast<float>(studentNumber) + (studentNumber / 100.0f); // Это то, что мы хотели получить
    std::cout << "Точное значение: " << exactValue << std::endl;

    // Проверка расхождения
    float epsilon = fabs(num - exactValue);
    std::cout << "Расхождение: " << epsilon << std::endl;

    if (epsilon == 0.0f) {
        std::cout << "Значение представлено точно." << std::endl;
    } else {
        std::cout << "Значение не представлено точно." << std::endl;
    }

    return 0;
}
