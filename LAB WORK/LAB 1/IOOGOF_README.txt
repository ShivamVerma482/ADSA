# Increasing Order of Growth of Functions — README

## Introduction

Order of growth describes how fast a function increases relative to the size of its input. It is commonly used in algorithm analysis to compare the efficiency of different algorithms. Understanding growth rates helps determine which algorithm performs better as input size becomes large.

---

## Purpose

This documentation explains the increasing order of growth of common mathematical functions used in computational complexity. It also presents comparisons, examples, and a reference table.

---

## What Is Order of Growth?

Order of growth focuses on the dominant term of a function as the input size **n** becomes very large.
It ignores constants and lower-order terms.
For example:

* `3n² + 2n + 7` has order of growth **n²**
* `100 log n` has order of growth **log n**

---

## Why It Matters

* Helps compare algorithms
* Predicts performance for large input sizes
* Determines feasibility in real-world scenarios
* Guides optimization and design decisions

---

## Common Growth Categories (Slowest → Fastest)

The following list shows growth rates from smallest (best performance) to largest (worst performance):

1. **Constant:** 1
2. **Logarithmic:** log n
3. **Linear:** n
4. **Linearithmic:** n log n
5. **Quadratic:** n²
6. **Cubic:** n³
7. **Polynomial:** nᵏ (k > 3)
8. **Exponential:** 2ⁿ
9. **Factorial:** n!

---

## Visual Comparison Table

| Growth Class | Example Function | Relative Speed              |
| ------------ | ---------------- | --------------------------- |
| Constant     | 1, 5, 100        | Slowest growth (best)       |
| Logarithmic  | log n            | Grows very slowly           |
| Linear       | n                | Moderate growth             |
| Linearithmic | n log n          | Slightly faster than linear |
| Quadratic    | n²               | Much faster growth          |
| Cubic        | n³               | Very fast growth            |
| Polynomial   | n⁴, n⁵           | Rapid growth                |
| Exponential  | 2ⁿ               | Extremely fast growth       |
| Factorial    | n!               | Fastest growth (worst)      |

---

## Example: Ordering Functions

Consider the following functions:

* `log n`
* `n`
* `n log n`
* `n²`
* `2ⁿ`

Their order of growth (increasing):

```
log n  <  n  <  n log n  <  n²  <  2ⁿ
```

---

## Graphical Intuition

When plotted on a graph (n on x-axis, growth on y-axis):

* Constant and logarithmic curves grow slowly
* Linear and n log n grow moderately
* Quadratic and polynomial curves rise quickly
* Exponential and factorial curves explode upward

Even though logarithmic and linear might look similar for small **n**, the differences become huge at large **n**.

---

## Practical Relevance in Algorithms

| Algorithm Type                        | Typical Complexity |
| ------------------------------------- | ------------------ |
| Binary Search                         | O(log n)           |
| Hash Table Operations                 | O(1)               |
| Merge Sort                            | O(n log n)         |
| Bubble Sort                           | O(n²)              |
| Matrix Multiplication (naive)         | O(n³)              |
| Dynamic Programming (like subset sum) | O(2ⁿ)              |
| Traveling Salesman (brute-force)      | O(n!)              |

Better algorithms tend to have lower growth rates.

---

## Summary

* Order of growth helps compare efficiency between algorithms.
* Smaller growth rates scale better for large input sizes.
* Knowing growth rates is essential for designing optimal solutions.

