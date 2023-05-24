#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void generateMatrix(int matrix_size, int matrix[matrix_size])
{
    _sleep(1000);
    srand(time(NULL));
    for (int i = 0; i < matrix_size; i++)
    {
        matrix[i] = rand() % 10;  
    }
    for (int i = 0; i < matrix_size; i++){
        printf("%d ", matrix[i]);
    }
    printf("\n");
}

void compareMatrix(int *n, int *r, int matrix_size_one, int matrix_size_two, int matrix_one[matrix_size_one], int matrix_two[matrix_size_two], int *matrix_X, int *matrix_Y) {
    for (int i = 0; i < matrix_size_one; i++) {
        int counter = 0;
        for (int j = 0; j < matrix_size_two; j++) {
            // printf("%d %d\n", i, j);
            if (matrix_one[i] == matrix_two[j]) {
                counter++;
            }
        }
        if (counter == 0) {
            (*n)++;
            matrix_X = realloc(matrix_X, (*n)*sizeof(int));
            // printf("%d ", matrix_one[i]);
            matrix_X[(*n)-1] = matrix_one[i];
            // printf("\n%d", matrix_X[(*n)-1]);
            // printf("\n n == %d", (*n));
        }
    }
    for (int i = 0; i < matrix_size_two; i++) {
        int counter = 0;
        for (int j = 0; j < matrix_size_one; j++) {
            // printf("%d %d\n", i, j);
            if (matrix_two[i] == matrix_one[j]) {
                counter++;
            }
        }
        if (counter == 0) {
            (*r)++;
            matrix_Y = realloc(matrix_Y, (*r)*sizeof(int));
            // printf("%d ", matrix_one[i]);
            matrix_Y[(*r)-1] = matrix_two[i];
            // printf("\n%d", matrix_X[(*n)-1]);
            // printf("\n n == %d", (*n));
        }
    }
    printf("\nmatrix X\n");
    for (int k = 0; k < (*n); k++) {
        printf("%d ", matrix_X[k]);
    }
    printf("\nmatrix Y\n");
    for (int k = 0; k < (*r); k++) {
        printf("%d ", matrix_Y[k]);
    }
}

void main() {
    int *matrix_X, *matrix_Y;
    int matrix_A[10]; 
    int matrix_B[15];
    int n, r = 0;

    matrix_X = malloc(0);
    matrix_Y = malloc(0);

    generateMatrix(10, matrix_A);
    generateMatrix(15, matrix_B);
    compareMatrix(&n, &r, 10, 15, matrix_A, matrix_B, matrix_X, matrix_Y);
    
}