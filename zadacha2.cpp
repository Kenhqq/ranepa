#include <iostream>
#include <iomanip> 

int main() {
    const int N = 10000000; // Максимальное значение n
    double sum = 0.0; // Переменная для хранения суммы

    for (int n = 1; n <= N; ++n) {
        sum += 1.0 / n; // Суммируем 1/n
    }

    // Устанавливаем точность вывода
    std::cout << std::fixed << std::setprecision(10); // точность до 10 знаков после точки
    std::cout << "Сумма 1/n для n от 1 до " << N << " составляет: " << sum << std::endl;

    return 0;
}