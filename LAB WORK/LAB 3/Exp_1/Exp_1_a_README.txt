# Binary Search (Recursive and Non-Recursive)

This document explains how the program performs **Binary Search** using both **recursive** and **iterative (non-recursive)** methods on a sorted list of integers. It also describes input, output, algorithm steps, limitations, and examples to help understand the program easily.

---

## Introduction

Binary Search is an efficient searching technique used to find the position of a target value (key) inside a **sorted** list. Instead of scanning every element, it repeatedly divides the search interval in half, reducing the time complexity to **O(log n)**.

The program provides two approaches:

* **Recursive Binary Search**
* **Non-Recursive (Iterative) Binary Search**

Both functions return the index of the key if found, otherwise return `-1`.

---

## How Binary Search Works

Binary Search operates on a sorted array by comparing the key with the middle element.

| Step | Action                                      |
| ---- | ------------------------------------------- |
| 1    | Find the middle index                       |
| 2    | Compare middle value with key               |
| 3    | If matched → search ends                    |
| 4    | If key < middle value → search left half    |
| 5    | If key > middle value → search right half   |
| 6    | Repeat until found or range becomes invalid |

This approach drastically reduces the number of comparisons.

---

## Features of the Program

* Accepts a list of integers from the user
* Requires the list to be sorted (ascending order)
* Searches the key using:

  * Recursive function
  * Non-Recursive function
* Displays the result from both functions separately
* Clearly shows index position if the key is present

---

## Recursive Binary Search Overview

The recursive binary search function repeatedly divides the array and calls itself on the appropriate half.

### Steps:

1. Base case: if `low > high`, the key is not found
2. Calculate middle index
3. Check:

   * If middle element equals key → return index
   * If key is smaller → search left sub-array
   * Otherwise → search right sub-array

This method uses the call stack to remember intervals.

---

## Non-Recursive Binary Search Overview

The non-recursive method uses a loop to perform the same operations without recursion.

### Steps:

1. Initialize `low` and `high` pointers
2. While `low <= high`, calculate the middle index
3. Compare key with middle value
4. Move `low` or `high` accordingly
5. If the key is found, return its index
6. If loop ends, key does not exist

This method avoids recursive overhead and is iterative.

---

## Example Input and Output

### Example Input

```
Enter number of elements: 6
Enter sorted elements: 2 5 9 13 21 30
Enter key to search: 13
```

### Example Output

```
Recursive Search: Key found at index 3
Non-Recursive Search: Key found at index 3
```

### When key does not exist:

```
Recursive Search: Key not found
Non-Recursive Search: Key not found
```

---

## Time and Space Complexity

| Method        | Time Complexity | Space Complexity                |
| ------------- | --------------- | ------------------------------- |
| Recursive     | O(log n)        | O(log n) due to recursion stack |
| Non-Recursive | O(log n)        | O(1)                            |

Both approaches are efficient, but the iterative version is slightly more memory-friendly.

---

## Important Notes

* The input list **must be sorted** before performing binary search.
* The index returned is based on **0-based indexing**.
* Both functions work only for integer arrays in this program.

---

## Summary

This program demonstrates how Binary Search can be implemented using both recursive and non-recursive techniques. It highlights the efficiency of divide-and-conquer searching and allows comparison between the two methods. You can use this as a foundation for learning search algorithms or extending it to more complex data structures.

