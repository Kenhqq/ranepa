#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std;

// Функция для сортировки пузырьком
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // Если за весь проход не было обменов, значит массив отсортирован
        if (!swapped) break;
    }
}

// Функция для генерации лучшего случая (массив отсортирован)
vector<int> generateBestCase(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = i + 1;
    }
    return arr;
}

// Функция для генерации худшего случая (массив отсортирован в обратном порядке)
vector<int> generateWorstCase(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = size - i;
    }
    return arr;
}

// Функция для генерации типового случая (массив случайных чисел)
vector<int> generateRandomCase(int size) {
    vector<int> arr(size);
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10000; // случайное число от 0 до 9999
    }
    return arr;
}

// Функция для измерения времени работы сортировки
template <typename T>
long long measureTime(T sortFunc, vector<int>& arr) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<long long, nano> duration = end - start;
    return duration.count();
}

int main() {
    srand(time(0));  // Инициализация генератора случайных чисел

    // Размеры массивов для тестирования
    vector<int> sizes = {100, 500, 1000, 5000, 10000}; // Примерные размеры

    // Тестируем время работы для всех случаев
    for (int size : sizes) {
        // Лучший случай
        vector<int> bestCase = generateBestCase(size);
        long long bestTime = measureTime(bubbleSort, bestCase);
        cout << "Best case for size " << size << ": " << bestTime << " nanoseconds" << endl;

        // Худший случай
        vector<int> worstCase = generateWorstCase(size);
        long long worstTime = measureTime(bubbleSort, worstCase);
        cout << "Worst case for size " << size << ": " << worstTime << " nanoseconds" << endl;

        // Типовой случай
        vector<int> randomCase = generateRandomCase(size);
        long long randomTime = measureTime(bubbleSort, randomCase);
        cout << "Random case for size " << size << ": " << randomTime << " nanoseconds" << endl;
    }

    return 0;
}
