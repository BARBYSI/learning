#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printMatrix(int matrix_size, int matrix[matrix_size][matrix_size]){
    for(int i=0; i < matrix_size; i++) {
        for(int j=0; j < matrix_size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void generateMatrix(int matrix_size, int matrix[matrix_size][matrix_size]) {
    srand(time(NULL));
    for (int row = 0; row < matrix_size; row++) {
        for (int column = 0; column < matrix_size; column++) {
            matrix[row][column] = rand() % 2;
        }
    }
}

void copyMatrix (int matrix_size, int matrix[matrix_size][matrix_size], int matrixToCopy[matrix_size][matrix_size]) {
    for (int row = 0; row < matrix_size; row++) {
        for (int column = 0; column < matrix_size; column++) {
            matrixToCopy[row][column] = matrix[row][column];
        }
    }
}

int compareMatrix (int matrix_size, int matrix[matrix_size][matrix_size], int matrixCopy[matrix_size][matrix_size]) {
    int result = 0;
    for (int row = 0; row < matrix_size; row++) {
        for (int column = 0; column < matrix_size; column++) {
            if (matrixCopy[row][column] != matrix[row][column]) {
                result = 1;
            };
        }
    }
    return result;
}

void scanMatrixHorizontal(int matrix_size, int matrix[matrix_size][matrix_size]) {
    //сканирование по строчкам
    for (int row = 0; row < matrix_size; row++) {
        int counter = matrix_size;
        for (int column = 0; column < matrix_size; column++) {
            if (matrix[row][column] == 0) {
                counter--;
            }
        }
        if (counter == 0) {
            printf("row %d is full of zero's\n", row+1);
            for (int i = 0; i < matrix_size; i++) {
                matrix[i][row] = 0;
            }
            printMatrix(matrix_size, matrix);
        }
    }
}

void scanMatrixVertical (int matrix_size, int matrix[matrix_size][matrix_size]) {
    for (int row = 0; row < matrix_size; row++) {
        int counter = matrix_size;
        for (int column = 0; column < matrix_size; column++) {
            if (matrix[column][row] == 0) {
                counter--;
            }
        }
        if (counter == 0) {
            printf("column %d is full of zero's\n", row+1);
            for (int i = 0; i < matrix_size; i++) {
                matrix[row][i] = 0;
            }
            printMatrix(matrix_size, matrix);
        }
    }
}

int main(void) {
    int size;
    printf("Input the size of matrix: ");
    scanf("%d", &size);
    int matrix[size][size];
    int matrixCopy[size][size];
    generateMatrix(size, matrix);
    printMatrix(size, matrix);
    for (int n = 0; n < size; n++) {
        copyMatrix(size, matrix, matrixCopy);
        scanMatrixHorizontal(size, matrix);
        copyMatrix(size, matrix, matrixCopy);
        scanMatrixVertical(size, matrix);
        copyMatrix(size, matrix, matrixCopy);
        if(compareMatrix(size, matrix, matrixCopy) == 0) {
            break;
        };
    }

}

