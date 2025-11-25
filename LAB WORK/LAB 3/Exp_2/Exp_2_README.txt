# Binary Search Tree Operations

This document explains how Binary Search Tree operations are implemented using functions. The program performs creation, insertion, deletion, and traversal operations on a BST with integer values.

## Introduction

A Binary Search Tree (BST) is a hierarchical data structure in which each node contains a value, and every node satisfies the BST property:

* All values in the left subtree are smaller than the node’s value
* All values in the right subtree are greater than the node’s value

BSTs are widely used in searching, sorting, indexing, and efficient data retrieval due to their structured arrangement.

## Operations Supported

The program provides the following operations through functions:

### Creation

The BST is created dynamically by inserting nodes one by one. Each node contains:

* A data value
* A pointer to the left child
* A pointer to the right child

The first insertion creates the root node, and subsequent insertions place new nodes according to BST rules.

### Insertion

Insertion follows the BST property.
For each value:

* If it is smaller than the current node, it moves to the left subtree
* If it is larger, it moves to the right subtree
* The process continues until the correct empty position is found

Insertion maintains the sorted structure of the tree.

### Deletion

Deletion in a BST is more complex and is handled through three cases:

1. **Node with no children (leaf node)**
   The node is simply removed.

2. **Node with one child**
   The node is replaced by its child.

3. **Node with two children**
   The node is replaced by its inorder successor (smallest value in the right subtree).
   This ensures the BST property remains valid.

A deletion function processes these cases to maintain the tree structure correctly.

### Traversals

The tree can be traversed in three different orders:

#### Inorder Traversal

Left subtree → Node → Right subtree
This traversal prints values in ascending order.

#### Preorder Traversal

Node → Left subtree → Right subtree
Preorder is useful for creating a copy of the tree.

#### Postorder Traversal

Left subtree → Right subtree → Node
Commonly used for deleting or freeing nodes.

## Example of Traversal Output

For a BST containing the values:
`50, 30, 20, 40, 70, 60, 80`

The traversals produce:

| Traversal Type | Output Order         |
| -------------- | -------------------- |
| Inorder        | 20 30 40 50 60 70 80 |
| Preorder       | 50 30 20 40 70 60 80 |
| Postorder      | 20 40 30 60 80 70 50 |

## Use Cases

* Searching for values
* Maintaining sorted data
* Efficient insertion and deletion
* Memory-optimized dynamic structures
* Repeated lookups with average O(log n) performance

## Summary

The BST implementation demonstrates core operations including creation, insertion, deletion, and traversal. By structuring data in a hierarchical form and always keeping nodes in sorted order, BSTs provide efficient and organized access to dynamically changing datasets. The operations allow users to interact with the tree, modify it, and retrieve elements in various traversal formats.

---


