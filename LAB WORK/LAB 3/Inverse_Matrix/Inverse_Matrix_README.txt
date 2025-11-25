# **README – Matrix Inversion in C**

## **Introduction**

This project demonstrates how to **compute the inverse of a square matrix** using the C programming language.
Matrix inversion is a fundamental operation in linear algebra, widely used in solving systems of linear equations, computer graphics, engineering, and scientific computations.

---

## **What Is a Matrix Inverse?**

The **inverse of a square matrix A**, denoted as (A^{-1}), is a matrix that, when multiplied by A, yields the **identity matrix**.

### **Mathematical Representation**

```
A × A⁻¹ = I
```

Where **I** is the identity matrix.

### **Requirements**

* Matrix must be **square** (same number of rows and columns)
* Determinant of the matrix must be **non-zero**

---

## **Methods for Finding Inverse**

1. **Using Adjoint and Determinant**

   * Find determinant of the matrix
   * Compute the cofactor matrix
   * Take the transpose of the cofactor matrix to get adjoint
   * Divide each element by the determinant to get the inverse

2. **Using Gaussian Elimination**

   * Augment the original matrix with identity matrix
   * Perform row operations to transform the left part into identity
   * The right part becomes the inverse

---

## **Algorithm Overview (Adjoint Method)**

### **Steps**

1. **Compute determinant** of the matrix
2. If determinant is **0**, inverse does not exist
3. **Find cofactor matrix**
4. **Transpose cofactor matrix** to get adjoint
5. **Divide each element of adjoint** by determinant → inverse matrix

---

## **Example**

### **Matrix**

```
A = | 2  1 |
    | 5  3 |
```

### **Determinant**

```
det(A) = (2*3) - (1*5) = 1
```

### **Cofactor Matrix**

```
C = |  3  -1 |
    | -5   2 |
```

### **Adjoint (Transpose of Cofactor)**

```
adj(A) = |  3  -5 |
         | -1   2 |
```

### **Inverse Matrix**

```
A⁻¹ = 1/det(A) × adj(A)
A⁻¹ = |  3  -5 |
       | -1   2 |
```

---

## **Algorithm Complexity**

| Step                    | Complexity                                      |
| ----------------------- | ----------------------------------------------- |
| Determinant (recursive) | O(n!)                                           |
| Cofactor matrix         | O(n³)                                           |
| Adjoint and division    | O(n²)                                           |
| Overall                 | O(n³) (optimized for practical implementations) |

Where n = size of the matrix (n × n).

---

## **Use Cases**

* Solving systems of linear equations (Ax = b)
* Engineering simulations and modeling
* Computer graphics transformations
* Control systems and robotics
* Data science and machine learning algorithms

---

## **Advantages**

* Provides exact solution for invertible square matrices
* Fundamental for linear algebra operations
* Can be implemented in basic C without advanced libraries

---

## **Limitations**

* Cannot invert **non-square** matrices
* Determinant must be non-zero
* Computationally expensive for large matrices using naive methods

---

## **Conclusion**

This project illustrates how to compute the **inverse of a matrix in C**.
Understanding matrix inversion helps in solving complex linear systems and is an essential skill in scientific computing and engineering applications.

