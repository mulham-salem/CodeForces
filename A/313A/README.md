# Problem 313A – Ilya and Bank Account

## Problem Summary

Ilya has a bank account balance `n` (can be negative). He is allowed **at most once** to delete either:
- the **last digit**, or
- the **digit before last**

from the balance. He may also choose to do nothing.

The goal is to find the **maximum** possible balance after using this option at most once.

**Constraints:** `10 ≤ |n| ≤ 10^9`

---

## Key Observations

- If `n` is **non-negative**, deleting any digit only makes the number smaller (or keeps it the same in edge cases). So the answer is `n` itself.
- If `n` is **negative**, deleting a digit makes the number *less negative* (i.e., larger). So we compare three candidates:
  1. `n` (do nothing)
  2. `n` with the **last digit removed**
  3. `n` with the **digit before last removed**

Since the number is stored as a string, we can construct these two modified strings easily.

---

### Example Walkthrough

| Input     | Do nothing | Remove last | Remove before last | Answer    |
|-----------|------------|-------------|--------------------|-----------|
| `2230`    | 2230       | 223         | 220                | **2230**  |
| `-10`     | -10        | -1          | -0 → 0             | **0**     |
| `-100003` | -100003    | -10000      | -10003             | **-10000**|

---

## Pseudocode

```

READ s as string

IF s[0] != '-':
	PRINT s
	RETURN

a = s without last character
b = s without second-to-last character

PRINT maximum of (s, a, b) as integers

```

---

## Complexity

- **Time Complexity:** `O(d)` where `d` is the number of digits in `n` (at most 10 digits). String slicing, conversion, and comparison all take linear time in the number of digits.
- **Space Complexity:** `O(d)` for storing the string and its modified copies.

---