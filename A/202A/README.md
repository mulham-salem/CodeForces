# Problem 202A – LLPS (Lexicographically Largest Palindromic Subsequence)

## 📖 Problem Summary

Given a string `s` of lowercase English letters, find the **lexicographically largest palindromic subsequence**.

A **subsequence** is formed by deleting zero or more characters without changing the order of the remaining characters.

A **palindrome** is a string that reads the same forwards and backwards.

---

## 💡 Key Observation

The lexicographically largest palindrome is obtained by:

- Finding the **largest character** in the string.
- Taking **all occurrences** of that character.

Since all selected characters are identical, the resulting subsequence is always a palindrome and is also lexicographically maximal.

---

## 📝 Examples

### Example 1

**Input**

```text
radar
```

**Output**

```text
rr
```

---

### Example 2

**Input**

```text
bowwowwow
```

**Output**

```text
wwwww
```

---

### Example 3

**Input**

```text
codeforces
```

**Output**

```text
s
```

---

## 🧠 Pseudocode

```text
Read string s

Find the largest character in s
Store it in mx

For each character c in s
    If c equals mx
        Output c
```

---

## ⏱️ Complexity Analysis

| Operation | Complexity |
|-----------|------------|
| Find maximum character | **O(n)** |
| Print all occurrences | **O(n)** |
| **Total** | **O(n)** |
| **Memory** | **O(1)** |

---