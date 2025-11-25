#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>      // for fabs

#define MAX 20
#define EPS 1e-9

void printTable(double table[MAX][MAX], int rows, int cols) {
    printf("\nSimplex Table:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%8.2f ", table[i][j]);
        printf("\n");
    }
}

// Function to find pivot column (most negative value in last row)
int findPivotColumn(double table[MAX][MAX], int cols) {
    int pivotCol = -1;
    double min = 0.0;
    for (int j = 0; j < cols-1; j++) {
        if (table[0][j] < min - EPS) {
            min = table[0][j];
            pivotCol = j;
        }
    }
    return pivotCol;
}

// Function to find pivot row using minimum ratio test
int findPivotRow(double table[MAX][MAX], int rows, int cols, int pivotCol) {
    int pivotRow = -1;
    double minRatio = 1e20;
    for (int i = 1; i < rows; i++) {
        if (table[i][pivotCol] > EPS) {
            double ratio = table[i][cols-1] / table[i][pivotCol]; // last column = RHS
            if (ratio < minRatio) {
                minRatio = ratio;
                pivotRow = i;
            }
        }
    }
    return pivotRow;
}

// Perform pivot operation
void pivotOperation(double table[MAX][MAX], int rows, int cols, int pivotRow, int pivotCol) {
    double pivot = table[pivotRow][pivotCol];
    for (int j = 0; j < cols; j++)
        table[pivotRow][j] /= pivot;

    for (int i = 0; i < rows; i++) {
        if (i != pivotRow) {
            double factor = table[i][pivotCol];
            for (int j = 0; j < cols; j++)
                table[i][j] -= factor * table[pivotRow][j];
        }
    }
}

// Simplex method
void simplex(double table[MAX][MAX], int rows, int cols) {
    while (true) {
        int pivotCol = findPivotColumn(table, cols);
        if (pivotCol == -1) break; // optimal solution found

        int pivotRow = findPivotRow(table, rows, cols, pivotCol);
        if (pivotRow == -1) {
            printf("Unbounded solution.\n");
            return;
        }

        pivotOperation(table, rows, cols, pivotRow, pivotCol);
        //printTable(table, rows, cols); // optional: show each iteration
    }

    printf("\nOptimal Solution Found:\n");
    for (int j = 0; j < cols-1; j++) {
        bool isBasic = false;
        double val = 0.0;
        for (int i = 1; i < rows; i++) {
            if (fabs(table[i][j] - 1.0) < EPS) {
                bool onlyOne = true;
                for (int k = 1; k < rows; k++)
                    if (k != i && fabs(table[k][j]) > EPS)
                        onlyOne = false;
                if (onlyOne) {
                    val = table[i][cols-1];
                    isBasic = true;
                    break;
                }
            }
        }
        printf("x%d = %.2f\n", j+1, isBasic ? val : 0.0);
    }
    printf("Maximum Value of Z = %.2f\n", table[0][cols-1]);
}

int main() {
    int variables, constraints;
    double table[MAX][MAX];

    printf("Enter number of variables: ");
    scanf("%d", &variables);
    printf("Enter number of constraints: ");
    scanf("%d", &constraints);

    int rows = constraints + 1;
    int cols = variables + constraints + 1;

    printf("Enter the coefficients of objective function (Z = c1*x1 + c2*x2 + ...):\n");
    for (int j = 0; j < variables; j++)
        scanf("%lf", &table[0][j]);
    for (int j = variables; j < cols; j++)
        table[0][j] = 0.0;

    printf("Enter the coefficients of constraints and RHS (format: a1 a2 ... an b):\n");
    for (int i = 1; i < rows; i++) {
        for (int j = 0; j < variables; j++)
            scanf("%lf", &table[i][j]);
        for (int j = variables; j < variables + constraints; j++)
            table[i][j] = (j - variables == i - 1) ? 1.0 : 0.0; // slack variables
        scanf("%lf", &table[i][cols-1]); // RHS
    }

    simplex(table, rows, cols);

    return 0;
}
