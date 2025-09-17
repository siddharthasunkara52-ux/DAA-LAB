#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void add(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subtract(int n, int A[][n], int B[][n], int C[][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[][n], int B[][n], int C[][n]) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;
    int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
    int B11[k][k], B12[k][k], B21[k][k], B22[k][k];

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    int M1[k][k], M2[k][k], M3[k][k], M4[k][k], M5[k][k], M6[k][k], M7[k][k];
    int temp1[k][k], temp2[k][k];

    add(k, A11, A22, temp1);
    add(k, B11, B22, temp2);
    strassen(k, temp1, temp2, M1);

    add(k, A21, A22, temp1);
    strassen(k, temp1, B11, M2);

    subtract(k, B12, B22, temp2);
    strassen(k, A11, temp2, M3);

    subtract(k, B21, B11, temp2);
    strassen(k, A22, temp2, M4);

    add(k, A11, A12, temp1);
    strassen(k, temp1, B22, M5);

    subtract(k, A21, A11, temp1);
    add(k, B11, B12, temp2);
    strassen(k, temp1, temp2, M6);

    subtract(k, A12, A22, temp1);
    add(k, B21, B22, temp2);
    strassen(k, temp1, temp2, M7);

    int C11[k][k], C12[k][k], C21[k][k], C22[k][k];

    add(k, M1, M4, temp1);
    subtract(k, temp1, M5, temp2);
    add(k, temp2, M7, C11);

    add(k, M3, M5, C12);
    add(k, M2, M4, C21);

    subtract(k, M1, M2, temp1);
    add(k, temp1, M3, temp2);
    add(k, temp2, M6, C22);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j] = C11[i][j];
            C[i][j + k] = C12[i][j];
            C[i + k][j] = C21[i][j];
            C[i + k][j + k] = C22[i][j];
        }
    }
}

int nextPowerOfTwo(int n) {
    int power = 1;
    while (power < n)
        power *= 2;
    return power;
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    printf("Enter rows and columns of Matrix A: ");
    scanf("%d %d", &rowsA, &colsA);

    printf("Enter rows and columns of Matrix B: ");
    scanf("%d %d", &rowsB, &colsB);

    if (colsA != rowsB) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    int maxSize = rowsA > colsA ? rowsA : colsA;
    if (rowsB > maxSize) maxSize = rowsB;
    if (colsB > maxSize) maxSize = colsB;

    int size = nextPowerOfTwo(maxSize);

    int A[size][size], B[size][size], C[size][size];

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++) {
            A[i][j] = 0;
            B[i][j] = 0;
            C[i][j] = 0;
        }

    printf("Enter elements of Matrix A:\n");
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of Matrix B:\n");
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++)
            scanf("%d", &B[i][j]);

    strassen(size, A, B, C);

    printf("\nResultant Matrix:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
