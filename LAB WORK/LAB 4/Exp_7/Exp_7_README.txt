# **README – Text File Encoding Using Huffman Coding**

## **Introduction**

This project demonstrates how to **encode data from a text file using Huffman coding**, a popular **lossless data compression** technique.
Huffman coding reduces the size of data by assigning **shorter codes to more frequent characters** and longer codes to less frequent ones, achieving efficient compression.

---

## **What Is Huffman Coding?**

Huffman coding is a **variable-length prefix coding algorithm** that builds an optimal binary tree based on character frequencies.

### **Key Properties**

* **Lossless Compression**: Original data can be perfectly reconstructed.
* **Prefix Code**: No code is a prefix of another, avoiding ambiguity during decoding.
* **Frequency-Based**: More frequent characters get shorter codes.

---

## **How Huffman Coding Works**

### **Steps**

1. **Count frequency** of each character in the text file.
2. **Build a priority queue** (min-heap) of nodes, each representing a character and its frequency.
3. **Construct Huffman Tree**:

   * Remove two nodes with lowest frequencies
   * Create a new internal node with these two as children, frequency = sum of children
   * Insert the new node back into the queue
   * Repeat until only one node remains → root of the Huffman tree
4. **Assign codes** by traversing the tree:

   * Left edge = `0`, Right edge = `1`
   * Generate binary code for each character
5. **Encode text file** using the generated Huffman codes.

---

## **Example**

### **Text Input**

```
ABRACADABRA
```

### **Character Frequencies**

| Character | Frequency |
| --------- | --------- |
| A         | 5         |
| B         | 2         |
| R         | 2         |
| C         | 1         |
| D         | 1         |

### **Huffman Codes (Example)**

| Character | Code |
| --------- | ---- |
| A         | 0    |
| B         | 101  |
| R         | 100  |
| C         | 1110 |
| D         | 1111 |

### **Encoded Output**

```
0 101 100 0 1110 0 1111 0 101 100 0
```

---

## **Algorithm Complexity**

| Aspect                   | Complexity                                   |
| ------------------------ | -------------------------------------------- |
| Building frequency table | O(n) (n = number of characters)              |
| Building Huffman Tree    | O(d log d) (d = number of unique characters) |
| Encoding text            | O(n)                                         |
| Overall                  | O(n + d log d)                               |

---

## **Use Cases**

* Text compression for storage efficiency
* File transfer over networks
* Image and multimedia compression (as part of formats like JPEG)
* Any application requiring **lossless data compression**

---

## **Advantages**

* Guarantees **optimal compression** for a given set of character frequencies
* Simple tree-based structure for encoding and decoding
* Works for **any data containing symbols with varying frequencies**

---

## **Limitations**

* Requires frequency analysis upfront
* Tree must be stored or transmitted alongside encoded data for decoding
* Not as efficient for **small files with uniform character distribution**

---

## **Conclusion**

This project demonstrates how **Huffman coding** can be used to encode data in a text file efficiently.
It highlights frequency analysis, tree construction, code assignment, and results in reduced file size without any loss of information.
