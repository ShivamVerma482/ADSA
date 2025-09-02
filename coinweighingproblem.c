#include <stdio.h>

// Simulated balance weighing: returns
// -1 if left < right, 0 if equal, +1 if left > right
int weigh(int left[], int lsize, int right[], int rsize) {
    int lw = 0, rw = 0;
    for (int i = 0; i < lsize; i++) lw += left[i];
    for (int i = 0; i < rsize; i++) rw += right[i];
    if (lw < rw) return -1;
    else if (lw > rw) return 1;
    else return 0;
}

int findDefectiveCoin(int coins[], int n) {
    if (n == 1) {
        // If this coin is lighter than perfect weight (say weight 10), it is defective
        return 0; // index of defective
    }

    int mid = n / 2;
    int result = weigh(coins, mid, coins + mid, n - mid);

    if (result == -1) {
        // left half is lighter
        return findDefectiveCoin(coins, mid);
    } else if (result == 1) {
        // right half is lighter
        int idx = findDefectiveCoin(coins + mid, n - mid);
        return mid + idx; // adjust index
    } else {
        // No defective coin found
        return -1;
    }
}

int main() {
    // Suppose perfect weight = 10
    int coins[] = {10, 10, 9, 10, 10, 10};  // 3rd coin is defective
    int n = sizeof(coins) / sizeof(coins[0]);

    int idx = findDefectiveCoin(coins, n);

    if (idx == -1)
        printf("No defective coin found\n");
    else
        printf("Defective coin found at index %d\n", idx);

    return 0;
}
