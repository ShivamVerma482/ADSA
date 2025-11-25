# LU Decomposition — README

## Introduction

LU decomposition is a matrix factorization technique used to simplify solving systems of linear equations, computing determinants, and performing matrix inversions. It expresses a square matrix **A** as the product of two simpler matrices:

* **L**: Lower triangular matrix
* **U**: Upper triangular matrix

The factorization takes the form:

```
A = L U
```

This decomposition allows solving linear systems efficiently through forward and backward substitution.

---

## Purpose of the Program

The program (not included here) performs LU decomposition on a square matrix and uses the decomposition to:

* Solve linear equations of the form `A x = b`
* Compute the determinant of matrix **A**
* Facilitate efficient matrix operations in numerical computing

---

## Key Concepts

### Lower Triangular Matrix (L)

Contains all zeros above the diagonal.
Diagonal entries may be 1 depending on the decomposition variant.

### Upper Triangular Matrix (U)

Contains all zeros below the diagonal.

### Requirements

LU decomposition works only when:

* Matrix **A** is square
* No pivot element becomes zero during elimination (unless pivoting is used)

---

## How LU Decomposition Works

LU decomposition mirrors Gaussian elimination. The idea is to convert matrix **A** into an upper triangular matrix **U**, while recording the multipliers used during elimination in the lower triangular matrix **L**.

### Step-by-step Process

#### Step 1: Start with Matrix A

Example:

```
A = [ a11  a12  a13 ]
    [ a21  a22  a23 ]
    [ a31  a32  a33 ]
```

#### Step 2: Perform Gaussian Elimination

Eliminate entries below the pivot.

For row 2:

```
m21 = a21 / a11
```

For row 3:

```
m31 = a31 / a11
```

These multipliers form entries in **L**, and modified values form **U**.

#### Step 3: Repeat for Remaining Columns

Continue elimination until **U** is fully upper triangular and **L** is fully lower triangular.

---

## Structure of L and U

For a 3×3 matrix:

```
L = [ 1     0     0   ]
    [ l21   1     0   ]
    [ l31  l32    1   ]

U = [ u11  u12  u13 ]
    [ 0    u22  u23 ]
    [ 0     0   u33 ]
```

---

## Solving Linear Systems Using LU

To solve:

```
A x = b
```

Rewrite using decomposition:

```
L U x = b
```

### Step 1: Forward Substitution

Solve:

```
L y = b
```

### Step 2: Backward Substitution

Solve:

```
U x = y
```

The final vector **x** is the solution.

---

## Determinant Using LU

The determinant of **A** is the product of the diagonal entries of **U**:

```
det(A) = u11 × u22 × ... × unn
```

This makes determinant computation simple and efficient.

---

## Example Table: Comparison with LUP

| Feature            | LU                    | LUP (Pivoting)           |
| ------------------ | --------------------- | ------------------------ |
| Stability          | Lower                 | Higher                   |
| Handles Zero Pivot | No                    | Yes                      |
| Extra Matrix       | No                    | Yes (Permutation Matrix) |
| Best for           | Well-behaved matrices | General matrices         |

---

## Applications

* Solving batches of linear equations
* Engineering computations
* Computer graphics
* Numerical simulations
* Optimization problems
* Computing matrix inverses efficiently

---

## Advantages

* Faster than computing inverse matrices directly
* Reduces repeated calculations if solving multiple equations with same **A**
* Foundation for many numerical linear algebra techniques

---

## Limitations

* Fails when pivot element becomes zero
* Less stable for poorly conditioned matrices
* Works only for square matrices
* Pivoting not included unless extended to LUP decomposition

---

## Summary

LU decomposition breaks a complex matrix into simple triangular components that allow efficient solving and numerical computation. It is one of the most widely used tools in linear algebra and serves as a building block for advanced algorithms.

