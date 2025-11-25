#include <stdio.h>

#define MAX 10

int main() {
    int n;
    float A[MAX][MAX], L[MAX][MAX], U[MAX][MAX];

    printf("Enter order of matrix (n): ");
    scanf("%d", &n);

    printf("Enter matrix A (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%f", &A[i][j]);
        }
    }

    // Initialize L and U matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            L[i][j] = 0;
            U[i][j] = 0;
        }
    }

    // Doolittle Algorithm
    for (int i = 0; i < n; i++) {

        // Upper Triangular (U)
        for (int k = i; k < n; k++) {
            float sum = 0;
            for (int j = 0; j < i; j++)
                sum += L[i][j] * U[j][k];

            U[i][k] = A[i][k] - sum;
        }

        // Lower Triangular (L)
        for (int k = i; k < n; k++) {
            if (i == k)
                L[i][i] = 1;  // Diagonal = 1
            else {
                float sum = 0;
                for (int j = 0; j < i; j++)
                    sum += L[k][j] * U[j][i];

                if (U[i][i] == 0) {
                    printf("LU decomposition not possible (zero pivot).\n");
                    return 0;
                }

                L[k][i] = (A[k][i] - sum) / U[i][i];
            }
        }
    }

    // Print L
    printf("\nLower Triangular Matrix L:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%8.4f ", L[i][j]);
        printf("\n");
    }

    // Print U
    printf("\nUpper Triangular Matrix U:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%8.4f ", U[i][j]);
        printf("\n");
    }

    return 0;
}
