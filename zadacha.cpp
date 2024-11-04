#include <iostream>
#include <iomanip>
#include <cmath>
#include <cfloat>

int main() {
    // Номер из списка
    int studentNumber = 16;

    // Создаем вещественное число вида n.n
    float floatNumber = static_cast<float>(studentNumber) + static_cast<float>(studentNumber) / 100;

    // Выводим полученное вещественное число
    std::cout << std::fixed << std::setprecision(2); // Округялем до двух знаков после точки
    std::cout << "Ваше число: " << floatNumber << std::endl;

    // Вычисляем точное значение с помощью double для сравнения
    double exactValue = static_cast<double>(studentNumber) + static_cast<double>(studentNumber) / 100;
    float error = floatNumber - static_cast<float>(exactValue);

    // Выводим результат
    if (error == 0.0f) {
        std::cout << "Точное значение получено!" << std::endl;
    } else {
        std::cout << "Точное значение не получено." << std::endl;
        std::cout << "Расхождение: " << error << std::endl;
        std::cout << "Причина расхождения: округление и ограничения формата float." << std::endl;
    }

    return 0;
}
