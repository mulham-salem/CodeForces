# Problem 365A – Good Number

## Problem Description

You are given a list of numbers.  
Each number is written **without leading zeros**.

A number is called **Good** if:
- It contains **all digits from 0 to k at least once**.

Your task is to count how many numbers in the list are **Good numbers**.

---

## Rules

1. Read two integers:
   - `n` → number of values
   - `k` → the maximum required digit
2. For each of the `n` numbers:
   - Check whether **all digits from `0` to `k`** appear at least once.
3. Count how many numbers satisfy this condition.
4. Output the count.

---

## Important Clarifications

- Digits must be checked **individually**, not as a numeric range.
- The digits must appear **at least once**, order does not matter.
- Extra digits larger than `k` are allowed and do **not** affect validity.
- The number can be very large, so it should be treated as a **string**, not an integer.

---

## Examples

### Example 1

**Input**
```

3 1
1
10
101

```

**Analysis**

We need digits: **0 and 1**

| Number | Digits Present | Good? |
|------|---------------|-------|
| `1` | {1} | ❌ (missing 0) |
| `10` | {1, 0} | ✅ |
| `101` | {1, 0} | ✅ |

**Output**
```

2

```

---

### Example 2

**Input**
```

5 2
012
120
102
111
210

```

**Analysis**

Required digits: **0, 1, 2**

| Number | Digits Present | Good? |
|------|---------------|-------|
| `012` | {0,1,2} | ✅ |
| `120` | {1,2,0} | ✅ |
| `102` | {1,0,2} | ✅ |
| `111` | {1} | ❌ |
| `210` | {2,1,0} | ✅ |

**Output**
```

4

```

---

## Step-by-Step Logic

For each number:
1. Create a boolean array (or set) to track digits `0 → k`.
2. Traverse each character in the number:
   - Convert it to a digit.
   - If it is between `0` and `k`, mark it as found.
3. After processing the number:
   - Check if **all digits from 0 to k were found**.
4. If yes → count it as a Good number.

---

## Key Notes

- Treat numbers as **strings** to easily access digits.
- Digits larger than `k` should be ignored.
- Time complexity is efficient since each digit is checked once.
- This problem focuses on:
  - String traversal
  - Digit frequency tracking
  - Logical condition checking

This is a classic problem used to practice digit analysis and string handling.

