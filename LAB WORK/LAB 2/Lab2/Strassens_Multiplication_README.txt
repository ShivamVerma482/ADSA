# Strassen’s Matrix Multiplication — README

## Introduction

Strassen’s algorithm is an optimized divide-and-conquer method for multiplying two square matrices faster than the standard cubic-time algorithm. Instead of using the traditional **O(n³)** approach, Strassen reduces the number of multiplications, achieving a complexity of approximately **O(n²·81)**. This makes the method useful for large matrices and scientific computing.

---

## Purpose

The program (not included here) implements Strassen’s algorithm to multiply two matrices more efficiently than the classical approach. It demonstrates the power of recursive subdivision and reduction in computational cost.

---

## Key Idea Behind Strassen’s Algorithm

Standard matrix multiplication requires **8 multiplications** for combining 2×2 blocks of matrices.
Strassen discovered that the same result can be achieved with **7 multiplications** and additional additions/subtractions, greatly reducing overall cost when applied recursively.

---

## Working Principle

### Block Matrix Representation

Given two n×n matrices **A** and **B**, divide each into four n/2 × n/2 submatrices:

```
A = | A11  A12 |
    | A21  A22 |

B = | B11  B12 |
    | B21  B22 |
```

### Strassen’s Seven Products

Instead of calculating 8 block multiplications, compute:

```
M1 = (A11 + A22)(B11 + B22)
M2 = (A21 + A22)(B11)
M3 = (A11)(B12 - B22)
M4 = (A22)(B21 - B11)
M5 = (A11 + A12)(B22)
M6 = (A21 - A11)(B11 + B12)
M7 = (A12 - A22)(B21 + B22)
```

### Combining the Results

The resulting matrix **C = A × B** is computed as:

```
C11 = M1 + M4 - M5 + M7
C12 = M3 + M5
C21 = M2 + M4
C22 = M1 - M2 + M3 + M6
```

---

## Complexity

| Method                  | Time Complexity |
| ----------------------- | --------------- |
| Standard Multiplication | O(n³)           |
| Strassen’s Algorithm    | O(n²·81)        |

This improvement becomes significant for larger values of **n**, especially in scientific and high-performance computing tasks.

---

## Requirements and Constraints

* Works best on matrices where **n is a power of 2**
* For other sizes, matrices can be padded with zeros
* More additions are required compared to standard multiplication
* Numerical stability may be lower for floating-point values

---

## Advantages

* Faster than classical matrix multiplication for large matrices
* Useful in algorithms for solving linear systems and matrix inversions
* Demonstrates divide-and-conquer optimization in numerical computation

---

## Limitations

* Overhead from recursion and extra additions may outweigh benefits for small matrices
* Not ideal for memory-constrained environments
* Can introduce numerical inaccuracies for floating-point calculations
* Requires padding when dimensions are not powers of 2

---

## Example Illustration

### Comparison of Operations for 2×2 Block Case:

| Operation Type  | Standard | Strassen |
| --------------- | -------- | -------- |
| Multiplications | 8        | 7        |
| Add/Subtract    | 4        | 18       |

Although additions increase, the key optimization is reducing multiplications, which are more expensive operations.

---

## Applications

* High-performance computing
* Scientific simulations
* Graphics processing
* Algorithms requiring fast matrix multiplication
* Computational linear algebra

---

## Summary

Strassen’s algorithm demonstrates how intelligent restructuring of matrix operations can significantly reduce computational effort. It remains a classic example of the power of divide-and-conquer and serves as the basis for many modern fast matrix multiplication algorithms.

