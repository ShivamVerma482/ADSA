//IOOGOF= Increasing order of growth of functions

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Struct to hold function name and its growth rank
typedef struct {
    char name[50];
    int rank; // smaller rank = slower growth
} Function;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    Function *fa = (Function*)a;
    Function *fb = (Function*)b;
    return fa->rank - fb->rank;
}

int main() {
    Function funcs[] = {
        {"1/n", 1},
        {"log2 n", 2},
        {"12√n", 3},
        {"50n^0.5", 3},    // same growth as sqrt(n)
        {"n^0.51", 4},
        {"2^32n", 5},
        {"nlog2n (1)", 6},
        {"100n^2 + 6n", 7},
        {"n^2 - 324", 7},
        {"2n^3", 8},
        {"n^log2n ", 9},
        {"3^n", 10},
    };

    int n = sizeof(funcs) / sizeof(funcs[0]);

    // Sort by rank
    qsort(funcs, n, sizeof(Function), compare);

    printf("Functions in increasing order of growth:\n\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", funcs[i].name);
    }

    return 0;
}

