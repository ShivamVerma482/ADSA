# **README – Evaluating Postfix Expression Using Stack**

## **Introduction**

This document explains how a postfix expression (also known as Reverse Polish Notation) is evaluated using stack operations.
The goal of this program is to demonstrate how operands and operators can be processed efficiently without needing parentheses or precedence rules.

---

## **What Is a Postfix Expression?**

A postfix expression places the operator **after** its operands.

### **Examples**

* Infix: `A + B` → Postfix: `A B +`
* Infix: `(A + B) * C` → Postfix: `A B + C *`

Postfix expressions are easier to evaluate using a stack because the order of operations is naturally encoded.

---

## **Why Evaluate Postfix Using a Stack?**

A stack makes it simple to:

* Push operands as they appear
* Apply operators immediately when encountered
* Maintain correct computation order
* Avoid precedence and parentheses completely

---

## **How the Evaluation Works**

### **General Rules**

| Input Type               | Action Taken                                                     |
| ------------------------ | ---------------------------------------------------------------- |
| Operand (number)         | Push onto the stack                                              |
| Operator (+, -, *, /, ^) | Pop the top two values, apply the operator, push the result back |

---

## **Step-by-Step Workflow**

1. Scan the postfix expression from **left to right**.
2. When an operand is found → push it onto the stack.
3. When an operator is found:

   * Pop the top two operands
   * Apply the operator (`operand2 operator operand1`)
   * Push the computed result back onto the stack
4. After scanning all characters → the top of the stack holds the final answer.

---

## **Example Evaluation**

### **Expression**

```
5 3 8 * + 2 -
```

### **Step Table**

| Step | Read | Action                      | Stack Content |
| ---- | ---- | --------------------------- | ------------- |
| 1    | 5    | Push operand                | 5             |
| 2    | 3    | Push operand                | 5, 3          |
| 3    | 8    | Push operand                | 5, 3, 8       |
| 4    | *    | Pop 3 & 8 → 3*8=24 → push   | 5, 24         |
| 5    | +    | Pop 5 & 24 → 5+24=29 → push | 29            |
| 6    | 2    | Push operand                | 29, 2         |
| 7    | -    | Pop 29 & 2 → 29-2=27 → push | 27            |

### **Final Result**

```
27
```

---

## **Operator Handling**

### **Supported Operators**

| Operator | Use            |
| -------- | -------------- |
| `+`      | Addition       |
| `-`      | Subtraction    |
| `*`      | Multiplication |
| `/`      | Division       |
| `^`      | Exponentiation |

### **Important Notes**

* Evaluation order matters:
  `operand2 operator operand1`
  Example: For `5 2 -`, compute `5 - 2`, not `2 - 5`.

---

## **Algorithm Summary**

1. Initialize an empty stack
2. For each symbol in the postfix expression:

   * If operand → push
   * If operator → pop two values, compute, push result
3. End of expression → the stack top is the final answer

---

## **Common Use Cases**

* Building calculator programs
* Expression evaluation in compilers
* Mathematical parsing engines
* Reverse Polish Notation interpreters

---

## **Key Learning Objectives**

* Understanding stack operations
* Applying operator logic on popped elements
* Managing numeric evaluation safely
* Building logical flow for expression computing

---

## **Limitations**

* Assumes valid postfix input
* Division by zero must be handled separately
* Requires consistent spacing or digit-handling logic

---

## **Conclusion**

Postfix evaluation using a stack is one of the simplest and most powerful parsing techniques.
This README explains how the stack-based algorithm works and prepares you to implement a clean, efficient postfix evaluator for numerical expressions.

