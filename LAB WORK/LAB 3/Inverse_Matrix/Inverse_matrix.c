// Program that Inverse a given Matrix

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 10
#define EPS 1e-9  // Tolerance for zero check

// Function to display a matrix
void displayMatrix(double mat[MAX][MAX], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%10.4lf ", mat[i][j]);
        printf("\n");
    }
}

// Function to inverse a matrix using Gauss-Jordan elimination
int inverseMatrix(double A[MAX][MAX], double inverse[MAX][MAX], int n) {
    // Initialize inverse as identity matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inverse[i][j] = (i == j) ? 1 : 0;

    // Forward elimination
    for (int i = 0; i < n; i++) {
        // Find pivot
        double pivot = A[i][i];
        if (fabs(pivot) < EPS) {
            printf("Matrix is singular and cannot be inverted.\n");
            return 0;
        }

        // Normalize the row
        for (int j = 0; j < n; j++) {
            A[i][j] /= pivot;
            inverse[i][j] /= pivot;
        }

        // Eliminate other rows
        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            double factor = A[k][i];
            for (int j = 0; j < n; j++) {
                A[k][j] -= factor * A[i][j];
                inverse[k][j] -= factor * inverse[i][j];
            }
        }
    }

    return 1;  // Successful inversion
}

int main() {
    int n;
    double A[MAX][MAX], inv[MAX][MAX];

    printf("Enter order of square matrix (n): ");
    scanf("%d", &n);

    printf("Enter matrix elements (%dx%d):\n", n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    if (inverseMatrix(A, inv, n)) {
        printf("\nInverse Matrix:\n");
        displayMatrix(inv, n);
    }

    return 0;
}
