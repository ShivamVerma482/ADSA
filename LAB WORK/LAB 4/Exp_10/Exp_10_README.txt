# **README – Matrix Multiplication Using Strassen’s Algorithm**

## **Introduction**

This project demonstrates how to **multiply two matrices using Strassen’s algorithm**, an advanced divide-and-conquer method for matrix multiplication.
Strassen’s algorithm reduces the number of scalar multiplications compared to the conventional method, improving performance for large matrices.

---

## **What Is Strassen’s Algorithm?**

* Strassen’s algorithm multiplies two **square matrices** more efficiently than the naive approach.
* It reduces the standard **O(n³)** time complexity to approximately **O(n^2.81)**.
* Works by recursively dividing matrices into **submatrices** and combining results using **seven key multiplications** instead of eight.

---

## **Key Concepts**

1. **Divide**: Split matrices A and B into four submatrices each.

   ```
   A = | A11  A12 |
       | A21  A22 |

   B = | B11  B12 |
       | B21  B22 |
   ```
2. **Conquer**: Compute seven intermediate matrices (M1 to M7) using combinations of submatrices:

   ```
   M1 = (A11 + A22) * (B11 + B22)
   M2 = (A21 + A22) * B11
   M3 = A11 * (B12 - B22)
   M4 = A22 * (B21 - B11)
   M5 = (A11 + A12) * B22
   M6 = (A21 - A11) * (B11 + B12)
   M7 = (A12 - A22) * (B21 + B22)
   ```
3. **Combine**: Construct the resulting matrix C using M1 to M7:

   ```
   C11 = M1 + M4 - M5 + M7
   C12 = M3 + M5
   C21 = M2 + M4
   C22 = M1 - M2 + M3 + M6
   ```

---

## **Example**

### **Matrices**

```
A = | 1 2 |
    | 3 4 |

B = | 5 6 |
    | 7 8 |
```

### **Strassen Multiplication Result**

```
C = | 19 22 |
    | 43 50 |
```

* Matches the conventional multiplication result.

---

## **Algorithm Complexity**

| Aspect                  | Complexity                      |
| ----------------------- | ------------------------------- |
| Standard multiplication | O(n³)                           |
| Strassen’s algorithm    | O(n^log2 7) ≈ O(n^2.81)         |
| Space                   | O(n²) (for storing submatrices) |

---

## **Use Cases**

* Large-scale matrix multiplication in scientific computing
* Graphics transformations and simulations
* Numerical linear algebra applications
* Machine learning computations (e.g., neural network operations)
* High-performance computing where large matrices are involved

---

## **Advantages**

* Reduces number of multiplications, improving efficiency
* Works recursively for matrices of size 2^n × 2^n
* Suitable for large matrices where performance gains are significant

---

## **Limitations**

* More **additions/subtractions** compared to conventional method
* Slightly higher memory usage due to recursive submatrices
* Not always faster for **small matrices** due to overhead
* Requires matrices to be square and preferably of size 2^n × 2^n (can be padded otherwise)

---

## **Conclusion**

This project illustrates **Strassen’s algorithm for matrix multiplication**, showcasing a divide-and-conquer approach that reduces computation compared to the traditional method.
It is particularly useful for large matrices in high-performance and scientific computing environments.
