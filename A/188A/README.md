# Problem 188A – Hexagonal Numbers

## Problem Description

A hexagonal number is a number that can be calculated using the formula:

`Hn = 2 * n^2 - n`

You are given an integer `n`, and your task is to calculate the `n`-th hexagonal number.

---

## Input

The input contains a single integer:

- `n` — the position of the hexagonal number to calculate.
- Constraints: `1 ≤ n ≤ 100`

---

## Output

Print the `n`-th hexagonal number.

---

## Examples

### Example 1

**Input**
```
3
```
**Calculation**

`H3 = 2 * 3^2 - 3 = 2 * 9 - 3 = 15`

**Output**
```
15
```
---

### Example 2

**Input**
```
6
```
**Calculation**

`H6 = 2 * 6^2 - 6 = 2 * 36 - 6 = 66`

**Output**
```
66
```
---

## Solution Idea

The formula directly gives the answer:

`Hn = 2 * n^2 - n`

So we only need to:

1. Read the value of `n`.
2. Apply the formula.
3. Print the result.

No loops or complex algorithms are required.

---

## Algorithm

1. Read `n`.
2. Compute `2 * n * n - n`.
3. Output the result.

---

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Memory Complexity:** `O(1)`

---