#include <iostream>

using namespace std;

void recursiveFunction(int depth) {
    int array[1000];  // Локальный массив, который занимает место в стеке
    cout << "Глубина рекурсии: " << depth << endl;

    // Заполняем массив, чтобы быть уверенными, что он действительно использует память
    for (int i = 0; i < 1000; i++) {
        array[i] = i;
    }

    // Рекурсивно вызываем саму себя, увеличивая глубину
    recursiveFunction(depth + 1);
}

int main() {
    try {
        // Запускаем рекурсивную функцию, начиная с глубины 1
        recursiveFunction(1);
    } catch (const std::exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}

