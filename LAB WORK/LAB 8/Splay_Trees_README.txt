# Splay Trees — README

## Introduction

Splay Trees are a type of self-adjusting binary search tree (BST) that move frequently accessed elements closer to the root. This behavior helps achieve amortized logarithmic time for common operations such as search, insert, and delete. Instead of maintaining strict balancing (like AVL or Red-Black Trees), Splay Trees rely on repeated tree rotations called *splaying*.

---

## Key Idea

The central idea is **splaying**: whenever an element is accessed (search/insert/delete), the tree performs a series of rotations to bring that element to the root.
This ensures:

* Frequently accessed nodes stay near the top
* Less frequently accessed nodes move deeper
* Tree remains “balanced enough” without maintaining strict height limits

---

## Properties of a Splay Tree

* **Binary Search Tree (BST) Property** holds
* Operations have **amortized O(log n)** time
* Worst-case time for a single operation can be O(n), but this is rare
* No explicit balance factors or color properties
* Efficient for workloads where certain keys are accessed repeatedly

---

## When Splay Trees Are Useful

Splay Trees are advantageous when:

* The access pattern is skewed
* Recently accessed items are likely to be accessed again
* Memory and structural overhead of AVL/Red-Black Trees is not desired

Common applications include caches, memory allocators, and network routing tables.

---

## Splaying Operations

A splaying operation consists of rotations that move a node `x` to the root.
There are three cases:

### 1. Zig (Single Rotation)

Occurs when the node is a child of the root.

```
    Root           X
     \     or     /
      X         Root
```

### 2. Zig-Zig (Double Rotation)

Node and its parent are both left or both right children.

```
      G               X
     /               |
    P                P
   /        or        \
  X                    G
```

### 3. Zig-Zag (Double Rotation)

Node and its parent are on opposite sides.

```
    G                X
     \              /
      P            G
     /      or      \
    X                P
```

These steps are repeated until the accessed node becomes the root.

---

## Core Operations

### Search

* Standard BST search
* Whether found or not, splay the last accessed node
* Improves locality for future operations

### Insert

* Insert like a normal BST
* Splay the newly inserted node to the root

### Delete

* Splay the node to be deleted
* Remove it
* Merge the remaining left and right subtrees
* Often done by:

  * Find max in left subtree
  * Splay it
  * Attach right subtree

### Find Min / Find Max

* Traverse left (min) or right (max)
* Splay the accessed node to root

---

## Complexity Summary

| Operation | Amortized Time | Worst Case |
| --------- | -------------- | ---------- |
| Search    | O(log n)       | O(n)       |
| Insert    | O(log n)       | O(n)       |
| Delete    | O(log n)       | O(n)       |
| Splaying  | O(log n)       | O(n)       |

Even though some individual operations may degrade to O(n), the amortized cost guarantees efficiency over sequences of operations.

---

## Advantages of Splay Trees

* Very simple to implement
* Strong amortized performance
* Adapt to actual use patterns
* No additional memory overhead (no colors, balance factors)
* Automatically keeps frequently used nodes near the root

---

## Limitations

* Worst-case performance for a single operation can be high
* Not strictly height balanced
* Might be slower for uniformly random access patterns compared to AVL/Red-Black Trees

---

## Example Diagram (Splaying Process)

```
Before Splay: (searching 15)

        20
       /
     10
       \
        15

After Zig-Zag:

        15
       /  \
     10    20
```

This shows how the target node is moved toward the root.

---

## Use Cases

* Implementing caches (LRU-style behavior emerges naturally)
* Memory allocation management
* Network routers maintaining frequently accessed routes
* String searching algorithms

---

## Summary

Splay Trees offer a unique tradeoff: they do not enforce strict balancing but still maintain excellent amortized performance by aggressively moving accessed nodes to the root. They are ideal for situations where access patterns are non-uniform and locality is high.

---

