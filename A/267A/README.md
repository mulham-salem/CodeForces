# Problem 267A – Subtractions

## Problem Statement

You are given two positive integers. While both numbers are greater than zero, you repeatedly perform the following operation: **subtract the smaller number from the larger number**. If the numbers are equal, subtract one from the other (resulting in one zero).

For each pair `(aᵢ, bᵢ)`, determine how many operations will be performed before one number becomes zero.

---

## Input Format

- The first line contains an integer `n` **(1 ≤ n ≤ 1000)** – the number of pairs.
- The next `n` lines each contain two integers `aᵢ` and `bᵢ` **(1 ≤ aᵢ, bᵢ ≤ 10⁹)**.

---

## Output Format

For each pair, print a single integer – the number of operations performed.

---

## Examples

### Example 1

**Input:**
```

2
4 17
7 987654321

```

**Output:**
```

8
141093479

```

### Explanation

For the pair `(4, 17)`:

```

(4, 17) → (4, 13) → (4, 9) → (4, 5) → (4, 1) → (3, 1) → (2, 1) → (1, 1) → (0, 1)

```

Total operations: **8**

For the pair `(7, 987654321)`, the result is **141093479** operations (using division to simulate repeated subtraction efficiently).

---

## Key Insight

Instead of simulating subtraction one step at a time (which would be too slow for large numbers), we can:

- If `a > b`, we can subtract `b` from `a` **multiple times at once**.
- The number of times is `a / b`, and the remainder becomes `a % b`.
- Add `a / b` to the operation counter and continue with the new values.

This approach is similar to the **Euclidean algorithm** and runs in **O(log min(a, b))** time per pair.

---

## Pseudocode

```
READ n
FOR each pair (a, b):
    operations = 0
    
    WHILE a > 0 AND b > 0:
        IF a >= b:
            operations = operations + (a / b)
            a = a % b
        ELSE:
            operations = operations + (b / a)
            b = b % a
    
    PRINT operations
```

---

## Complexity

- **Time Complexity:** O(log min(a, b)) per pair  
- **Space Complexity:** O(1) per pair

---

## Notes

- The algorithm is a direct optimization of repeated subtraction.
- Works efficiently even with numbers up to **10⁹**.
- The loop terminates when either number becomes zero.

---