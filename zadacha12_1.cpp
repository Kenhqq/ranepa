#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Функция для формирования максимальной кучи
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Инициализация самого большого элемента как корень
    int left = 2 * i + 1; // Левый дочерний элемент
    int right = 2 * i + 2; // Правый дочерний элемент

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // Если самый большой элемент не корень
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Рекурсивно приводим в порядок поддерево
        heapify(arr, n, largest);
    }
}

// Функция для пирамидальной сортировки
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Одна за другой извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]); // Перемещаем текущий корень в конец
        heapify(arr, i, 0);   // Приводим оставшуюся часть массива в порядок
    }
}

// Функция для вывода массива
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    // Генерация случайного массива
    srand(time(0));
    int n = 10; // Размер массива
    vector<int> arr(n);
    
    // Заполнение массива случайными числами
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // случайные числа от 0 до 99
    }

    cout << "Исходный массив: ";
    printArray(arr);

    // Сортировка массива
    heapSort(arr);

    cout << "Отсортированный массив: ";
    printArray(arr);

    return 0;
}
