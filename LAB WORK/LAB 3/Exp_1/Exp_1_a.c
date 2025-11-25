//Write	a	program	that	use	both	recursive	and	non	recursive	functions	to	   
// perform	the	Binary	search	operation	for	a	Key	value	in	a	given	list	of	integers.	


#include <stdio.h>

// Non-recursive binary search
int binarySearchIterative(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;                   // Key found
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Key not found
}

// Recursive binary search
int binarySearchRecursive(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;  // Key not found

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;                       // Found
    else if (key < arr[mid])
        return binarySearchRecursive(arr, low, mid - 1, key);
    else
        return binarySearchRecursive(arr, mid + 1, high, key);
}

int main() {
    int n, key, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted integers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter key to search: ");
    scanf("%d", &key);

    // Non-recursive search
    int index1 = binarySearchIterative(arr, n, key);
    if (index1 != -1)
        printf("Iterative: Key found at index %d\n", index1);
    else
        printf("Iterative: Key not found\n");

    // Recursive search
    int index2 = binarySearchRecursive(arr, 0, n - 1, key);
    if (index2 != -1)
        printf("Recursive: Key found at index %d\n", index2);
    else
        printf("Recursive: Key not found\n");

    return 0;
}
