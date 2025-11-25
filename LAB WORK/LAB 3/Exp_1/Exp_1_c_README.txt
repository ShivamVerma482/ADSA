# Quick Sort Using Median-as-Pivot

This document provides a clear explanation of implementing **Quick Sort using the median element as the pivot** to sort a list of integers in ascending order. Using the median-of-three pivot selection improves the efficiency of Quick Sort and significantly reduces the chances of hitting the worst-case time complexity.

---

## Introduction

Quick Sort is a fast divide-and-conquer sorting algorithm. The efficiency of Quick Sort largely depends on how the pivot is selected. Choosing a poor pivot—such as the first or last element in an already sorted list—can degrade performance. To avoid this, an improved pivot selection technique known as the **median-of-three method** is used.

This approach chooses the pivot as the median value among:

* The first element
* The middle element
* The last element

This generally leads to a better-balanced partition and improves overall performance.

---

## Median-of-Three Pivot Strategy

The median-of-three pivot strategy works by comparing three key elements of the list (first, middle, last) and selecting the median value among them. This helps avoid skewed partitions and reduces the likelihood of encountering the worst-case behavior that typically happens when the pivot is the smallest or largest element.

### Why Median Pivot Works Better

* It reduces the probability of extremely unbalanced partitions
* It improves performance for partially sorted or reverse-sorted input
* It provides more consistent partitioning quality
* It helps Quick Sort maintain close-to-optimal performance across many types of inputs

---

## How the Algorithm Works

### Step 1: Select Pivot Using Median-of-Three

The algorithm inspects the first, middle, and last elements of the list. It rearranges them so the median value becomes the pivot.

### Step 2: Partition the List

All elements smaller than the pivot are moved to the left, and all elements larger than the pivot are moved to the right. This partitioning step forms the core of Quick Sort.

### Step 3: Recursively Sort Sublists

The sublists on the left and right of the pivot are independently sorted using the same strategy until the entire list becomes sorted.

---

## Time and Space Complexity

| Case         | Time Complexity                               |
| ------------ | --------------------------------------------- |
| Best Case    | O(n log n)                                    |
| Average Case | O(n log n)                                    |
| Worst Case   | O(n²), but much less likely with median pivot |

### Space Usage

* Generally **O(log n)** due to recursive stack frames
* Sorting is performed **in-place**, meaning no extra large memory blocks are needed

---

## Advantages of Using Median-as-Pivot

* Reduces the chance of worst-case O(n²) behavior
* More reliable performance on large or partially sorted datasets
* Better partition balancing
* Improved speed over naive pivot selections
* Works efficiently for random data and repeated values

---

## Example Flow (Illustrative)

Given a list:

```
[30, 5, 12, 50, 22, 18, 9]
```

1. First = 30
2. Middle = 50 (mid element)
3. Last = 9
4. Median of (30, 50, 9) is **30**

Pivot = 30

List partitions into:

* Left: values < 30 → [5, 12, 22, 18, 9]
* Right: values > 30 → [50]

The same method is applied recursively until sorting is complete.

---

## Summary

Quick Sort using the median-of-three pivot selection is an optimized and reliable version of the traditional Quick Sort. By picking a pivot closer to the true middle value, it achieves more balanced partitions, ensures faster sorting on average, and reduces the likelihood of worst-case scenarios. This technique is well-suited for general-purpose sorting tasks and efficiently handles diverse input patterns.

