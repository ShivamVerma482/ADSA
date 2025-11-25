# Knuth–Morris–Pratt (KMP) String Searching Algorithm — README

## Introduction

The Knuth–Morris–Pratt (KMP) algorithm is an efficient string searching method used to locate all occurrences of a **pattern** within a **text**. Unlike the naïve approach, which re-checks characters unnecessarily, KMP avoids redundant comparisons by preprocessing the pattern. This preprocessing builds a table that helps decide how far the pattern can safely shift after a mismatch.

---

## Why KMP?

The main problem with the naïve pattern matching method is the repeated comparison of characters that have already been checked. KMP solves this by ensuring:

* No backtracking in the text
* Every character of the text is scanned **at most once**
* The overall time complexity becomes **O(n + m)**, where

  * *n* = length of text
  * *m* = length of pattern

This makes KMP ideal for applications like search engines, DNA sequence matching, compiler design, and intrusion detection systems.

---

## Core Idea

The algorithm uses a preprocessing phase to compute the **LPS (Longest Prefix Suffix)** array. This array indicates, for any position in the pattern, the length of the longest prefix that is also a suffix.
During searching, this array helps shift the pattern without rechecking previously matched characters.

---

## The LPS Array

The LPS array captures how much you can “reuse” of the previous match after a mismatch.

Example pattern:

```
Pattern: A B A B A C
Index:   0 1 2 3 4 5
LPS:     0 0 1 2 3 0
```

Explanation:

* At index 4 (“A”), the longest prefix and suffix both match `"ABA"` → length 3
* At index 5 (“C”), no prefix-suffix match → 0

---

## How KMP Works

### Step 1: Preprocess the Pattern

* Build the LPS array
* Use prefix/suffix relationships to compute it in **O(m)** time

### Step 2: Scan the Text

* Start comparing characters from left to right
* When characters match, move forward
* On a mismatch:

  * Do **not** reset `i` (text index)
  * Use LPS to shift the pattern
  * Reuse previously matched characters efficiently
* Continue until the entire text has been scanned

---

## Advantages

| Advantage             | Explanation                              |
| --------------------- | ---------------------------------------- |
| Linear Time           | No character is compared more than once  |
| Efficient Shifting    | LPS allows skipping redundant checks     |
| No Backtracking       | Text index never moves backward          |
| Good for Large Inputs | Handles long texts and patterns smoothly |

---

## Applications

KMP is widely used in:

* Searching for substrings in large texts
* DNA and protein sequence analysis
* Plagiarism detection
* Search engines
* Text editors (find/replace)
* Pattern recognition
* Intrusion detection systems

---

## Example Walkthrough

**Text:** `ABABDABACDABABCABAB`
**Pattern:** `ABABCABAB`

During matching, once a mismatch occurs after partially matching `"ABABC"`, KMP avoids re-checking characters and uses LPS shifts to continue efficiently.

High-level representation:

```
Text:    ABABDABACDABABCABAB
Pattern: ABABCABAB
                 ↑ shift using LPS
```

The algorithm identifies matches by shifting the pattern based on computed LPS values, ensuring no wasted comparisons.

---

## Time & Space Complexity

| Phase               | Complexity           |
| ------------------- | -------------------- |
| Preprocessing (LPS) | O(m)                 |
| Searching           | O(n)                 |
| Total               | **O(n + m)**         |
| Extra Space         | O(m) (the LPS array) |

---

## Limitations

* Requires additional preprocessing step
* Slightly more complex logic compared to naïve search
* LPS computation must be correct for accurate results

---

## Visual Comparison (Naïve vs KMP)

### Naïve Method

* Re-checks characters
* May take O(nm)

### KMP Method

* Smart shifting using LPS
* Always O(n + m)

```
Naïve:   ABABABABABA (re-check many times)
KMP:     ABABABABABA (checks once, shifts smartly)
```

---

## Summary

The KMP Algorithm provides a fast and reliable solution for pattern matching by eliminating unnecessary comparisons. Its ability to use previous match information through the LPS array makes it one of the most powerful algorithms in string processing.

