# Problem 274A – k-Multiple Free Set

## Problem Statement

Given a set of `n` distinct positive integers, find the size of its largest subset where **no two numbers** satisfy the condition that one is equal to the other multiplied by `k`.

In other words, there should be **no pair** `(x, y)` such that:
- `x < y`
- `y = x * k`

---

## Key Insight

If we sort the array in **ascending order**, we can make a greedy decision for each number:

- For any number `x`:
  - If `x` is **not divisible** by `k`, it can never form a forbidden pair with a smaller number. → **Take it.**
  - If `x` is divisible by `k`, check if `x / k` has already been taken:
    - If **not taken** → take `x`.
    - If **already taken** → skip `x` (because `(x/k, x)` would form a forbidden pair).

This works because we process numbers from **smallest to largest**, ensuring that when we encounter the larger element of a potential pair, we already know whether the smaller one was chosen.

---

## Example

**Input:**
```

6 2
2 3 6 5 4 10

```

**Sorted Array:** `[2, 3, 4, 5, 6, 10]`

| Number | Divisible by 2? | x/k | Is x/k chosen? | Action |
|--------|----------------|-----|----------------|--------|
| 2      | Yes            | 1   | No             | Take ✅ |
| 3      | No             | -   | -              | Take ✅ |
| 4      | Yes            | 2   | Yes            | Skip ❌ |
| 5      | No             | -   | -              | Take ✅ |
| 6      | Yes            | 3   | Yes            | Skip ❌ |
| 10     | Yes            | 5   | Yes            | Skip ❌ |

**Result:** `{2, 3, 5}` → Size = **3**

> **Note:** The answer is the **size** of the subset, not the subset itself. Multiple optimal subsets may exist.

---

## Complexity Analysis

- **Sorting:** `O(n log n)`
- **Single pass with hash set lookups:** `O(n)`
- **Total:** `O(n log n)`
- **Space:** `O(n)` for the hash set

---

## Pseudocode

```

1. Read n, k
2. Read array a of size n
3. Sort a in ascending order
4. Initialize empty hash set chosen
5. Initialize answer = 0
6. For each x in a:
   if x % k != 0:
   add x to chosen
   answer++
   else:
   if (x / k) is NOT in chosen:
   add x to chosen
   answer++
   // else: skip x
7. Print answer

```

---

## Key Takeaway

The greedy strategy works because:
- We always prefer the **smaller** element of each potential `(x, x*k)` pair.
- Processing in ascending order guarantees that when we see `x*k`, we already know whether `x` was chosen.

This ensures we never include both elements of a forbidden pair, while maximizing the total count.

---