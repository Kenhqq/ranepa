#include <iostream>
#include <vector>
#include <functional>

// Функция пузырьковой сортировки для массива
void bubbleSort(int* arr, int n, std::function<bool(int, int)> compare) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(arr[j + 1], arr[j])) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Функция пузырьковой сортировки для std::vector
void bubbleSort(std::vector<int>& vec, std::function<bool(int, int)> compare) {
    bubbleSort(vec.data(), vec.size(), compare);
}

void printArray(const int* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void printVector(const std::vector<int>& vec) {
    for (int value : vec) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Пример с массивом
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    printArray(arr, n);

    // Сортировка по возрастанию
    bubbleSort(arr, n, [](int a, int b) { return a < b; });

    std::cout << "Отсортированный массив (по возрастанию): ";
    printArray(arr, n);

    // Сортировка по убыванию
    bubbleSort(arr, n, [](int a, int b) { return a > b; });

    std::cout << "Отсортированный массив (по убыванию): ";
    printArray(arr, n);

    // Пример с std::vector
    std::vector<int> vec = {37, 23, 0, 17, 12, 72, 31};

    std::cout << "\nИсходный вектор: ";
    printVector(vec);

    // Сортировка вектора по возрастанию
    bubbleSort(vec, [](int a, int b) { return a < b; });

    std::cout << "Отсортированный вектор (по возрастанию): ";
    printVector(vec);

    // Сортировка вектора по убыванию
    bubbleSort(vec, [](int a, int b) { return a > b; });

    std::cout << "Отсортированный вектор (по убыванию): ";
    printVector(vec);

    return 0;
}
