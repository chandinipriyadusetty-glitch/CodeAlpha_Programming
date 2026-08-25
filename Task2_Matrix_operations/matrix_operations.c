#include <stdio.h>

void inputMatrix(int matrix[10][10], int rows, int cols);
void displayMatrix(int matrix[10][10], int rows, int cols);
void addMatrix(int a[10][10], int b[10][10], int rows, int cols);
void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int c2);
void transposeMatrix(int matrix[10][10], int rows, int cols);

int main() {
    int choice;
    int A[10][10], B[10][10];
    int r1, c1, r2, c2;

    while (1) {
        printf("\n===== MATRIX OPERATIONS =====\n");
        printf("1. Matrix Addition\n");
        printf("2. Matrix Multiplication\n");
        printf("3. Matrix Transpose\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (r1 != r2 || c1 != c2) {
                    printf("Addition not possible!\n");
                    break;
                }

                printf("Enter Matrix A:\n");
                inputMatrix(A, r1, c1);

                printf("Enter Matrix B:\n");
                inputMatrix(B, r2, c2);

                addMatrix(A, B, r1, c1);
                break;

            case 2:
                printf("Enter rows and columns of Matrix A: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter rows and columns of Matrix B: ");
                scanf("%d %d", &r2, &c2);

                if (c1 != r2) {
                    printf("Multiplication not possible!\n");
                    break;
                }

                printf("Enter Matrix A:\n");
                inputMatrix(A, r1, c1);

                printf("Enter Matrix B:\n");
                inputMatrix(B, r2, c2);

                multiplyMatrix(A, B, r1, c1, c2);
                break;

            case 3:
                printf("Enter rows and columns of Matrix: ");
                scanf("%d %d", &r1, &c1);

                printf("Enter Matrix:\n");
                inputMatrix(A, r1, c1);

                transposeMatrix(A, r1, c1);
                break;

            case 4:
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

void inputMatrix(int matrix[10][10], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[10][10], int rows, int cols) {
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrix(int a[10][10], int b[10][10], int rows, int cols) {
    int sum[10][10];
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nResult of Matrix Addition:\n");
    displayMatrix(sum, rows, cols);
}

void multiplyMatrix(int a[10][10], int b[10][10], int r1, int c1, int c2) {
    int product[10][10];
    int i, j, k;

    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            product[i][j] = 0;
            for (k = 0; k < c1; k++) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nResult of Matrix Multiplication:\n");
    displayMatrix(product, r1, c2);
}

void transposeMatrix(int matrix[10][10], int rows, int cols) {
    int transpose[10][10];
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transpose[j][i] = matrix[i][j];
        }
    }

    printf("\nTranspose Matrix:\n");
    displayMatrix(transpose, cols, rows);
}