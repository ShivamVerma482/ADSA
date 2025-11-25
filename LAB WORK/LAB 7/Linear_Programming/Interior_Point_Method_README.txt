Below is the **clean README-style content**, formatted only with headings, paragraphs, lists, tables, and diagrams.
No author, no project structure, no ChatGPT-style commentary.
You can copy–paste directly into a GitHub README.md.

---

# Interior Point Method (IPM)

A minimal educational algorithm for solving simple linear optimization problems.

## Introduction

The Interior Point Method (IPM) is an iterative algorithm used to solve linear optimization problems by moving through the *interior* of the feasible region instead of along its edges. Unlike the simplex method, which traverses vertices of the polytope, IPM follows a smooth path known as the **central path** toward the optimal solution.
This method is efficient, numerically stable, and forms the foundation of many modern industrial optimization solvers.

---

## Problem Definition

The standard form of a linear optimization problem is:

```
Minimize:      cᵀx  
Subject to:    Ax = b  
               x ≥ 0  
```

Where:

* A is an m×n constraint matrix
* b is an m-dimensional vector
* c is an n-dimensional objective coefficient vector
* x is the vector of decision variables

The goal is to find a feasible vector x that minimizes the objective function.

---

## Core Idea of Interior Point Methods

Interior Point Methods avoid the boundary of the feasible region and move towards the optimum by:

1. Maintaining strictly positive values for decision variables (x > 0).
2. Replacing inequalities with a smooth “barrier” function that discourages approaching the boundary.
3. Solving a sequence of barrier subproblems that gradually reduce the influence of the barrier.

This creates a curved, smooth trajectory toward the optimal solution.

---

## Barrier Function

To prevent x from becoming zero or negative, the algorithm augments the objective with a logarithmic barrier:

```
ϕ(x) = – Σ ln(xᵢ)
```

This barrier becomes extremely large as any xᵢ approaches 0, pushing the solution away from the boundary.

The modified optimization problem becomes:

```
Minimize:      cᵀx + (1/t) * ϕ(x)  
Subject to:    Ax = b  
```

Where t is a positive parameter controlling the strength of the barrier.

* Large t → weak barrier
* Small t → strong barrier

As t increases progressively, the solution approaches the true optimum of the original linear program.

---

## Central Path

At each t, the solution to the barrier problem lies on the **central path**, which connects the interior of the feasible region to the optimal point.
The IPM algorithm follows this central path by repeatedly solving Newton systems related to the Karush–Kuhn–Tucker (KKT) conditions.

---

## Algorithm Overview

### Step 1: Initialization

Choose an initial interior point x₀ such that:

* Ax₀ = b
* x₀ > 0

Select an initial value of t (often small).

### Step 2: Form Barrier Objective

Construct the barrier-augmented objective:

```
Fₜ(x) = cᵀx + (1/t) * (– Σ ln(xᵢ))
```

### Step 3: Compute Newton Direction

Solve the Newton system from the gradient and Hessian of Fₜ(x) subject to the equality constraint Ax = b.

This yields a search direction d:

```
x_new = x + α d
```

Where α is chosen to ensure x_new remains strictly positive.

### Step 4: Update the Variables

Move along the interior direction:

```
x ← x_new
```

### Step 5: Increase t

Increase t to reduce barrier strength and bring the solution closer to the LP optimum.

A common update:

```
t ← μ t
```

Where μ > 1.

### Step 6: Repeat

Continue iterations until:

* The duality gap becomes very small
* x converges to an optimal point

---

## Duality Gap

A key measure of convergence is the **duality gap**, often approximated as:

```
gap = n / t
```

Where n is the number of variables.
As t becomes large, the gap approaches 0, indicating convergence.

---

## Conceptual Diagram (Text Illustration)

```
Feasible Region (Polygon)

         Optimal Point (Vertex)
                 *
               /  
     Central Path (smooth curve)
           ------
        ----
     ---
  --
Interior starting point (x0)
```

The method follows the curved central path instead of jumping between vertices.

---

## Comparison With Simplex Method

| Property             | Simplex Method        | Interior Point Method         |
| -------------------- | --------------------- | ----------------------------- |
| Path type            | Moves along edges     | Moves through interior        |
| Typical speed        | Very fast in practice | Very fast and polynomial-time |
| Numerical stability  | Can face degeneracy   | Very stable                   |
| Large-scale problems | Sometimes slower      | Highly efficient              |
| Output               | Exact vertex solution | Interior → boundary → optimum |

---

## Advantages

* Polynomial-time algorithm
* Works well for large-scale linear optimization
* Avoids cycling and degeneracy
* Smooth, stable numerical behavior
* Foundation for many commercial solvers

---

## Limitations

* Requires matrix factorizations (can be expensive)
* Needs feasible interior starting point (or uses Phase I variants)
* May require careful handling for poorly conditioned systems

---

## Applications

Interior Point Methods are widely used in:

* Industrial linear programming
* Network optimization
* Resource allocation
* Logistics and transportation
* Portfolio optimization
* Convex optimization and machine learning

---

## Conclusion

The Interior Point Method offers a powerful and elegant framework for solving linear optimization problems. By combining barrier functions, Newton’s method, and duality theory, IPM provides a smooth, globally convergent pathway to the optimal solution. It is one of the most successful algorithms in mathematical optimization and remains central to modern solver design.

---

