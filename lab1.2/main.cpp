#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;

class HashTable {
private:
    int keys[TABLE_SIZE];
    int values[TABLE_SIZE];
    bool occupied[TABLE_SIZE];

    // Простая хэш-функция, остаток от деления
    int hashFunction(int key) {
        return key % TABLE_SIZE;
    }

    // Функция для поиска следующего свободного слота
    int findNextSlot(int index) {
        while (occupied[index]) {
            index = (index + 1) % TABLE_SIZE;
        }
        return index;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            occupied[i] = false;
        }
    }

    // Вставка элемента в хэш-таблицу
    void insert(int key, int value) {
        int index = hashFunction(key);

        // Если слот занят, ищем следующий свободный слот
        if (occupied[index]) {
            index = findNextSlot(index);
        }

        keys[index] = key;
        values[index] = value;
        occupied[index] = true;
    }

    // Поиск значения по ключу
    int getValue(int key) {
        int index = hashFunction(key);

        while (occupied[index]) {
            if (keys[index] == key) {
                return values[index];
            }
            index = (index + 1) % TABLE_SIZE;
        }

        return -1; // Возвращаем -1, если ключ не найден
    }

    // Удаление элемента из хэш-таблицы
    void remove(int key) {
        int index = hashFunction(key);

        while (occupied[index]) {
            if (keys[index] == key) {
                occupied[index] = false;
                return;
            }
            index = (index + 1) % TABLE_SIZE;
        }
    }

    // Функция вывода таблицы
    void printTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (occupied[i]) {
                cout << "[" << i << "]: (" << keys[i] << ", " << values[i] << ")" << endl;
            } else {
                cout << "[" << i << "]: Empty" << endl;
            }
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

    // Вывод таблицы
    cout << "Hash Table:" << endl;
    hashTable.printTable();

    cout << "------------------------" <<endl;

    cout << "Value for key 15: " << hashTable.getValue(15) << endl;
    hashTable.remove(15);
    cout << "Value for key 15 after removal: " << hashTable.getValue(15) << endl;

    cout << "------------------------" <<endl;

    // Вывод таблицы
    cout << "Hash Table:" << endl;
    hashTable.printTable();

    return 0;
}
