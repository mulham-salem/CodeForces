# Problem 385A – Bear and Raspberry

## Problem Summary

A bear can borrow a honey barrel for one day, paying `c` kg of raspberry as rent. On day `d`, he sells the borrowed barrel at price `x[d]`, then on day `d+1` he buys a new barrel at price `x[d+1]` and returns it to his friend along with the rent `c`.

The profit for choosing day `d` is:

```

profit = x[d] - x[d+1] - c

```

If the profit is negative, the bear simply doesn't execute the plan (he can choose to do nothing). The goal is to find the **maximum possible profit** over all valid days `d` (1 ≤ d < n), or `0` if no profitable plan exists.

**Constraints:** 2 ≤ n ≤ 100, 0 ≤ c ≤ 100, 0 ≤ x[i] ≤ 100.

---

## Approach

Since the plan can be executed at most once, we just check every consecutive pair of days `(i, i+1)`:

1. Compute the profit: `x[i] - x[i+1] - c`.
2. Keep track of the maximum profit seen.
3. Start the answer at `0`, so if all profits are negative, the output is `0` (bear does nothing).

---

## Example Walkthrough

**Example 1:**
```

n = 5, c = 1
x = [5, 10, 7, 3, 20]

```
Check each pair:
- d=1: 5 - 10 - 1 = -6
- d=2: 10 - 7 - 1 = 2
- d=3: 7 - 3 - 1 = **3** ✅
- d=4: 3 - 20 - 1 = -18

Maximum profit = **3**.

---

**Example 2:**
```

n = 6, c = 2
x = [100, 1, 10, 40, 10, 40]

```
- d=1: 100 - 1 - 2 = **97** ✅
- d=2: 1 - 10 - 2 = -11
- d=3: 10 - 40 - 2 = -32
- d=4: 40 - 10 - 2 = 28
- d=5: 10 - 40 - 2 = -32

Maximum profit = **97**.

---

**Example 3:**
```

n = 3, c = 0
x = [1, 2, 3]

```
- d=1: 1 - 2 - 0 = -1
- d=2: 2 - 3 - 0 = -1

No profitable plan → answer = **0**.

---

## Pseudocode

```

READ n, c
READ array x of size n

ans = 0

FOR i = 0 TO n-2:
	profit = x[i] - x[i+1] - c
	ans = MAX(ans, profit)

PRINT ans

```

---

## Complexity

- **Time Complexity:** `O(n)` — we iterate through the array once, checking each consecutive pair of days.
- **Space Complexity:** `O(n)` — to store the array of `n` prices (or `O(1)` extra space beyond the input array).