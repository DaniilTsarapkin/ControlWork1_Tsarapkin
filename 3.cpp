#include <iostream>
#include <cstdlib>

void fill(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        arr[i] = rand() % 50 + 1;
    }
}

void print(int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void pairs(int* arr, int size, int Sum) {
    bool pairfound = false;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (arr[i] + arr[j] == Sum) {
                std::cout << "Пара: " << arr[i] << ", " << arr[j] << std::endl;
                pairfound = true;
            }
        }
    }
    if (pairfound == false) {
        std::cout << "Пары не найдены" << std::endl;
    }
}

int main() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    int* Array = new int[size];

    fill(Array, size);

    std::cout << "Массив: ";
    print(Array, size);

    int Sum;
    std::cout << "Введите сумму: ";
    std::cin >> Sum;

    pairs(Array, size, Sum);

    delete[] Array;

    return 0;
}
