#include <iostream>
#include <cstdlib> // Для std::atoi
#include <string>  // Для std::string

int main(int argc, char* argv[]) {
    // Проверяем количество аргументов
    if (argc != 3) {
        std::cout << "Использование: ./zadacha6_3(название программы) <число1> <число2>" << std::endl;
        return 1; // Возвращаем ошибку
    }

    // Преобразуем аргументы в целые числа
    int num1 = std::atoi(argv[1]);
    int num2 = std::atoi(argv[2]);

    // Проверяем деление на нол
    if (num2 == 0) {
        std::cout << "Ошибка: Деление на 0 запрещено." << std::endl;
        return 1; // Возвращаем ошибку
    }

    // Выполняем деление и выводим результат
    double result = static_cast<double>(num1) / num2;
    std::cout << "Результат деления " << num1 << " на " << num2 << " = " << result << std::endl;

    return 0; 
}