# **README – Longest Common Subsequence and All Common Subsequences Between Two Strings**

## **Introduction**

This project demonstrates how to find the **Longest Common Subsequence (LCS)** and **all common subsequences** between a pair of strings using dynamic programming techniques.
The LCS problem is a classic application in computer science, used in text comparison, bioinformatics, version control, and pattern recognition.

---

## **What Is a Longest Common Subsequence (LCS)?**

* A **subsequence** is a sequence that appears in the same order but not necessarily contiguously in both strings.
* The **Longest Common Subsequence** is the longest sequence that exists in both strings.

### **Example**

```
String 1: ABCDGH
String 2: AEDFHR
LCS: ADH
```

---

## **Why LCS Is Important**

* Comparing **similarity between texts**
* File and version comparison (e.g., git diff)
* DNA or protein sequence alignment in bioinformatics
* Pattern matching and data analysis

---

## **Algorithm Overview**

### **Dynamic Programming Approach**

1. Initialize a **2D matrix** `dp` of size `(m+1) x (n+1)` where `m` and `n` are lengths of the two strings.
2. Fill the matrix using the rule:

   * If `string1[i-1] == string2[j-1]`:

     ```
     dp[i][j] = dp[i-1][j-1] + 1
     ```
   * Else:

     ```
     dp[i][j] = max(dp[i-1][j], dp[i][j-1])
     ```
3. **The value at dp[m][n]** gives the length of LCS.
4. Trace back through the matrix to **construct one LCS**.
5. To find **all common subsequences**, explore all possible paths in the DP matrix that lead to the LCS length.

---

## **Example**

### **Strings**

```
String 1: ABC
String 2: AC
```

### **DP Matrix**

|   |   | A | C |
| - | - | - | - |
|   | 0 | 0 | 0 |
| A | 0 | 1 | 1 |
| B | 0 | 1 | 1 |
| C | 0 | 1 | 2 |

### **Result**

* **LCS Length:** 2
* **One LCS:** AC
* **All Common Subsequences:** A, C, AC

---

## **Algorithm Complexity**

| Aspect                   | Complexity                                              |
| ------------------------ | ------------------------------------------------------- |
| DP matrix filling        | O(m × n)                                                |
| Constructing LCS         | O(m + n)                                                |
| Finding all subsequences | Exponential in LCS length (O(2^k) where k = LCS length) |

---

## **Use Cases**

* Text comparison and diff tools
* Bioinformatics (DNA, RNA, protein alignment)
* Code version control systems
* Plagiarism detection
* Pattern recognition and data mining

---

## **Advantages**

* Provides **exact similarity measure** between strings
* Can generate **all common subsequences**, not just the longest
* Useful in various fields requiring sequence analysis

---

## **Limitations**

* Memory-intensive for very long strings (DP matrix size = m × n)
* Finding all common subsequences can be **exponentially complex**
* Not suitable for extremely large sequences without optimization

---

## **Conclusion**

This project illustrates how to compute the **Longest Common Subsequence and all common subsequences** between two strings.
Dynamic programming allows efficient calculation of LCS length and reconstruction of sequences, making it a powerful tool for sequence comparison and analysis.
