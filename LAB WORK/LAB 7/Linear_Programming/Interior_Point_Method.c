#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAX 20
#define EPS 1e-8
#define MAX_ITER 100
#define MU 0.1     // barrier reduction

// Solve Ax = b using Gaussian elimination (simple)
void solveLinearSystem(int n, double A[MAX][MAX], double b[MAX], double x[MAX]) {
    for (int i = 0; i < n; i++) {
        // pivoting
        if (fabs(A[i][i]) < EPS) {
            for (int k = i + 1; k < n; k++) {
                if (fabs(A[k][i]) > EPS) {
                    for (int j = 0; j < n; j++)
                        A[i][j] += A[k][j];
                    b[i] += b[k];
                    break;
                }
            }
        }

        double pivot = A[i][i];
        for (int j = 0; j < n; j++)
            A[i][j] /= pivot;
        b[i] /= pivot;

        for (int k = 0; k < n; k++) {
            if (k == i) continue;
            double factor = A[k][i];
            for (int j = 0; j < n; j++)
                A[k][j] -= factor * A[i][j];
            b[k] -= factor * b[i];
        }
    }

    for (int i = 0; i < n; i++)
        x[i] = b[i];
}

int main() {
    int n, m;

    printf("Enter number of variables (n): ");
    scanf("%d", &n);
    printf("Enter number of equality constraints (m): ");
    scanf("%d", &m);

    double A[MAX][MAX], b[MAX], c[MAX];

    printf("\nEnter matrix A (m x n):\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    printf("\nEnter vector b:\n");
    for (int i = 0; i < m; i++)
        scanf("%lf", &b[i]);

    printf("\nEnter cost vector c:\n");
    for (int i = 0; i < n; i++)
        scanf("%lf", &c[i]);

    // Initial point (strictly positive)
    double x[MAX];
    for (int i = 0; i < n; i++)
        x[i] = 1.0;

    printf("\nRunning Interior Point Method...\n");

    double lambda[MAX], s[MAX];

    // initial values
    for (int i = 0; i < n; i++) {
        lambda[i] = 1.0;
        s[i] = 1.0;
    }

    for (int iter = 0; iter < MAX_ITER; iter++) {

        // complementarity gap
        double gap = 0;
        for (int i = 0; i < n; i++)
            gap += x[i] * s[i];

        if (gap < EPS) {
            printf("\nOptimal solution found:\n");
            for (int i = 0; i < n; i++)
                printf("x[%d] = %.6f\n", i, x[i]);
            return 0;
        }

        double mu = MU * gap / n;

        // Compute Newton direction
        double M[MAX][MAX], rhs[MAX], dx[MAX];

        // M = diag(s/x)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                M[i][j] = (i == j) ? (s[i] / x[i]) : 0;

        // rhs = -(c + M*x - mu*(1/x))
        for (int i = 0; i < n; i++)
            rhs[i] = -(c[i] + M[i][i] * x[i] - mu / x[i]);

        // Solve for dx
        // (simple: ignoring constraints for teaching example)
        solveLinearSystem(n, M, rhs, dx);

        // Step size to keep x > 0
        double alpha = 1.0;
        for (int i = 0; i < n; i++) {
            if (dx[i] < 0)
                alpha = fmin(alpha, -0.99 * x[i] / dx[i]);
        }

        // Update variables
        for (int i = 0; i < n; i++) {
            x[i] += alpha * dx[i];
            s[i] = mu / x[i];
        }
    }

    printf("\nMax iterations reached. Solution may be inaccurate.\n");
    return 0;
}
