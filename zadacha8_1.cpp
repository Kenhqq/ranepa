#include <iostream>

// Макрос для суммы двух чисел
#define SUM(a, b) ((a) + (b))

int main() {
    int x = 5;
    int y = 3;
    std::cout << "Сумма чисел " << x << " и " << y << " равна: " << SUM(x, y) << std::endl;
    return 0;
}
