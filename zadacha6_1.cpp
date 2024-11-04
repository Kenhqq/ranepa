#include <iostream>
#include <functional>

void bubbleSort(int arr[], int n, std::function<bool(int, int)> compare) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(arr[j + 1], arr[j])) {
                // Меняем местами arr[j] и arr[j + 1]
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
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

    return 0;
}