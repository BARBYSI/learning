#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define FILENAME "matrix"
#define MATRIX_SIZE 3

int main() {
    FILE *file;
    int i, j, min = INT_MAX, max = INT_MIN;
    int matrix[MATRIX_SIZE][MATRIX_SIZE];

    file = fopen(FILENAME, "rb+");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // ��������� ������� �� �����
    fread(matrix, sizeof(int), MATRIX_SIZE * MATRIX_SIZE, file);

    // ������� ����������� � ������������ �������� �������
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

    // �������� �������� ������� � ������������ � ��������� ������
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

    // ���������� ���������� ������� � ����
    fseek(file, 0, SEEK_SET);
    fwrite(matrix, sizeof(int), MATRIX_SIZE * MATRIX_SIZE, file);

    // ��������� ����
    fclose(file);

    return 0;
}
