#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

std::vector<int> generateMSequence(int m) {
    std::vector<int> sequence;

    // Генерация случайной последовательности
    for (int i = 0; i < m; ++i) {
        sequence.push_back(getRandomNumber(0, 1));
    }

    // Проверка и удовлетворение условий
    for (int i = 0; i < m - 2; ++i) {
        if (sequence[i] == 0 && sequence[i + 1] == 0 && sequence[i + 2] == 0) {
            int randomIndex = getRandomNumber(i, i + 2);
            sequence[randomIndex] = 1; // Заменяем одно из нулей на 1, чтобы получить 3 единицы подряд
            i = randomIndex + 1; // Пропускаем следующие два элемента, чтобы не создавать новый блок
        }
    }

    int countOnes = 0;
    for (int i = 0; i < m; ++i) {
        countOnes += sequence[i];
    }

    while (countOnes % 3 != 0) {
        // Добавляем единицы, чтобы число единиц было кратно 3
        int index = getRandomNumber(0, m - 1);
        if (sequence[index] == 0) {
            sequence[index] = 1;
            countOnes++;
        }
    }

    return sequence;
}

int main() {
    srand(static_cast<unsigned>(time(0)));
    int m = 10а;

    std::vector<int> mSequence = generateMSequence(m);

    std::cout << "Сгенерированная m-последовательность: ";
    for (int i = 0; i < m; ++i) {
        std::cout << mSequence[i] << " ";
    }

    return 0;
}
