#include <iostream>
using namespace std;

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    // Функция для добавления элемента в стек
    int push(int value) {
        if (top >= MAX_SIZE - 1) {
            return -1; // Стек переполнен
        }
        arr[++top] = value;
        return 0; // Успешное добавление
    }

    // Функция для удаления элемента из стека
    int pop() {
        if (top < 0) {
            return -1; // Стек пуст
        }
        top--;
        return 0; // Успешное удаление
    }

    // Функция для считывания последнего элемента стека
    int peek(int &value) {
        if (top < 0) {
            return -1; // Стек пуст
        }
        value = arr[top];
        return 0; // Успешное считывание
    }
};

int main() {
    Stack stack;
    int value;

    // Тестирование операций со стеком
    cout << "Push 10: " << stack.push(10) << endl; // 0
    cout << "Push 20: " << stack.push(20) << endl; // 0
    cout << "Peek: " << stack.peek(value) << ", Value: " << value << endl; // 0, Value: 20
    cout << "Pop: " << stack.pop() << endl; // 0
    cout << "Peek: " << stack.peek(value) << ", Value: " << value << endl; // 0, Value: 10
    cout << "Pop: " << stack.pop() << endl; // 0
    cout << "Pop: " << stack.pop() << endl; // -1 (стек пуст)

    return 0;
}
