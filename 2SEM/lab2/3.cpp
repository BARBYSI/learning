#include <iostream>
#include <cstdlib>
#include <assert.h>

int main()
{
    // Ввод нижней и верхней границ массива
    int lb, ub;
    std::cout << "Enter lower bound: ";
    std::cin >> lb;
    std::cout << "Enter upper bound: ";
    std::cin >> ub;

    // Проверка условия на верхнюю и нижнюю границы массива
    assert(ub - lb > 0);

    // Вычисление размера массива
    int size = ub - lb + 1;

    // Выделение памяти под массив
    int* arr = new int[size];

    // Инициализация массива
    for (int i = 0; i < size; i++) {Ы
        arr[i] = rand() % 100; // заполнение случайными значениями от 0 до 99
    }

    // Вывод исходного и динамического массивов
    std::cout << "Initial array: ";
    for (int i = lb; i <= ub; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    std::cout << "Dynamic array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Освобождение памяти
    delete[] arr;

    return 0;
}