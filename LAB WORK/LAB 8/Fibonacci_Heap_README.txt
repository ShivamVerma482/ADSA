# Fibonacci Heap

## Introduction

A Fibonacci Heap is an advanced data structure used primarily to achieve improved asymptotic time complexity for priority queue operations. It supports very fast amortized running times and is widely used in graph algorithms such as Dijkstra’s shortest path and Prim’s minimum spanning tree algorithms.
Its structure is built on a collection of heap-ordered trees that are linked together using a circular doubly linked list.

---

## Core Concepts

A Fibonacci Heap is made up of a set of **min-heap–ordered trees**.
Key features include:

* Flexible tree structure
* Lazy consolidation strategy
* Efficient decrease-key operation
* Support for merging heaps in constant time

Each node stores:

* Key value
* Degree (number of children)
* Parent pointer
* Child pointer
* Mark bit (to support cascading cuts)

---

## Operations and Their Complexity

| Operation     | Amortized Time | Description                                      |
| ------------- | -------------- | ------------------------------------------------ |
| Insert        | O(1)           | Adds a new node to the root list                 |
| Find Min      | O(1)           | Returns pointer to minimum element               |
| Union (Merge) | O(1)           | Concatenates two root lists                      |
| Extract Min   | O(log n)       | Removes minimum node and consolidates trees      |
| Decrease Key  | O(1)           | Cuts node from its parent if heap order violated |
| Delete        | O(log n)       | Decreases key to −∞ and extracts min             |

These amortized bounds make Fibonacci Heaps particularly efficient in repetitive decrease-key operations.

---

## Structure Overview

### Root List

All trees in the heap exist in a circular doubly linked structure.
Each tree follows min-heap ordering.

### Min Pointer

A direct pointer to the minimum node ensures constant-time retrieval of the smallest element.

### Children Lists

Children of a node form their own circular linked list. Nodes can be added or removed efficiently.

### Mark Bit

Indicates whether a child has been cut before.
Used in cascading cuts to maintain amortized efficiency.

---

## Visual Structure (Text Diagram)

```
Root List:
  [3] — [7] — [10] — [18] — (back to [3])

Each node may have children:

      [3]
     /   \
   [8]   [15]
         /  \
       [20] [22]

All lists are circular doubly linked.
```

---

## Key Algorithmic Ideas

### 1. Lazy Consolidation

During operations like insert or merge, the heap does not immediately restructure.
Instead, structural optimization is postponed until **extract-min**, improving amortized performance.

### 2. Cascading Cut

Triggered during decrease-key when a node’s key becomes smaller than its parent.

Steps:

* Cut the node from its parent
* Add it to the root list
* If the parent was already marked → recursively cut it too

This mechanism maintains a low tree degree, ensuring logarithmic consolidation cost.

---

## Extract-Min (Core Operation)

This is the most important and expensive operation in Fibonacci heaps.

### Steps:

1. Remove the minimum node from the root list.
2. Add all of its children to the root list.
3. Consolidate the root list by:

   * Pairwise linking trees of the same degree
   * Ensuring no two trees in the root list share the same degree

### Consolidation Table Sketch

| Degree | Trees Present | Operation                           |
| ------ | ------------- | ----------------------------------- |
| 0      | T₀, T₀        | Link one to another → degree 1 tree |
| 1      | —             | No action                           |
| 2      | T₂, T₂        | Link → degree 3 tree                |
| …      | …             | …                                   |

The linking process ensures the heap's efficiency and maintains a forest of trees with unique degrees up to O(log n).

---

## Decrease-Key

### Purpose

Used to reduce the value of a key in the heap and possibly restructure the heap if heap-order is violated.

### Steps

1. Reduce the key of the target node.
2. If the new key is still ≥ parent key, no action is needed.
3. Otherwise:

   * Cut the node
   * Move it to the root list
   * Perform cascading cuts if necessary

This leads to extremely efficient graph algorithms where decrease-key dominates runtime.

---

## Applications

### Graph Algorithms

Fibonacci Heaps provide theoretical improvements to:

* Prim’s Minimum Spanning Tree:

  * Reduces time to **O(E + V log V)**
* Dijkstra’s Shortest Path:

  * Achieves **O(E + V log V)**

### Other Uses

* Network routing
* Scheduling
* Data compression tools
* Priority-based simulation systems

---

## Advantages

* Extremely fast amortized operations
* Efficient merging of heaps
* Optimal for algorithms needing frequent decrease-key calls
* Strong theoretical guarantees

---

## Limitations

* High constant factors in real-world implementation
* More complex structure than binary or binomial heaps
* Less commonly used in practice for general-purpose applications
* Memory overhead due to storing multiple pointers and marks

---

## Summary

Fibonacci Heaps represent a sophisticated priority queue structure optimized for amortized performance. Their most powerful feature is the efficient decrease-key operation, making them ideal for algorithmic workloads dominated by key updates. Although rarely used in real-world libraries due to complexity, they remain an essential concept in the study of advanced data structures and algorithm design.

---

