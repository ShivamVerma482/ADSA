#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Binary Search Function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low)/2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

// Ternary Search Function
int ternarySearch(int arr[], int low, int high, int key) {
    while (low <= high) {
        int mid1 = low + (high - low)/3;
        int mid2 = high - (high - low)/3;
        
        if (arr[mid1] == key) return mid1;
        if (arr[mid2] == key) return mid2;
        
        if (key < arr[mid1])
            high = mid1 - 1;
        else if (key > arr[mid2])
            low = mid2 + 1;
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
}

int main() {
    int n, key;
    
    printf("Enter size of the array: ");
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));
    
    // Fill array with sorted elements
    for(int i = 0; i < n; i++)
        arr[i] = i + 1;
    
    printf("Enter element to search: ");
    scanf("%d", &key);
    
    clock_t start, end;
    double time_taken;
    
    // Binary Search Timing
    start = clock();
    int result_b = binarySearch(arr, n, key);
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    if(result_b != -1)
        printf("Binary Search: Element found at index %d\n", result_b);
    else
        printf("Binary Search: Element not found\n");
    printf("Time taken by Binary Search: %lf seconds\n", time_taken);
    
    // Ternary Search Timing
    start = clock();
    int result_t = ternarySearch(arr, 0, n - 1, key);
    end = clock();
    time_taken = ((double)(end - start))/CLOCKS_PER_SEC;
    if(result_t != -1)
        printf("Ternary Search: Element found at index %d\n", result_t);
    else
        printf("Ternary Search: Element not found\n");
    printf("Time taken by Ternary Search: %lf seconds\n", time_taken);
    
    free(arr);
    return 0;
}
