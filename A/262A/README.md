# Problem 262A – Roma and Lucky Numbers

## Problem Summary

You are given `n` positive integers and an integer `k`.

A **lucky digit** is a digit equal to `4` or `7`.

For each number, count how many lucky digits it contains.  
If this count is **at most `k`**, the number is considered valid.

The task is to find how many numbers are valid.

---

## Input

- The first line contains two integers `n` and `k`:
  - `n` — the number of integers.
  - `k` — the maximum allowed number of lucky digits.
- The second line contains `n` positive integers.

---

### Constraints

- `1 ≤ n, k ≤ 100`
- `1 ≤ ai ≤ 10^9`

---

## Output

Print the number of integers that contain **at most `k` lucky digits**.

---

## Examples

### Example 1

**Input:**
```text
3 4
1 2 4
```

`1 → 0 lucky digits → valid`

`2 → 0 lucky digits → valid`

`4 → 1 lucky digit → valid`


**Output:**
```
3
```

---

### Example 2

**Input:**
```
3 2
447 44 77
```

`447 → 3 lucky digits → invalid`

`44 → 2 lucky digits → valid`

`77 → 2 lucky digits → valid`


**Output:**
```
2
```

---

## Pseudocode
```
Read n and k
answer = 0

Repeat n times:
    Read number
    luckyCount = 0

    While number has digits:
        digit = last digit of number

        If digit is 4 or 7:
            luckyCount++

        Remove the last digit

    If luckyCount <= k:
        answer++

Print answer
```

---

## Complexity

**Time:** `O(n × d)`, where `d` is the number of digits in each number.

**Space:** `O(1)`

---