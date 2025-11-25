# **README – Minimum Spanning Tree Using Prim’s Algorithm from SIF Graph**

## **Introduction**

This project demonstrates how to find the **Minimum Spanning Tree (MST)** of a graph using **Prim’s algorithm**.
The graph is provided in **Simple Interaction Format (SIF)**, which lists edges and their weights in a simple text format.
Prim’s algorithm builds the MST **incrementally**, starting from a single node and adding the **cheapest edge** connecting the tree to a new vertex at each step.

---

## **What Is a Minimum Spanning Tree (MST)?**

* A spanning tree includes **all vertices** with **minimum total edge weight**.
* Ensures **exactly one path** between any two nodes.

### **Key Features**

| Feature                  | Description                                                                   |
| ------------------------ | ----------------------------------------------------------------------------- |
| Edge Selection           | Always pick the edge with **minimum weight** connecting the MST to a new node |
| Incremental Construction | Starts from a single vertex and grows the MST step by step                    |
| Total Weight             | Minimizes sum of all edges in the MST                                         |

---

## **Simple Interaction Format (SIF)**

* Represents graphs as **pairs of nodes with interaction type and weight**.
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

## **Prim’s Algorithm Overview**

### **Steps**

1. Start with any **vertex** as the initial MST.
2. **Find the edge with minimum weight** that connects a node in the MST to a node outside it.
3. **Add the selected edge** and the new vertex to the MST.
4. Repeat until **all vertices are included** in the MST.

### **Key Concepts**

* **Priority Queue / Min-Heap**: Can be used to efficiently select the smallest edge.
* **Visited Set**: Keeps track of vertices already included in the MST.

---

## **Step-by-Step Example**

### **Graph Edges**

```
A-B 4
B-C 3
A-C 5
C-D 2
```

### **MST Construction Steps**

| Step | Edge Selected | Action                            | MST Edges     |
| ---- | ------------- | --------------------------------- | ------------- |
| 1    | Start at A    | Initial vertex                    | A             |
| 2    | A-B (4)       | Minimum edge from MST → add       | A-B           |
| 3    | B-C (3)       | Minimum edge connecting MST → add | A-B, B-C      |
| 4    | C-D (2)       | Minimum edge connecting MST → add | A-B, B-C, C-D |

**MST Edges:** `A-B, B-C, C-D`
**Total Weight:** `4 + 3 + 2 = 9`

---

## **Algorithm Complexity**

| Aspect                          | Complexity |
| ------------------------------- | ---------- |
| Using adjacency matrix          | O(V²)      |
| Using adjacency list + min-heap | O(E log V) |

Where V = number of vertices, E = number of edges.

---

## **Use Cases**

* Network design (telecommunication, computer networks)
* Road and railway planning
* Electrical grid optimization
* Clustering in data analysis
* Any application requiring minimal connectivity cost

---

## **Advantages**

* Simple and intuitive MST construction
* Efficient for **dense graphs**
* Can start from any vertex
* Greedy approach guarantees **minimum total weight**

---

## **Limitations**

* Requires a connected graph
* Only works for **weighted graphs**
* Needs careful handling of priority selection for large graphs

---

## **Conclusion**

This project explains how to generate a **Minimum Spanning Tree from a SIF graph using Prim’s algorithm**.
It highlights incremental construction, selection of minimum-weight edges, and ensures all vertices are connected efficiently with minimal total cost.

