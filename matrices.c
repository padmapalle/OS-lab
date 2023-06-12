/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

#define MAX_SIZE 10

void matrixMultiplication(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int columns1, int columns2) {
    int i, j, k;

    for (i = 0; i < rows1; i++) {
        for (j = 0; j < columns2; j++) {
            result[i][j] = 0;
            for (k = 0; k < columns1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void matrixAddition(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void matrixSubtraction(int matrix1[MAX_SIZE][MAX_SIZE], int matrix2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int columns) {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < columns; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void rowAddition(int matrix[MAX_SIZE][MAX_SIZE], int row, int rows, int columns) {
    int i;
    int sum = 0;

    for (i = 0; i < columns; i++) {
        sum += matrix[row][i];
    }

    printf("Sum of row %d: %d\n", row + 1, sum);
}

void columnAddition(int matrix[MAX_SIZE][MAX_SIZE], int column, int rows, int columns) {
    int i;
    int sum = 0;

    for (i = 0; i < rows; i++) {
        sum += matrix[i][column];
    }

    printf("Sum of column %d: %d\n", column + 1, sum);
}

int main() {
    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];
    int rows1, columns1, rows2, columns2;
    int choice, i, j;

    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &rows1, &columns1);

    printf("Enter the elements of matrix 1:\n");
    for (i = 0; i < rows1; i++) {
        for (j = 0; j < columns1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &rows2, &columns2);

    printf("Enter the elements of matrix 2:\n");
    for (i = 0; i < rows2; i++) {
        for (j = 0; j < columns2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Enter your choice:\n");
    printf("1. Matrix Multiplication\n");
    printf("2. Matrix Addition\n");
    printf("3. Matrix Subtraction\n");
    printf("4. Row Addition\n");
    printf("5. Column Addition\n");
    printf("Choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (columns1 != rows2) {
                printf("Matrix multiplication not possible!\n");
                return 0;
            }
            matrixMultiplication(matrix1, matrix2, result, rows1, columns1, columns2);
            printf("Result of matrix multiplication:\n");
            for (i = 0; i < rows1; i++) {
                for (j = 0; j < columns2; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;
        case 2:
            if (rows1 != rows2 || columns1 != columns2) {
                printf("Matrix addition not possible!\n");
                return 0;
            }
            matrixAddition(matrix1, matrix2, result, rows1, columns1);
            printf("Result of matrix addition:\n");
            for (i = 0; i < rows1; i++) {
                for (j = 0; j < columns1; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;
        case 3:
            if (rows1 != rows2 || columns1 != columns2) {
                printf("Matrix subtraction not possible!\n");
                return 0;
            }
            matrixSubtraction(matrix1, matrix2, result, rows1, columns1);
            printf("Result of matrix subtraction:\n");
            for (i = 0; i < rows1; i++) {
                for (j = 0; j < columns1; j++) {
                    printf("%d ", result[i][j]);
                }
                printf("\n");
            }
            break;
        case 4:
            printf("Enter the row number to find the sum: ");
            scanf("%d", &i);
            if (i < 1 || i > rows1) {
                printf("Invalid row number!\n");
                return 0;
            }
            rowAddition(matrix1, i - 1, rows1, columns1);
            break;
        case 5:
            printf("Enter the column number to find the sum: ");
            scanf("%d", &j);
            if (j < 1 || j > columns1) {
                printf("Invalid column number!\n");
                return 0;
            }
            columnAddition(matrix1, j - 1, rows1, columns1);
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
