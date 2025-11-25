# **README – Single Source Shortest Path Using Dijkstra’s Algorithm**

## **Introduction**

This project demonstrates how to find the **shortest path** from a single source node to all other nodes in a weighted graph using **Dijkstra’s algorithm**.
Dijkstra’s algorithm is a classic method in graph theory for efficiently computing minimum distances in graphs with **non-negative edge weights**.

---

## **What Is Dijkstra’s Algorithm?**

Dijkstra’s algorithm calculates the **minimum distance** from a starting node (source) to all other nodes in a graph by iteratively selecting the closest unvisited node and updating distances of its neighbors.

---

## **Key Concepts**

### **Graph Components**

| Component     | Description                                            |
| ------------- | ------------------------------------------------------ |
| Node (Vertex) | Represents an entity or point in the graph             |
| Edge          | Connection between nodes with an associated weight     |
| Weight        | Cost or distance associated with the edge              |
| Source Node   | Starting node from which shortest paths are calculated |

### **Assumptions**

* Edge weights are **non-negative**
* Graph can be **directed** or **undirected**
* All nodes are reachable from the source node (if not, distance remains infinity for unreachable nodes)

---

## **Algorithm Overview**

### **Steps**

1. Initialize distances for all nodes:

   * Distance to source = 0
   * Distance to all other nodes = ∞
2. Maintain a **priority queue** or set of unvisited nodes.
3. While there are unvisited nodes:

   * Pick the node with **minimum distance**
   * Mark it as visited
   * For each neighbor:

     * Calculate **tentative distance** via current node
     * If tentative distance < current stored distance → update distance
4. Repeat until all nodes are visited
5. The final distances represent **shortest paths** from the source

---

## **Example**

### **Graph**

```
Nodes: A, B, C, D
Edges: A-B(1), A-C(4), B-C(2), B-D(5), C-D(1)
Source: A
```

### **Step-by-Step Table**

| Current Node | Distance Array     | Action                     |
| ------------ | ------------------ | -------------------------- |
| A            | A=0, B=∞, C=∞, D=∞ | Start from A               |
| B            | A=0, B=1, C=4, D=∞ | Update neighbors of A      |
| C            | A=0, B=1, C=3, D=∞ | Update neighbors of B      |
| D            | A=0, B=1, C=3, D=4 | Update neighbors of C      |
| All visited  | Final distances    | A→A=0, A→B=1, A→C=3, A→D=4 |

### **Shortest Path Result**

```
A to B = 1
A to C = 3
A to D = 4
```

---

## **Algorithm Complexity**

| Aspect                                | Complexity       |
| ------------------------------------- | ---------------- |
| Using adjacency matrix                | O(V^2)           |
| Using adjacency list + priority queue | O((V + E) log V) |

Where V = number of vertices, E = number of edges.

---

## **Use Cases**

* Network routing (finding shortest routes)
* GPS and navigation systems
* Telecommunications
* Game AI for pathfinding
* Logistics and supply chain optimization

---

## **Advantages**

* Efficient for graphs with non-negative weights
* Provides shortest paths from a single source to all nodes
* Can be extended to find actual paths, not just distances

---

## **Limitations**

* Does not handle negative weight edges
* Requires careful selection of data structures for efficiency
* Less efficient for extremely large dense graphs without priority queues

---

## **Conclusion**

Dijkstra’s algorithm is a fundamental tool for computing shortest paths in weighted graphs.
This project demonstrates how to calculate distances from a source node and helps in understanding graph traversal, priority queues, and path optimization techniques.

