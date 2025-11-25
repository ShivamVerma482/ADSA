## AVL Tree Insert and Delete Operations

This document describes the concepts, operations, and behavior of an AVL Tree, along with details about insertion and deletion processes. It is intended to accompany a program that implements these operations using functions.

---

## Introduction

An AVL Tree is a self-balancing Binary Search Tree (BST).
It ensures that for every node, the height difference between its left and right subtrees (known as the balance factor) is no more than ±1.
This balancing property guarantees fast search, insertion, and deletion operations.

---

## Key Features of an AVL Tree

* Every node maintains a height value.
* The balance factor is calculated as:
  `balance factor = height(left subtree) − height(right subtree)`
* After every insertion or deletion, the tree may require rotations to maintain balance.
* AVL Trees provide **O(log n)** time complexity for search, insertion, and deletion.

---

## Operations in the AVL Tree

### 1. Creation

The tree is initially empty. Nodes are added dynamically using the insertion function.
Each new node has a key, height = 1, and left/right pointers set to NULL.

---

### 2. Insertion

Insertion follows Binary Search Tree (BST) rules:

1. Insert the node in its correct position.
2. Update the height of each ancestor node.
3. Compute the balance factor.
4. Apply rotations when imbalance occurs.

#### Types of Rotations

| Imbalance Type   | Condition                                 | Rotation Used                  |
| ---------------- | ----------------------------------------- | ------------------------------ |
| Left-Left (LL)   | Inserting in left subtree of left child   | Right Rotation                 |
| Right-Right (RR) | Inserting in right subtree of right child | Left Rotation                  |
| Left-Right (LR)  | Inserting in right subtree of left child  | Left Rotation + Right Rotation |
| Right-Left (RL)  | Inserting in left subtree of right child  | Right Rotation + Left Rotation |

#### Example of Insert Balancing

```
Insert: 30 → 20 → 10  
Imbalance: LL  
Apply: Right Rotation  
```

---

### 3. Deletion

Deletion is more complex because after removing a node, the tree may become unbalanced.

Steps:

1. Locate and remove the node (BST deletion).
2. If the node has:

   * **No child:** remove directly
   * **One child:** replace node with child
   * **Two children:** replace with inorder successor
3. Update heights of all ancestor nodes.
4. Recheck the balance factor.
5. Apply the appropriate rotation.

#### Rotation Cases After Deletion

| Case             | Condition                  | Rotation                       |
| ---------------- | -------------------------- | ------------------------------ |
| Left-Left (LL)   | Left subtree heavier       | Right Rotation                 |
| Left-Right (LR)  | Left subtree → right-heavy | Left Rotation + Right Rotation |
| Right-Right (RR) | Right subtree heavier      | Left Rotation                  |
| Right-Left (RL)  | Right subtree → left-heavy | Right Rotation + Left Rotation |

---

## Traversal Methods

Traversal is used to view the structure of the tree.

### Inorder Traversal

Visits nodes in sorted order:
**Left → Node → Right**

### Preorder Traversal

Useful for copying the tree:
**Node → Left → Right**

### Postorder Traversal

Used for deleting the tree:
**Left → Right → Node**

---

## Height and Balance Illustration

### Height Calculation

```
 height(node) = 1 + max(height(left child), height(right child))
```

### Balance Factor Visual

```
 BF = -2 or +2 → Unbalanced  
 BF = -1, 0, +1 → Balanced  
```

---

## Example AVL Tree Growth

### Insert Sequence

```
Insert: 10, 20, 30, 40, 50, 25
```

### Balancing Summary Table

| Inserted Key | Imbalance? | Rotation            |
| ------------ | ---------- | ------------------- |
| 10           | No         | –                   |
| 20           | No         | –                   |
| 30           | Yes        | Left Rotation       |
| 40           | No         | –                   |
| 50           | Yes        | Left Rotation       |
| 25           | Yes        | Right-Left Rotation |

---

## Advantages of AVL Trees

* Faster lookups compared to simple BSTs.
* Maintains strict height balance.
* Guarantees consistent performance.

---

## Conclusion

An AVL Tree is an efficient self-balancing data structure that maintains optimal height after every insertion or deletion. The operations rely heavily on balance factor calculations and rotations to ensure performance remains logarithmic. This README explains the concepts required to understand and implement the insert and delete functions of an AVL Tree program.

