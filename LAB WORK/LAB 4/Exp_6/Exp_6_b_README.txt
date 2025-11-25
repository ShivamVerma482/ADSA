# **README – Minimum Spanning Tree Using Kruskal’s Algorithm from SIF Graph**

## **Introduction**

This project demonstrates how to find the **Minimum Spanning Tree (MST)** of a graph using **Kruskal’s algorithm**.
The graph is provided in **Simple Interaction Format (SIF)**, a lightweight text format commonly used to represent edges and nodes.
A Minimum Spanning Tree connects all nodes with the **minimum total edge weight** without forming any cycles.

---

## **What Is a Minimum Spanning Tree (MST)?**

* A spanning tree of a connected graph includes **all vertices** with the **minimum possible sum of edge weights**.
* MST ensures that there is **exactly one path** between any two vertices.

### **Key Features**

| Feature          | Description                                                   |
| ---------------- | ------------------------------------------------------------- |
| Edge Selection   | Choose edges with **lowest weight first**                     |
| Cycle Prevention | Use a **disjoint-set (union-find)** structure to avoid cycles |
| Total Weight     | Minimized sum of all selected edge weights                    |

---

## **Simple Interaction Format (SIF)**

* SIF describes the graph as **pairs of nodes with interaction type and weight**.
* Format:

```
node1 interaction_type node2 weight
```

### **Example**

```
A pp B 4
B pp C 3
A pp C 5
C pp D 2
```

* Represents a weighted undirected graph with nodes A, B, C, D.

---

## **Kruskal’s Algorithm Overview**

### **Steps**

1. **Sort all edges** in ascending order of weight.
2. **Initialize MST** as empty.
3. For each edge in sorted order:

   * If adding the edge **does not form a cycle** (check using union-find):

     * Add edge to MST
4. Stop when MST contains **(V-1) edges**, where V = number of vertices

### **Key Components**

* **Union-Find (Disjoint Set)**: Efficiently checks whether adding an edge forms a cycle.
* **Edge Sorting**: Ensures edges are added from **smallest to largest weight**.

---

## **Step-by-Step Example**

### **Graph Edges**

```
A-B 4
B-C 3
A-C 5
C-D 2
```

### **Sorted Edges**

```
C-D 2
B-C 3
A-B 4
A-C 5
```

### **MST Construction**

| Step | Edge Considered | Action             | MST Edges     |
| ---- | --------------- | ------------------ | ------------- |
| 1    | C-D (2)         | No cycle → add     | C-D           |
| 2    | B-C (3)         | No cycle → add     | C-D, B-C      |
| 3    | A-B (4)         | No cycle → add     | C-D, B-C, A-B |
| 4    | A-C (5)         | Forms cycle → skip | C-D, B-C, A-B |

**MST Edges:** `C-D, B-C, A-B`
**Total Weight:** `2 + 3 + 4 = 9`

---

## **Algorithm Complexity**

| Aspect                | Complexity                         |
| --------------------- | ---------------------------------- |
| Edge Sorting          | O(E log E)                         |
| Union-Find Operations | O(E log V) (with path compression) |
| Overall               | O(E log E)                         |

Where V = number of vertices, E = number of edges.

---

## **Use Cases**

* Network design (telecommunication, computer networks)
* Road and railway optimization
* Electrical grid planning
* Clustering in data analysis
* Any problem requiring efficient connectivity with minimal cost

---

## **Advantages**

* Guarantees a **minimum total weight** MST
* Efficient for sparse graphs
* Simple to implement with union-find

---

## **Limitations**

* Requires a connected graph
* Only works with **weighted graphs**
* Cannot handle dynamic edge additions efficiently without re-running

---

## **Conclusion**

This project illustrates how to build a **Minimum Spanning Tree from a graph given in SIF format** using Kruskal’s algorithm.
It demonstrates edge sorting, cycle prevention, and MST construction, which are critical concepts in graph theory and network optimization.

