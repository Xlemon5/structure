#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class Node {
public:
    int key;
    int value;
    Node* next;

    Node(int key, int value) : key(key), value(value), next(nullptr) {}
};

class HashTable {
private:
    Node* table[TABLE_SIZE];

    // Простая хэш-функция, остаток от деления
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    // Вставка элемента в хэш-таблицу
    void insert(int key, int value) {
        int index = hashFunction(key);
        Node* newNode = new Node(key, value);
        newNode->next = table[index];
        table[index] = newNode;
    }

    // Поиск значения по ключу
    int getValue(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value; // Возвращаем значение по ключу
            }
            current = current->next;
        }
        return -1; // Возвращаем -1, если ключ не найден
    }

    // Удаление элемента из хэш-таблицы
    void remove(int key) {
        int index = hashFunction(key);
        Node* current = table[index];
        Node* prev = nullptr;

        while (current != nullptr && current->key != key) {
            prev = current;
            current = current->next;
        }

        if (current != nullptr) {
            if (prev != nullptr) {
                prev->next = current->next;
            } else {
                table[index] = current->next;
            }
            delete current;
        }
    }

    // Функция вывода таблицы
    void printTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            std::cout << "[" << i << "]: ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << "(" << current->key << ", " << current->value << ") ";
                current = current->next;
            }
            cout << std::endl;
        }
    }
};

int main() {
    HashTable hashTable;

    // Пример использования
    hashTable.insert(1, 17);
    hashTable.insert(37, 156);
    hashTable.insert(15, 44);
    hashTable.insert(895, 250);
    hashTable.insert(1, 1);


    cout << "Hash Table:" << std::endl;
    hashTable.printTable();

    cout << "------------------------" <<endl;

    cout << "Value for key 15: " << hashTable.getValue(15) << endl;
    hashTable.remove(15);
    cout << "Value for key 15 after removal: " << hashTable.getValue(15) << endl;


    cout << "------------------------" <<endl;
    // Вывод таблицы
    cout << "Hash Table:" << std::endl;
    hashTable.printTable();

    return 0;
}
