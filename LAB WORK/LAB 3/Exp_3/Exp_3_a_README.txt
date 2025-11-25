# **README – Infix to Postfix Conversion Using Stack**

## **Introduction**

This project demonstrates how to convert an **infix expression** (e.g., `A + B * C`) into a **postfix expression** (e.g., `A B C * +`) using **stack operations**.
The main purpose is to show how stacks help in handling operator precedence and associativity while parsing arithmetic expressions.

---

## **What is Infix and Postfix?**

### **Infix Expression**

* Operators appear **between operands**.
  Example: `A + B`

### **Postfix Expression (Reverse Polish Notation)**

* Operators appear **after operands**.
  Example: `A B +`

### **Why Postfix?**

* No parentheses are required.
* Easy for machines to evaluate using a simple stack-based algorithm.

---

## **How Conversion Works (Concept Overview)**

### **1. Use of Stack**

A stack is used to temporarily hold operators and parentheses while scanning the expression from left to right.

### **2. Rules for Conversion**

| Input Character          | Action                                                                                   |
| ------------------------ | ---------------------------------------------------------------------------------------- |
| Operand (A–Z, 0–9)       | Add directly to postfix output                                                           |
| `(`                      | Push to stack                                                                            |
| `)`                      | Pop until `(` is found                                                                   |
| Operator (+, -, *, /, ^) | Pop operators from stack **with higher or equal precedence**, then push current operator |

### **3. Operator Precedence**

| Operator | Precedence | Associativity |
| -------- | ---------- | ------------- |
| `^`      | Highest    | Right to Left |
| `*` `/`  | Medium     | Left to Right |
| `+` `-`  | Low        | Left to Right |

Stack helps compare precedence to decide whether to pop or push operators.

---

## **Step-by-Step Example**

Convert:

```
A + B * C
```

### **Steps**

| Step | Read | Action               | Stack | Postfix |
| ---- | ---- | -------------------- | ----- | ------- |
| 1    | A    | Operand → output     | –     | A       |
| 2    | +    | Push                 | +     | A       |
| 3    | B    | Operand → output     | +     | AB      |
| 4    | *    | Higher than + → push | + *   | AB      |
| 5    | C    | Operand → output     | + *   | ABC     |
| 6    | End  | Pop all              | –     | ABC*+   |

### **Final Result**

```
ABC*+
```

---

## **Algorithm Summary**

1. Scan expression left to right
2. If operand → add to output
3. If `(` → push to stack
4. If `)` → pop until `(`
5. If operator → pop higher/equal precedence operators, then push
6. After scanning → pop all remaining operators

This logical workflow will be implemented in the program using stack operations.

---

## **Use Cases**

* Expression evaluation systems
* Compilers and interpreters
* Calculator implementations
* Reverse Polish Notation (RPN) engines

---

## **Key Learning Objectives**

* Understanding stack-based parsing
* Handling operator precedence and associativity
* Converting infix expressions to postfix format
* Using data structures to manage expression evaluation logic

---

## **Limitations**

* Assumes valid input expressions
* Does not handle unary operators
* Requires careful handling of whitespace and edge cases

---

## **Conclusion**

This project provides a clear demonstration of using stack operations to convert infix expressions to postfix form. It helps build strong foundational knowledge in expression parsing, stack-based algorithms, and compiler-style processing.



