#include <iostream>
#include <cstring>

class String {
private:
    char* str_;
    unsigned int len_;

public:
    // Конструктор
    String(unsigned int size) {
        len_ = size;
        str_ = new char[len_ + 1];  // +1 для символа завершения строки
        for (unsigned int i = 0; i < len_; i++) {
            str_[i] = '\0';  // Заполнение строки пустыми символами
        }
        str_[len_] = '\0';  // Завершающий нулевой символ
    }

    // Конструктор копирования
    String(const String& other) {
        len_ = other.len_;
        str_ = new char[len_ + 1];
        std::strcpy(str_, other.str_);
    }

    // Деструктор
    ~String() {
        delete[] str_;
    }

    // Метод для получения строки
    const char* getData() const {
        return str_;
    }

    // Оператор присваивания
    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str_;  // Освобождаем старую память
            len_ = other.len_;
            str_ = new char[len_ + 1];
            std::strcpy(str_, other.str_);
        }
        return *this;
    }

    // Метод для вывода строки
    void print() const {
        std::cout << str_ << std::endl;
    }
};

int main() {
    String str1(10);  // Строка длиной 10
    str1.print();     // Вывод пустой строки

    String str2 = str1;  // Использование конструктора копирования
    str2.print();         // Вывод пустой строки

    String str3(5);
    str3 = str1;  // Использование оператора присваивания
    str3.print();  // Вывод пустой строки

    return 0;
}
