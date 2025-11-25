# **README – Bipartite Graph Matching**

## **Introduction**

This project explains **Bipartite Graph Matching**, a key concept in graph theory and combinatorial optimization.
It focuses on finding **maximum matchings** in a bipartite graph, where vertices from two disjoint sets are paired without conflicts.

---

## **What Is a Bipartite Graph?**

* A graph is **bipartite** if its vertices can be divided into two sets, **U** and **V**, such that every edge connects a vertex in U to a vertex in V.
* There are **no edges connecting vertices within the same set**.

### **Example**

```
U = {A, B, C}
V = {X, Y, Z}
Edges: A-X, A-Y, B-Y, C-Z
```

* This is a bipartite graph as all edges are between U and V.

---

## **What Is Bipartite Graph Matching?**

* A **matching** is a set of edges where no two edges share a vertex.
* **Maximum matching**: The largest possible matching, containing the highest number of edges.
* **Perfect matching**: A matching where **every vertex is matched**.

### **Example Matching**

```
Edges selected: A-X, B-Y, C-Z
```

* All vertices are matched → perfect matching, also maximum in this case.

---

## **Algorithms for Bipartite Graph Matching**

### **1. DFS-Based Approach**

* Uses **augmenting paths** to increase matching incrementally.
* For each vertex in U, attempt to find a path to an unmatched vertex in V.
* If successful, include the edge in the matching.

### **2. Hopcroft-Karp Algorithm**

* Optimized for **unweighted bipartite graphs**.
* Uses **BFS to find multiple augmenting paths** simultaneously.
* Time Complexity: O(√V × E)

### **3. Hungarian Algorithm**

* Designed for **weighted bipartite graphs**.
* Finds maximum weight matching efficiently.
* Time Complexity: O(V³)

---

## **Step-by-Step Example**

### **Graph**

```
U = {A, B, C}
V = {X, Y, Z}
Edges: A-X, A-Y, B-Y, C-Z
```

### **Matching Process**

| Step | Vertex | Action    | Matching      |
| ---- | ------ | --------- | ------------- |
| 1    | A      | Match A-X | A-X           |
| 2    | B      | Match B-Y | A-X, B-Y      |
| 3    | C      | Match C-Z | A-X, B-Y, C-Z |

* Maximum Matching: 3 edges (also perfect matching in this case)

---

## **Algorithm Complexity**

| Algorithm            | Complexity |
| -------------------- | ---------- |
| DFS-based            | O(V × E)   |
| Hopcroft-Karp        | O(√V × E)  |
| Hungarian (weighted) | O(V³)      |

Where V = number of vertices, E = number of edges.

---

## **Applications**

* Job assignment problems
* Student-project allocation
* Network flow optimization
* Resource allocation in computing and logistics
* Scheduling tasks with constraints

---

## **Advantages**

* Efficient algorithms exist for both **weighted and unweighted bipartite graphs**
* Guarantees **optimal matching**
* Scales well with appropriate algorithm choice

---

## **Limitations**

* Only applies to **bipartite graphs**
* General graph matching requires more complex algorithms
* Weighted maximum matching is computationally more expensive

---

## **Conclusion**

Bipartite graph matching is crucial for optimization problems involving **pairing elements from two sets**.
This project covers approaches to find **maximum and perfect matchings**, illustrating practical applications in assignment, scheduling, and network problems.
