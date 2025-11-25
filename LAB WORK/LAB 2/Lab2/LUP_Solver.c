#include <stdio.h>
#include <math.h>

#define N 3
#define EPS 1e-9

// Swap two matrix rows and permutation entries
void swap_rows(double A[N][N], int P[N], int r1, int r2) {
    for (int j = 0; j < N; j++) {
        double tmp = A[r1][j];
        A[r1][j] = A[r2][j];
        A[r2][j] = tmp;
    }

    int temp = P[r1];
    P[r1] = P[r2];
    P[r2] = temp;
}

// LUP decomposition: A -> combined L & U, P = permutation
int lup_decompose(double A[N][N], int P[N]) {
    for (int i = 0; i < N; i++) P[i] = i;

    for (int k = 0; k < N; k++) {
        // Pivot search
        int pivot = k;
        double maxval = fabs(A[k][k]);

        for (int i = k + 1; i < N; i++) {
            if (fabs(A[i][k]) > maxval) {
                maxval = fabs(A[i][k]);
                pivot = i;
            }
        }

        if (maxval < EPS) return 0; // matrix is singular

        // Swap if needed
        if (pivot != k)
            swap_rows(A, P, k, pivot);

        // Elimination
        for (int i = k + 1; i < N; i++) {
            A[i][k] /= A[k][k];

            for (int j = k + 1; j < N; j++) {
                A[i][j] -= A[i][k] * A[k][j];
            }
        }
    }
    return 1;
}

// Solve system Ax = b using LUP decomposition
void lup_solve(double A[N][N], int P[N], double b[N], double x[N]) {
    double y[N];

    // Forward substitution: Ly = Pb
    for (int i = 0; i < N; i++) {
        y[i] = b[P[i]];

        for (int j = 0; j < i; j++) {
            y[i] -= A[i][j] * y[j];
        }
    }

    // Backward substitution: Ux = y
    for (int i = N - 1; i >= 0; i--) {
        x[i] = y[i];

        for (int j = i + 1; j < N; j++) {
            x[i] -= A[i][j] * x[j];
        }

        x[i] /= A[i][i];
    }
}

int main() {
    double A[N][N], b[N], x[N];
    int P[N];

    printf("Enter matrix A (%dx%d):\n", N, N);
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%lf", &A[i][j]);

    printf("Enter vector b (%d values):\n", N);
    for (int i = 0; i < N; i++)
        scanf("%lf", &b[i]);

    if (!lup_decompose(A, P)) {
        printf("\nMatrix is singular! Cannot solve.\n");
        return 1;
    }

    lup_solve(A, P, b, x);

    printf("\nSolution vector x:\n");
    for (int i = 0; i < N; i++) {
        if (fabs(x[i]) < 1e-9) x[i] = 0; // avoid -0
        printf("x[%d] = %.6f\n", i, x[i]);
    }

    return 0;
}
