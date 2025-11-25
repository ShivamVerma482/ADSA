# Heap Sort — README

## Introduction

Heap Sort is a **comparison-based sorting algorithm** that uses a **binary heap data structure** to sort elements efficiently. It is an example of a **selection sort** where the largest (or smallest) element is repeatedly extracted from a heap and placed in its correct position.

Heap Sort is widely used due to its **guaranteed O(n log n) time complexity** and in-place sorting capability.

---

## Purpose

The program (not included here) demonstrates how to sort an array of elements using Heap Sort. The algorithm is useful for:

* Large datasets where predictable time complexity is required
* Systems with memory constraints (in-place sorting)
* Teaching heap data structures and their applications

---

## Key Concepts

### Binary Heap

A **binary heap** is a complete binary tree satisfying the **heap property**:

* **Max Heap:** Parent node ≥ children nodes (used for ascending order sorting)
* **Min Heap:** Parent node ≤ children nodes (used for descending order sorting)

### Heapify

The process of maintaining the heap property by **rearranging nodes** is called **heapify**. It is applied:

* After inserting a new element
* After removing the root

---

## Heap Sort Algorithm

### Steps

1. **Build Heap:** Convert the array into a max heap (for ascending sort)
2. **Extract Elements:**

   * Swap the root (maximum) with the last element
   * Reduce heap size by 1
   * Heapify the root to maintain the heap property
3. Repeat extraction until the heap is empty

### Flow

```
Unsorted Array → Build Max Heap → Swap Root with Last → Heapify → Repeat → Sorted Array
```

---

## Time Complexity

| Operation         | Complexity |
| ----------------- | ---------- |
| Building Heap     | O(n)       |
| Heapify per node  | O(log n)   |
| Sorting all nodes | O(n log n) |

* **Best Case:** O(n log n)
* **Worst Case:** O(n log n)
* **Average Case:** O(n log n)

Heap Sort has **guaranteed performance**, unlike Quick Sort which can degrade to O(n²) in worst cases.

---

## Space Complexity

* Heap Sort is **in-place**: O(1) additional memory
* Does not require extra arrays or recursion stack

---

## Advantages

* Predictable O(n log n) time complexity
* In-place sorting; no extra memory required
* Works well for large datasets

---

## Limitations

* Not a **stable sorting algorithm** (relative order of equal elements may change)
* Slower in practice than Quick Sort for small datasets due to more comparisons

---

## Example Illustration

Consider array: `[4, 10, 3, 5, 1]`

1. Build Max Heap: `[10, 5, 3, 4, 1]`
2. Swap root with last: `[1, 5, 3, 4, 10]`
3. Heapify root: `[5, 4, 3, 1, 10]`
4. Repeat until sorted: `[1, 3, 4, 5, 10]`

---

## Applications

* Priority queues
* Scheduling algorithms
* Large dataset sorting where stable sort is not required
* Situations requiring guaranteed O(n log n) sorting time

---

## Summary

Heap Sort is a reliable, in-place sorting algorithm based on **binary heap structure**. It guarantees **O(n log n) performance** and is particularly useful in environments where memory usage must be minimized. Understanding Heap Sort also reinforces the concepts of **heap data structures** and **divide-and-conquer strategies**.

---


  
