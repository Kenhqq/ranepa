#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Функция формирования списка
    void addToEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Добавление элемента в конец списка
    void add(int value) {
        addToEnd(value);
    }

    // Вставка элемента в заданную позицию
    void insert(int position, int value) {
        if (position < 0) {
            std::cout << "Ошибка: недопустимая позиция\n";
            return;
        }
        Node* newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; temp && i < position - 1; ++i) {
            temp = temp->next;
        }
        
        if (!temp) {
            std::cout << "Ошибка: позиция вне границ списка\n";
            delete newNode;
            return;
        }
        
        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Удаление элемента из списка по позиции
    void remove(int position) {
        if (!head || position < 0) {
            std::cout << "Ошибка: некорректный запрос\n";
            return;
        }

        Node* temp = head;
        if (position == 0) {
            head = head->next;
            delete temp;
            return;
        }

        for (int i = 0; temp && i < position - 1; ++i) {
            temp = temp->next;
        }

        if (!temp || !temp->next) {
            std::cout << "Ошибка: позиция вне границ списка\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Очистка списка
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Замена элемента в списке
    void replace(int position, int value) {
        Node* temp = head;
        for (int i = 0; temp && i < position; ++i) {
            temp = temp->next;
        }
        
        if (!temp) {
            std::cout << "Ошибка: позиция вне границ списка\n";
            return;
        }
        
        temp->data = value;
    }

    // Поиск элемента по индексу
    int get(int position) {
        Node* temp = head;
        for (int i = 0; temp && i < position; ++i) {
            temp = temp->next;
        }
        
        if (!temp) {
            std::cout << "Ошибка: позиция вне границ списка\n";
            return -1;
        }
        
        return temp->data;
    }

    // Печать списка (для отладки)
    void print() {
        Node* temp = head;
        while (temp) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;

    // Пример использования
    list.add(10);
    list.add(20);
    list.add(30);
    list.print();

    list.insert(1, 15);  // Вставка 15 на позицию 1
    list.print();

    list.replace(2, 25);  // Замена элемента на позиции 2 на 25
    list.print();

    std::cout << "Элемент на позиции 2: " << list.get(2) << std::endl;

    list.remove(1);  // Удаление элемента на позиции 1
    list.print();

    list.clear();  // Очистка списка
    list.print();

    return 0;
}
