#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define MAX 20
#define MAX_ITER 5000
#define EPS 1e-6

// Check if center x satisfies all A*x <= b
int violatedConstraint(double A[MAX][MAX], double b[MAX], double x[MAX], int m, int n) {
    for (int i = 0; i < m; i++) {
        double sum = 0;
        for (int j = 0; j < n; j++)
            sum += A[i][j] * x[j];

        if (sum - b[i] > EPS)
            return i; // return index of violated constraint
    }
    return -1; // feasible
}

int main() {
    int m, n;

    printf("Enter number of constraints (m): ");
    scanf("%d", &m);

    printf("Enter number of variables (n): ");
    scanf("%d", &n);

    double A[MAX][MAX], b[MAX];

    printf("\nEnter matrix A (each row of coefficients):\n");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    printf("\nEnter vector b:\n");
    for (int i = 0; i < m; i++)
        scanf("%lf", &b[i]);

    // Ellipsoid initialization
    double x[MAX] = {0};             // Start center at origin
    double E[MAX][MAX] = {0};        // Initial ellipsoid matrix

    // Identity matrix * R^2
    double R = 100;                  // Large initial radius
    for (int i = 0; i < n; i++)
        E[i][i] = R * R;

    printf("\nRunning Ellipsoid Algorithm...\n");

    for (int iter = 0; iter < MAX_ITER; iter++) {

        int k = violatedConstraint(A, b, x, m, n);

        if (k == -1) {
            printf("\nFeasible point found:\n");
            for (int i = 0; i < n; i++)
                printf("x[%d] = %.6f\n", i, x[i]);
            return 0;
        }

        // Normalize violating constraint vector g = A[k]
        double g[MAX];
        double norm = 0;

        for (int i = 0; i < n; i++) {
            g[i] = A[k][i];
            norm += g[i] * g[i];
        }
        norm = sqrt(norm);

        for (int i = 0; i < n; i++)
            g[i] /= norm;

        // Compute E*g
        double Eg[MAX];
        for (int i = 0; i < n; i++) {
            Eg[i] = 0;
            for (int j = 0; j < n; j++)
                Eg[i] += E[i][j] * g[j];
        }

        // Compute denominator g^T E g
        double gEg = 0;
        for (int i = 0; i < n; i++)
            gEg += g[i] * Eg[i];

        // Update center: x = x - Eg / (n+1)
        for (int i = 0; i < n; i++)
            x[i] -= Eg[i] / (n + 1.0);

        // Update ellipsoid matrix
        double alpha = 2.0 / (n + 1.0);
        double beta = (n * n) / (n * n - 1.0);

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                E[i][j] = beta * (E[i][j] - alpha * (Eg[i] * Eg[j]) / gEg);
    }

    printf("\nNo feasible solution found (iterations exhausted).\n");
    return 0;
}
