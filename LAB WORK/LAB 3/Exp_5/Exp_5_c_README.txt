# **README – All-Pairs Shortest Path Using Floyd-Warshall Algorithm**

## **Introduction**

This project demonstrates how to compute the **shortest paths between all pairs of nodes** in a weighted graph using the **Floyd-Warshall algorithm**.
Floyd-Warshall is a dynamic programming approach that efficiently handles graphs, including both directed and undirected edges, with **non-negative or negative weights** (but no negative cycles).

---

## **What Is Floyd-Warshall Algorithm?**

The Floyd-Warshall algorithm calculates the shortest distance between every pair of vertices by progressively improving an estimate through all possible intermediate nodes.

### **Key Features**

* Works for **weighted graphs**
* Computes **all-pairs shortest paths**
* Handles negative edge weights (no negative cycles)
* Uses a **distance matrix** for calculations

---

## **Graph Representation**

* **Nodes (Vertices)**: Entities in the graph
* **Edges**: Connections between nodes with a weight (distance or cost)
* **Adjacency Matrix**: Stores initial weights of edges; `∞` represents no direct connection

### **Example Matrix**

|   | A | B | C | D |
| - | - | - | - | - |
| A | 0 | 3 | ∞ | 7 |
| B | 8 | 0 | 2 | ∞ |
| C | 5 | ∞ | 0 | 1 |
| D | 2 | ∞ | ∞ | 0 |

---

## **Algorithm Overview**

### **Steps**

1. Initialize a **distance matrix** equal to the graph’s adjacency matrix.
2. Consider each node as an **intermediate node** one by one.
3. For every pair of nodes `(i, j)`, check if the path `i → k → j` is **shorter** than the current `i → j`.
4. If yes, update `distance[i][j]` with the new shorter path.
5. Repeat for all intermediate nodes.

**Mathematical Formulation:**

```
for k from 1 to n:
    for i from 1 to n:
        for j from 1 to n:
            if distance[i][k] + distance[k][j] < distance[i][j]:
                distance[i][j] = distance[i][k] + distance[k][j]
```

---

## **Step-by-Step Example**

### **Graph Edges**

```
A → B = 3
A → D = 7
B → C = 2
C → D = 1
D → A = 2
```

### **Initial Distance Matrix**

|   | A | B | C | D |
| - | - | - | - | - |
| A | 0 | 3 | ∞ | 7 |
| B | ∞ | 0 | 2 | ∞ |
| C | ∞ | ∞ | 0 | 1 |
| D | 2 | ∞ | ∞ | 0 |

### **After Floyd-Warshall Updates**

|   | A | B | C | D |
| - | - | - | - | - |
| A | 0 | 3 | 5 | 6 |
| B | 3 | 0 | 2 | 3 |
| C | 3 | 6 | 0 | 1 |
| D | 2 | 5 | 7 | 0 |

**Result:** All pairs now have their shortest paths computed.

---

## **Algorithm Complexity**

| Aspect | Complexity |
| ------ | ---------- |
| Time   | O(V³)      |
| Space  | O(V²)      |

Where V = number of vertices.

---

## **Use Cases**

* Network routing and optimization
* Social network analysis
* All-pairs pathfinding in games
* Traffic and logistics planning
* Bioinformatics (e.g., shortest path in protein interaction networks)

---

## **Advantages**

* Simple and systematic approach
* Handles negative weights (except negative cycles)
* Computes all-pairs shortest paths in one run

---

## **Limitations**

* High time complexity for large graphs (O(V³))
* Requires adjacency matrix, which can be memory-intensive
* Cannot handle graphs with negative cycles

---

## **Conclusion**

Floyd-Warshall algorithm provides a reliable method for calculating **shortest paths between all node pairs** in a graph.
It is widely used in network analysis, optimization problems, and computational applications requiring full path information.

