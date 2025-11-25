# **README – String Matching Using KMP and Rabin-Karp Algorithms**

## **Introduction**

This project demonstrates **string matching algorithms** using two classic approaches: **Knuth-Morris-Pratt (KMP)** and **Rabin-Karp Fingerprinting**.
Both algorithms are used to find occurrences of a **pattern string** within a **text string** efficiently, reducing unnecessary comparisons compared to naive methods.

---

## **Knuth-Morris-Pratt (KMP) Algorithm**

### **Overview**

KMP is a **linear-time string matching algorithm** that avoids redundant comparisons by pre-processing the pattern.

### **Key Concepts**

* **Prefix Table / LPS Array**: Stores the length of the longest prefix which is also a suffix for substrings of the pattern.
* **Efficient Backtracking**: When a mismatch occurs, the algorithm uses the LPS table to skip unnecessary comparisons in the text.

### **Steps**

1. Preprocess the pattern to create **LPS (Longest Prefix Suffix) array**.
2. Traverse the text and pattern:

   * If characters match, move forward in both text and pattern.
   * If mismatch, use LPS array to shift pattern appropriately without rechecking matched characters.
3. Report all occurrences of the pattern in the text.

### **Example**

```
Text: ABC ABCDAB ABCDABCDABDE
Pattern: ABCDAB
Matches at indices: 4, 11
```

### **Complexity**

| Aspect                    | Complexity |
| ------------------------- | ---------- |
| Preprocessing (LPS array) | O(m)       |
| Searching                 | O(n)       |
| Overall                   | O(n + m)   |

Where n = length of text, m = length of pattern.

---

## **Rabin-Karp Fingerprinting Algorithm**

### **Overview**

Rabin-Karp is a **probabilistic string matching algorithm** that uses **hashing** to find pattern matches efficiently.
It is particularly useful when searching for multiple patterns or large text.

### **Key Concepts**

* **Hash Function**: Converts pattern and text substrings into numerical fingerprints.
* **Sliding Window**: Text is scanned in windows of the same length as the pattern.
* **Match Verification**: If hash matches, characters are compared to verify true match (avoids false positives).

### **Steps**

1. Compute the **hash of the pattern**.
2. Slide a window of pattern length over the text:

   * Compute hash of current substring (using **rolling hash** for efficiency).
   * If hashes match, compare characters to confirm match.
3. Report all occurrences of the pattern.

### **Example**

```
Text: GEEKS FOR GEEKS
Pattern: GEEK
Matches at indices: 0, 10
```

### **Complexity**

| Aspect           | Complexity                        |
| ---------------- | --------------------------------- |
| Average case     | O(n + m)                          |
| Worst case       | O(n × m)                          |
| Hash computation | O(1) per character (rolling hash) |

Where n = length of text, m = length of pattern.

---

## **Use Cases**

* Text editors and word processors for search functionality
* Plagiarism detection
* DNA/protein sequence searching in bioinformatics
* Network packet inspection and data scanning
* Pattern recognition in large datasets

---

## **Advantages**

| Algorithm  | Advantage                                                                                 |
| ---------- | ----------------------------------------------------------------------------------------- |
| KMP        | Guarantees linear-time search, avoids redundant comparisons                               |
| Rabin-Karp | Efficient for multiple pattern searches, uses hashing to quickly detect potential matches |

---

## **Limitations**

| Algorithm  | Limitation                                                                                    |
| ---------- | --------------------------------------------------------------------------------------------- |
| KMP        | Preprocessing is needed; not suitable for complex pattern matching with wildcards             |
| Rabin-Karp | Hash collisions may require extra verification, worst-case complexity can degrade to O(n × m) |

---

## **Conclusion**

This project provides implementations of **Knuth-Morris-Pratt and Rabin-Karp algorithms** for efficient string matching.
KMP leverages pattern preprocessing to skip unnecessary comparisons, while Rabin-Karp uses hashing to quickly identify potential matches, making both algorithms suitable for different text processing scenarios.
