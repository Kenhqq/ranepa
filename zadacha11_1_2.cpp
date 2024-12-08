#include <iostream>
#include <cstring> // Для работы с C-строками

class MyString {
private:
    char* str; // Указатель на строку
public:
    // Конструктор по умолчанию
    MyString(const char* init_str = "") {
        str = new char[strlen(init_str) + 1]; // выделение памяти для строки
        strcpy(str, init_str); // копирование строки в новый массив
    }

    // Конструктор копирования
    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // Деструктор
    ~MyString() {
        delete[] str; // освобождение памяти
    }

    // Оператор + (конкатенация строк)
    MyString operator+(const MyString& other) const {
        char* new_str = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(new_str, str);
        strcat(new_str, other.str);
        MyString result(new_str);
        delete[] new_str; // очищаем временную строку
        return result;
    }

    // Оператор += (добавление строки к текущей)
    MyString& operator+=(const MyString& other) {
        char* new_str = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(new_str, str);
        strcat(new_str, other.str);
        delete[] str; // освобождение старой памяти
        str = new_str; // указываем на новую строку
        return *this;
    }

    // Оператор << для вывода строки в поток
    friend std::ostream& operator<<(std::ostream& os, const MyString& myStr) {
        os << myStr.str; // выводим строку в поток
        return os;
    }
};

int main() {
    // Пример использования оператора +
    MyString str1("Hello, ");
    MyString str2("World!");
    MyString result = str1 + str2;
    std::cout << "Результат сложения строк: " << result << std::endl;

    // Пример использования оператора +=
    str1 += str2;
    std::cout << "Результат сложения с помощью +=: " << str1 << std::endl;

    return 0;
}
