# Problem 192A – Funky Numbers

## Problem Summary

A **triangular number** is a number defined by the following formula:

```text
T(k) = k × (k + 1) / 2
```

where **k** is a positive integer.

Given an integer **n**, determine whether it can be represented as the sum of **two triangular numbers** (they may be the same).

Print **"YES"** if such a representation exists; otherwise, print **"NO"**.

---

## Examples

### Example 1

**Input**
```text
256
```

**Output**
```text
YES
```

**Explanation**

```text
256 = 120 + 136
```

Both **120** and **136** are triangular numbers.

---

### Example 2

**Input**
```text
512
```

**Output**
```text
NO
```

**Explanation**

There is no pair of triangular numbers whose sum equals **512**.

---

## Algorithm

1. Generate all triangular numbers less than or equal to **n**.
2. Store them in an array.
3. Use two pointers:
   - One starts from the beginning.
   - The other starts from the end.
4. Compare the sum of the two numbers:
   - If the sum equals **n**, print **YES**.
   - If the sum is smaller than **n**, move the left pointer forward.
   - If the sum is larger than **n**, move the right pointer backward.
5. If no valid pair is found, print **NO**.

---

## Pseudocode

```text
Read n

Generate all triangular numbers <= n
Store them in an array

left = 0
right = last index of the array

While left <= right
    sum = triangular[left] + triangular[right]

    If sum == n
        Print "YES"
        Stop

    Else if sum < n
        left++

    Else
        right--

Print "NO"
```

---

## Complexity Analysis

- **Time Complexity:** `O(√n)`
- **Space Complexity:** `O(√n)`

---