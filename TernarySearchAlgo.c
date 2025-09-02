// Ternary Search Algorithm

 

#include <stdio.h>

// Ternary Search Function

int ternarySearch(int arr[], int left, int right, int target) {

    if (left <= right) {

        // Calculate the mid points

        int mid1 = left + (right -left) / 3;

        int mid2 = right - (right -left) / 3;

        // Check if target is at mid1 or mid2

        if (arr[mid1] == target) {

            return mid1;

        }

        if (arr[mid2] == target) {

            return mid2;

        }

        // searching the element

        if (target < arr[mid1]) {

            return ternarySearch(arr, left, mid1 - 1, target);

        } else if (target > arr[mid2]) {

            return ternarySearch(arr, mid2 + 1, right, target);

        } else {

            return ternarySearch(arr, mid1 + 1, mid2 -1, target);

        }

    }

    // If Target not found

    return -1;

}

int main() {

    int n;

    printf("Enter the number of elements in the array:");

    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements in sorted order:\n");

    for (int i = 0; i < n; i++) 

    {

        scanf("%d", &arr[i]);

    }

    int target;

    printf("Enter the target element to search for: ");

    scanf("%d", &target);

    int result = ternarySearch(arr, 0, n - 1, target);

    if (result == -1) {

        printf("Element not found in the array.\n");

    } else {

        printf("Element found at index %d.\n", result);

    }

    return 0;

}
