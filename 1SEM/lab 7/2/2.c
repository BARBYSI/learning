#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define FILENAME "matrix"
#define MATRIX_SIZE 3

int main() {
    FILE *file;
    int i, j, min = INT_MAX, max = INT_MIN;
    int matrix[MATRIX_SIZE][MATRIX_SIZE];

    file = fopen(FILENAME, "r+b");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Считываем матрицу из файла
    fread(matrix, sizeof(int), MATRIX_SIZE * MATRIX_SIZE, file);

    // Находим минимальный и максимальный элементы матрицы
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }

    // Заменяем элементы матрицы в соответствии с условиями задачи
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            if (matrix[i][j] < 0) {
                matrix[i][j] = min;
            } else if (matrix[i][j] > 0) {
                matrix[i][j] = max;
            } else {
                matrix[i][j] = max - min;
            }
        }
    }

    // Перемещаем указатель в начало файла
    fseek(file, 0, SEEK_SET);

    // Записываем измененную матрицу в файл
    fwrite(matrix, sizeof(int), MATRIX_SIZE * MATRIX_SIZE, file);

    // Снова перемещаем указатель в начало файла
    fseek(file, 0, SEEK_SET);

    // Выводим матрицу в консоль
    printf("Matrix:\n");
    for (i = 0; i < MATRIX_SIZE; i++) {
        for (j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Закрываем файл
    fclose(file);

    return 0;
}
