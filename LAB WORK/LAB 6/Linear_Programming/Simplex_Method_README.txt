# **README – Simplex Method for Solving Linear Programming Problems**

## **Introduction**

This project demonstrates the **Simplex Method**, a widely used algorithm to solve **Linear Programming (LP) problems**.
Linear Programming involves optimizing a **linear objective function** subject to **linear constraints**, commonly used in operations research, economics, and engineering.

---

## **What Is Linear Programming?**

* Linear Programming (LP) seeks to **maximize or minimize** a linear function:

```
Maximize or Minimize: Z = c1*x1 + c2*x2 + ... + cn*xn
```

* Subject to **linear constraints**:

```
a11*x1 + a12*x2 + ... + a1n*xn ≤ b1
...
am1*x1 + am2*x2 + ... + amn*xn ≤ bm
x1, x2, ..., xn ≥ 0
```

### **Example**

```
Maximize Z = 3x + 2y
Subject to:
x + y ≤ 4
x ≤ 2
y ≤ 3
x, y ≥ 0
```

---

## **Simplex Method Overview**

The **Simplex Method** is an iterative algorithm that moves from one **vertex (feasible solution) to another** along the edges of the feasible region, improving the objective function at each step.

### **Key Concepts**

* **Basic Feasible Solution (BFS)**: Solution where number of non-zero variables equals the number of constraints.
* **Pivot Operation**: Moves from one BFS to a better BFS by entering and leaving variables.
* **Optimality Condition**: When no further improvement in objective function is possible.

---

## **Algorithm Steps**

1. **Convert LP into standard form**

   * Ensure all constraints are ≤ type, and all variables ≥ 0
   * Introduce **slack variables** to convert inequalities into equalities

2. **Set up initial simplex tableau**

   * Includes coefficients of variables in objective function and constraints

3. **Iterative Process**

   * **Identify entering variable**: The variable with the most negative coefficient in objective row (for maximization)
   * **Identify leaving variable**: Using **minimum ratio test** (ratio of RHS to pivot column values)
   * **Pivot**: Update tableau to reflect the new BFS

4. **Check Optimality**

   * If all coefficients in objective row ≥ 0 (for maximization), current BFS is optimal
   * Otherwise, repeat pivoting

5. **Read Solution**

   * Values of variables in the optimal tableau give the **solution to LP problem**

---

## **Example Tableau (Maximization)**

| Basic Var | x  | y  | s1 | s2 | RHS |
| --------- | -- | -- | -- | -- | --- |
| s1        | 1  | 1  | 1  | 0  | 4   |
| s2        | 1  | 0  | 0  | 1  | 2   |
| Z         | -3 | -2 | 0  | 0  | 0   |

* **Pivot operations** are performed until all coefficients in Z row are ≥ 0

---

## **Algorithm Complexity**

| Aspect                | Complexity                                  |
| --------------------- | ------------------------------------------- |
| Iterations            | Worst-case exponential O(2^n)               |
| Practical performance | Polynomial time on most real-world problems |

---

## **Applications**

* Production and manufacturing optimization
* Resource allocation and workforce planning
* Transportation and logistics problems
* Diet and nutrition planning
* Financial portfolio optimization

---

## **Advantages**

* Provides **exact optimal solution**
* Systematic and iterative method suitable for computer implementation
* Can handle multiple variables and constraints efficiently

---

## **Limitations**

* Requires LP problem to be in **linear form**
* Computationally intensive for **very large problems**
* Sensitive to **degeneracy** (can lead to cycling)

---

## **Conclusion**

The Simplex Method is a cornerstone of **linear programming** and optimization.
By systematically moving along the feasible region’s vertices, it identifies the **optimal solution** efficiently, making it invaluable in operations research, economics, and engineering applications.
