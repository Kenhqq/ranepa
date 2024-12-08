#include <iostream>
#include <vector>

// Функция для слияния двух отсортированных частей массива
void merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

// Функция для сортировки слиянием
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);  // Рекурсивная сортировка левой части
        mergeSort(arr, mid + 1, right);  // Рекурсивная сортировка правой части

        merge(arr, left, mid, right);  // Слияние отсортированных частей
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6, 7};
    int arrSize = arr.size();

    std::cout << "До сортировки: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    mergeSort(arr, 0, arrSize - 1);

    std::cout << "После сортировки: ";
    for (int i : arr) std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}
