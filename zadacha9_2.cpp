#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class DateTime {
private:
    int day, month, year;
    int hour, minute, second;

public:
    // Конструктор без аргументов
    DateTime() : day(1), month(1), year(2000), hour(0), minute(0), second(0) {}

    // Конструктор с аргументами
    DateTime(int d, int m, int y, int h = 0, int min = 0, int sec = 0) {
        setDate(d, m, y);
        setTime(h, min, sec);
    }

    // Метод для установки даты
    void setDate(int d, int m, int y) {
        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
        } else {
            cout << "Ошибка: Неверная дата!" << endl;
        }
    }

    // Метод для установки времени
    void setTime(int h, int m, int s) {
        if (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60) {
            hour = h;
            minute = m;
            second = s;
        } else {
            cout << "Ошибка: Неверное время!" << endl;
        }
    }

    // Метод для отображения даты и времени
    void display() const {
        cout << setfill('0') << setw(2) << day << "/"
             << setw(2) << month << "/"
             << setw(4) << year << " "
             << setw(2) << hour << ":"
             << setw(2) << minute << ":"
             << setw(2) << second << endl;
    }

    // Метод для проверки, является ли дата Новым годом
    bool isNewYear() const {
        return (day == 1 && month == 1);
    }

    // Проверка корректности даты (простая версия)
    bool isValidDate(int d, int m, int y) const {
        if (m < 1 || m > 12) return false;
        int daysInMonth[] = {31, 28 + (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        return d >= 1 && d <= daysInMonth[m - 1];
    }
};

int main() {
    DateTime dt;
    dt.display();

    int d, m, y, h, min, s;
    cout << "Введите дату (день, месяц, год): ";
    cin >> d >> m >> y;
    cout << "Введите время (часы, минуты, секунды): ";
    cin >> h >> min >> s;

    DateTime customDate(d, m, y, h, min, s);
    customDate.display();

    if (customDate.isNewYear()) {
        cout << "Это Новый Год!" << endl;
    } else {
        cout << "Это не Новый Год." << endl;
    }

    return 0;
}
