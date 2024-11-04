#include <iostream>
#include <vector>
using namespace std;

void Eratosthenes(int N) {
    // Создаем вектор булевых значений и инициализируем их значением true
    vector<bool> prime(N + 1, true);

    // 0 и 1 не являются простыми числами
    prime[0] = prime[1] = false;

    // Начинаем с первого простого числа — 2
    for (int p = 2; p * p <= N; p++) {
        // Если prime[p] не было помечено как false, оно является простым
        if (prime[p]) {
            // Помечаем все кратные p начиная с p*p как не простые
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }

    // Выводим все простые числа от 1 до N
    cout << "Простые числа до " << N << ": ";
    for (int p = 2; p <= N; p++) {
        if (prime[p])
            cout << p << " ";
    }
    cout << endl;
}

int main() {
    int N;
    cout << "Введите число N: ";
    cin >> N;
    Eratosthenes(N);
    return 0;
}
