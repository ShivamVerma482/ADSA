# Sorting Using Quick Sort, Merge Sort, and Heap Sort

This document provides an explanation of three major comparison-based sorting algorithms used to arrange a list of integers in ascending order. The program implements **Quick Sort**, **Merge Sort**, and **Heap Sort**, allowing comparison between their performance characteristics and operational methods. All three algorithms follow different strategies but ultimately produce a fully sorted list.

---

## Introduction

Sorting is one of the most fundamental operations in computer science. Efficient sorting improves the performance of searching, merging, and other data-processing tasks. This program demonstrates three well-known and widely used algorithms:

* Quick Sort (Divide-and-Conquer method)
* Merge Sort (Stable Divide-and-Conquer method)
* Heap Sort (Binary Heap–based selection method)

Each algorithm works differently and has its own advantages depending on the input data.

---

## Overview of the Algorithms

### Quick Sort

Quick Sort is a divide-and-conquer algorithm that selects a pivot element and partitions the list so that smaller elements move to the left and larger ones move to the right. It then sorts each partition recursively.

**Key points:**

* Uses partitioning around a pivot
* Works in-place
* Very fast for average cases
* Worst case occurs with poor pivot choices

### Merge Sort

Merge Sort breaks the list into halves recursively until single-element lists remain. Then it merges these sorted pieces back together to form a fully sorted list.

**Key points:**

* Stable sorting algorithm
* Requires additional memory for merging
* Excellent performance even in worst case
* Suitable for large datasets

### Heap Sort

Heap Sort uses a binary heap data structure to repeatedly extract the maximum element and build the sorted list. The algorithm first builds a max heap and then performs heapify operations.

**Key points:**

* Uses heap structure
* Performs sorting in-place
* Consistent worst-case performance
* Not stable, but memory efficient

---

## Comparison of Sorting Algorithms

| Feature        | Quick Sort         | Merge Sort         | Heap Sort            |
| -------------- | ------------------ | ------------------ | -------------------- |
| Approach       | Divide-and-Conquer | Divide-and-Conquer | Heap-based selection |
| Best Case      | O(n log n)         | O(n log n)         | O(n log n)           |
| Average Case   | O(n log n)         | O(n log n)         | O(n log n)           |
| Worst Case     | O(n²)              | O(n log n)         | O(n log n)           |
| Space Used     | O(log n)           | O(n)               | O(1)                 |
| Stable         | No                 | Yes                | No                   |
| Works In-Place | Yes                | No                 | Yes                  |

---

## How the Program Works

1. The user enters the number of integers and the list elements.
2. The program creates copies of the list so each sorting method works independently.
3. Quick Sort, Merge Sort, and Heap Sort are applied to their respective copies.
4. The sorted results are displayed for all three algorithms.
5. If needed, the outputs can be compared to verify correctness and performance.

This allows easy observation of how each algorithm transforms the same input list.

---

## Example Input and Output

### Example Input

```
Enter number of elements: 8
Enter elements: 23 5 18 42 9 12 31 3
```

### Example Output

```
Quick Sort Result: 3 5 9 12 18 23 31 42
Merge Sort Result: 3 5 9 12 18 23 31 42
Heap Sort Result: 3 5 9 12 18 23 31 42
```

All algorithms produce identical sorted output even though their internal processes differ significantly.

---

## When Each Algorithm Is Best

* **Quick Sort:** Best for general-purpose in-memory sorting when average performance matters.
* **Merge Sort:** Best when consistent performance is needed or when sorting linked lists.
* **Heap Sort:** Best when memory usage must be minimal and predictable.

---

## Summary

This program demonstrates three important sorting algorithms that follow different methodologies but achieve the same end goal: sorting a list of integers in ascending order. By implementing Quick Sort, Merge Sort, and Heap Sort in one program, it becomes easier to understand their advantages, limitations, and differences. The comparison highlights how algorithm choice can influence memory usage, performance, and stability depending on the application.

