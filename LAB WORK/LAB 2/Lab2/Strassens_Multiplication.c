#include <stdio.h>
#include <stdlib.h>

// Function to allocate a square matrix
int **allocate_matrix(int n) {
    int **mat = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        mat[i] = (int *)malloc(n * sizeof(int));
    return mat;
}

// Add two matrices
void add(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

// Subtract two matrices
void subtract(int **A, int **B, int **C, int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

// Strassen recursive multiplication
void strassen(int **A, int **B, int **C, int n) {
    if (n == 1) {  // Base case
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    // Allocate sub-matrices
    int **A11 = allocate_matrix(k);  int **A12 = allocate_matrix(k);
    int **A21 = allocate_matrix(k);  int **A22 = allocate_matrix(k);

    int **B11 = allocate_matrix(k);  int **B12 = allocate_matrix(k);
    int **B21 = allocate_matrix(k);  int **B22 = allocate_matrix(k);

    int **M1 = allocate_matrix(k);   int **M2 = allocate_matrix(k);
    int **M3 = allocate_matrix(k);   int **M4 = allocate_matrix(k);
    int **M5 = allocate_matrix(k);   int **M6 = allocate_matrix(k);
    int **M7 = allocate_matrix(k);

    int **tempA = allocate_matrix(k);
    int **tempB = allocate_matrix(k);

    // Divide matrices into 4 sub-matrices
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

    // M1 = (A11 + A22)(B11 + B22)
    add(A11, A22, tempA, k);
    add(B11, B22, tempB, k);
    strassen(tempA, tempB, M1, k);

    // M2 = (A21 + A22) B11
    add(A21, A22, tempA, k);
    strassen(tempA, B11, M2, k);

    // M3 = A11 (B12 - B22)
    subtract(B12, B22, tempB, k);
    strassen(A11, tempB, M3, k);

    // M4 = A22 (B21 - B11)
    subtract(B21, B11, tempB, k);
    strassen(A22, tempB, M4, k);

    // M5 = (A11 + A12) B22
    add(A11, A12, tempA, k);
    strassen(tempA, B22, M5, k);

    // M6 = (A21 - A11)(B11 + B12)
    subtract(A21, A11, tempA, k);
    add(B11, B12, tempB, k);
    strassen(tempA, tempB, M6, k);

    // M7 = (A12 - A22)(B21 + B22)
    subtract(A12, A22, tempA, k);
    add(B21, B22, tempB, k);
    strassen(tempA, tempB, M7, k);

    // Combine results into C
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            C[i][j]         = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
            C[i][j + k]     = M3[i][j] + M5[i][j];
            C[i + k][j]     = M2[i][j] + M4[i][j];
            C[i + k][j + k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
        }
    }
}

int main() {
    int n;
    printf("Enter matrix size (must be power of 2): ");
    scanf("%d", &n);

    int **A = allocate_matrix(n);
    int **B = allocate_matrix(n);
    int **C = allocate_matrix(n);

    printf("Enter matrix A:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter matrix B:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(A, B, C, n);

    printf("\nResult matrix C = A × B:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }

    return 0;
}
