// Programs	that	implement	Quick	Sort	by	taking	median	as	the	pivot	
// element	to	sort	a	given	list	of	integers	in	ascending	order.	

#include <stdio.h>

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to find median of first, middle, last elements
int medianOfThree(int arr[], int low, int high) {
    int mid = (low + high) / 2;

    // Order low, mid, high
    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);

    if (arr[mid] > arr[high])
        swap(&arr[mid], &arr[high]);

    if (arr[low] > arr[mid])
        swap(&arr[low], &arr[mid]);

    // median is now at arr[mid]
    swap(&arr[mid], &arr[high - 1]);  // Move median to high-1 as pivot

    return arr[high - 1];
}

// Partition using median-of-three pivot
int partition(int arr[], int low, int high) {
    int pivot = medianOfThree(arr, low, high);

    int i = low;
    int j = high - 1;

    while (1) {
        while (arr[++i] < pivot);
        while (arr[--j] > pivot);

        if (i < j)
            swap(&arr[i], &arr[j]);
        else
            break;
    }

    swap(&arr[i], &arr[high - 1]);  // Place pivot in its correct position
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low + 2 <= high) {  // At least 3 elements needed
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    } 
    else {
        // For small size, use simple sorting (like insertion sort)
        if (arr[low] > arr[high])
            swap(&arr[low], &arr[high]);
    }
}

// Print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// -------------------- MAIN PROGRAM --------------------
int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    quickSort(arr, 0, n - 1);

    printf("\nSorted Array (Quick Sort with Median Pivot):\n");
    printArray(arr, n);

    return 0;
}
