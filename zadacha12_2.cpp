#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

class JournalEntry {
private:
    int entryNumber;
    string fullName;
    vector<double> grades;

public:
    // Конструктор класса
    JournalEntry(int number, const string& name, const vector<double>& grades)
        : entryNumber(number), fullName(name), grades(grades) {}

    // Метод для вычисления суммы баллов
    double getTotalScore() const {
        return accumulate(grades.begin(), grades.end(), 0.0);
    }

    // Оператор сравнения для сортировки
    bool operator<(const JournalEntry& other) const {
        return getTotalScore() < other.getTotalScore();
    }

    // Геттеры
    int getEntryNumber() const { return entryNumber; }
    string getFullName() const { return fullName; }
    const vector<double>& getGrades() const { return grades; }

    // Вывод информации о записи
    void printEntry() const {
        cout << "Номер записи: " << entryNumber << ", ФИО: " << fullName << ", Баллы: ";
        for (double grade : grades) {
            cout << grade << " ";
        }
        cout << ", Сумма баллов: " << getTotalScore() << endl;
    }
};

int main() {
    // Создание списка записей
    vector<JournalEntry> journal = {
        JournalEntry(1, "Иванов И.И.", {9.5, 8.5, 7.0}),
        JournalEntry(2, "Петров П.П.", {10.0, 9.0, 8.5}),
        JournalEntry(3, "Сидоров С.С.", {7.5, 6.0, 8.0})
    };

    // Сортировка записей по баллам
    sort(journal.begin(), journal.end());

    // Вывод отсортированных записей
    for (const auto& entry : journal) {
        entry.printEntry();
    }

    return 0;
}
