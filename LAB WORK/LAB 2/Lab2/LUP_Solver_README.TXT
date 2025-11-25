# LUP Solver — README

## Introduction

LUP decomposition is a numerical method used to solve systems of linear equations, compute matrix inverses, and determine determinants. It decomposes a square matrix **A** into three components:

* **L**: Lower triangular matrix
* **U**: Upper triangular matrix
* **P**: Permutation matrix

This decomposition allows efficient and stable solving of equations of the form:

```
A x = b
```

Instead of directly solving the system, the problem is transformed into:

```
P A = L U
```

This rearrangement improves numerical stability, especially when partial pivoting is required.

---

## Purpose of the Program

The program (not included here) uses LUP decomposition to:

* Factor a matrix into **L**, **U**, and **P** components
* Solve the linear system using forward and backward substitution
* Handle cases requiring row permutations
* Provide accurate solutions even when the matrix has small pivot elements

---

## Key Concepts

### Decomposition

LUP decomposition finds matrices **L**, **U**, and **P** such that:

```
P A = L U
```

* **P** is a permutation matrix that represents row swaps done during pivoting.
* **L** is lower triangular with all diagonal entries equal to 1.
* **U** is upper triangular.

### Why Use Pivoting?

Pivoting avoids division by values close to zero, which could create large numerical errors.

Partial pivoting ensures:

* Improved numerical stability
* Reduced risk of floating-point overflow/underflow

---

## Steps in LUP Decomposition

### Step 1: Identify Pivot

Choose the row with the largest absolute value in the current column.

### Step 2: Swap Rows

Swap the current row with the pivot row and update the permutation matrix **P**.

### Step 3: Eliminate

Use Gaussian elimination to fill entries in **L** and **U**:

* Entries below the pivot become part of **L**
* Entries above remain part of **U**

---

## Solving the System

Once the decomposition is obtained:

### Step 1: Compute `Pb`

Multiply the permutation matrix **P** with vector **b**.

### Step 2: Forward Substitution

Solve the lower triangular system:

```
L y = P b
```

### Step 3: Backward Substitution

Solve the upper triangular system:

```
U x = y
```

The result is the solution vector **x**.

---

## Example of L, U, and P Structure

For a 3×3 matrix:

```
L = [ 1     0     0   ]
    [ l21   1     0   ]
    [ l31  l32    1   ]

U = [ u11  u12  u13 ]
    [ 0    u22  u23 ]
    [ 0     0   u33 ]

P = [ 0 1 0 ]
    [ 1 0 0 ]
    [ 0 0 1 ]
```

---

## Determinant Using LUP

The determinant of matrix **A** can be computed easily using:

```
det(A) = det(P) × product of diagonal entries of U
```

Permutation matrix determinant:

* +1 if even number of row swaps
* –1 if odd number of row swaps

---

## Properties

| Property   | Description                                |
| ---------- | ------------------------------------------ |
| Stability  | High, due to pivoting                      |
| Format     | Works only with square matrices            |
| Efficiency | Similar to Gaussian elimination            |
| Complexity | O(n³) for decomposition, O(n²) for solving |

---

## Applications

* Numerical solution of linear systems
* Matrix inversion
* Determinant computation
* Simulation and modeling
* Optimization problems
* Scientific and engineering computations

---

## Advantages

* More stable than simple LU decomposition
* Handles zero or small pivots through row swapping
* Good for large or dense matrices

---

## Limitations

* Not suitable for singular matrices
* Requires square matrices
* Pivoting adds additional steps compared to plain LU decomposition

---

## Summary

LUP decomposition provides a robust and reliable method for solving linear systems by combining:

* Lower triangular factor
* Upper triangular factor
* Permutation-based pivoting

This makes it a core tool in numerical linear algebra and scientific computation.

