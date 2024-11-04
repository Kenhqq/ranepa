// Оптимизированная версия кода
#include <iostream>
#include <cmath> // Для функции sqrt

bool isPrime(int n) { // Выводит true или false
    if (n <= 1) return false; // Числа 0 и 1 не являются простыми
    if (n <= 3) return true; // 2 и 3 - простые числа

    // Исключаем четные числа и делители 3
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Проверяем делители от 5 до sqrt(n)
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int number;
    std::cout << "Введите целое число: ";
    std::cin >> number;

    if (isPrime(number)) {
        std::cout << number << " является простым числом." << std::endl;
    } else {
        std::cout << number << " не является простым числом." << std::endl;
    }

    return 0;
}
