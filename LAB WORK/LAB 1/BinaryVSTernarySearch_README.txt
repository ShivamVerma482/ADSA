# Binary Search vs Ternary Search — Searching Time Analysis — README

## Introduction

Binary Search and Ternary Search are two fundamental algorithms used to find elements in a **sorted array**. Both use the divide-and-conquer principle to reduce the search space, but they differ in the number of divisions per iteration:

* **Binary Search:** Divides the array into **two parts**
* **Ternary Search:** Divides the array into **three parts**

Analyzing their searching time helps understand efficiency in practical and theoretical contexts.

---

## Purpose

This documentation explains the **searching time analysis** of Binary and Ternary Search. It focuses on:

* Time complexity
* Number of comparisons per iteration
* Theoretical vs practical efficiency
* Use cases where each method is preferable

---

## Binary Search — Time Analysis

### Algorithm Steps

1. Start with the entire sorted array.
2. Check the middle element.
3. If the element matches → search ends.
4. If target < middle → search left half.
5. If target > middle → search right half.
6. Repeat until the element is found or array is exhausted.

### Time Complexity

* Best Case: O(1) → element found at first middle comparison
* Worst Case: O(log₂ n) → element found after multiple halving steps
* Average Case: O(log₂ n)

### Comparisons

* One comparison per iteration (with middle element)

---

## Ternary Search — Time Analysis

### Algorithm Steps

1. Split the array into three equal parts.
2. Compare the target with the two mid-points.
3. Discard the third where the target cannot exist.
4. Repeat recursively on the remaining segment.

### Time Complexity

* Best Case: O(1) → element matches one of the mid-points on first check
* Worst Case: O(log₃ n) → element found after repeatedly dividing into thirds
* Average Case: O(log₃ n)

### Comparisons

* Two comparisons per iteration (with both mid-points)

---

## Comparison Table

| Feature                 | Binary Search        | Ternary Search                           |
| ----------------------- | -------------------- | ---------------------------------------- |
| Division of Array       | 2 parts              | 3 parts                                  |
| Time Complexity (worst) | O(log₂ n)            | O(log₃ n)                                |
| Comparisons per Step    | 1                    | 2                                        |
| Practical Efficiency    | Faster in most cases | Slightly slower due to extra comparisons |
| Use Case                | General searching    | Unimodal function search, optimization   |

---

## Observations

* Although log₃ n < log₂ n theoretically, **binary search often performs fewer total comparisons** due to only one check per iteration.
* Ternary search can be more useful in **optimization problems** where the search is over a unimodal function instead of a discrete array.
* Both algorithms require the input to be **sorted**.

---

## Graphical Intuition

* **Binary Search:** Each step reduces search space by 50%
* **Ternary Search:** Each step reduces search space by ~33%
* Number of iterations is fewer in ternary search, but more comparisons per step make binary search faster in practice for discrete arrays.

```
Binary Search: n → n/2 → n/4 → ... → 1
Ternary Search: n → 2n/3 → 4n/9 → ... → 1
```

---

## Practical Notes

* For small arrays, the difference is negligible.
* For large arrays, binary search is usually more efficient for standard lookups.
* Ternary search shines when used in **continuous search domains** like numerical optimization or unimodal function maxima/minima searches.

---

## Summary

* **Binary Search:** Simpler, fewer comparisons per iteration, faster in practice.
* **Ternary Search:** Slightly fewer iterations but more comparisons per step, useful for optimization tasks.
* Both algorithms highlight the power of divide-and-conquer for reducing search time in sorted or structured data.

---
