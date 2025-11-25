# Coin Weighing Problem — README

## Introduction

The Coin Weighing Problem is a classic **algorithmic puzzle** that involves finding a counterfeit coin among a set of coins using a balance scale. The counterfeit coin may be **lighter or heavier** than the genuine ones, and the goal is to identify it with the **minimum number of weighings**.

---

## Purpose

This problem illustrates the application of **divide-and-conquer strategies** and **information theory** in problem-solving. It is widely used to teach:

* Logical reasoning
* Optimization techniques
* Efficient search strategies

---

## Problem Statement

Given:

* A set of `n` coins
* One coin is counterfeit (different weight)
* A balance scale for comparing groups of coins

Objective:

* Determine the counterfeit coin
* Decide whether it is lighter or heavier
* Use the **fewest possible weighings**

---

## Approach and Strategy

### Divide-and-Conquer Method

1. **Divide** the coins into groups
2. **Weigh** two groups against each other
3. **Analyze Result**:

* Left side heavier → counterfeit is in left or right depending on lighter/heavier assumption
* Right side heavier → similarly narrow down
* Balanced → counterfeit is in unweighed group

4. Repeat recursively until the counterfeit coin is found

---

## Mathematical Insight

* For `n` coins, the **minimum number of weighings (W)** can be estimated using:

```
3^W ≥ n
```

This is because each weighing can result in **three outcomes**: left heavier, right heavier, or balanced.

* Therefore:

```
W ≥ log3(n)
```

This gives the **information-theoretic lower bound** on weighings.

---

## Example

### Scenario

* Total coins: 12
* One counterfeit coin
* Balance scale available

### Step-by-Step Solution

1. Divide 12 coins into 3 groups of 4
2. Weigh group 1 vs group 2

   * If balanced → counterfeit in group 3
   * If unbalanced → counterfeit in heavier or lighter group
3. Divide suspected group into 3 smaller groups
4. Repeat until the counterfeit coin is isolated

This classic 12-coin problem requires **3 weighings** at most.

---

## Comparison Table: Weighings vs Coins

| Coins (n) | Minimum Weighings (W) |
| --------- | --------------------- |
| 3         | 1                     |
| 9         | 2                     |
| 12        | 3                     |
| 27        | 3                     |
| 81        | 4                     |

> Note: The number of weighings grows logarithmically with the number of coins.

---

## Applications

* Puzzle and logical reasoning exercises
* Teaching divide-and-conquer strategies
* Error detection in physical systems
* Information theory demonstrations

---

## Advantages of the Strategy

* Efficient and systematic
* Reduces the number of weighings from linear to logarithmic scale
* Can be generalized for multiple counterfeit coins

---

## Limitations

* Assumes only **one counterfeit coin**
* Requires a **perfect balance scale**
* Complexity increases with unknown counterfeit weight difference (lighter or heavier)

---

## Summary

The Coin Weighing Problem is a fascinating example of how **logical deduction and optimization** can solve a search problem efficiently. By applying the divide-and-conquer strategy and understanding the information-theoretic limits, the counterfeit coin can be found using the **minimum number of weighings**.

---

