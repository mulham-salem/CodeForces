# Problem 285A – Slightly Decreasing Permutations

## Problem Statement

A permutation of length `n` is an ordered set of `n` distinct integers from `1` to `n`.

The **decreasing coefficient** of a permutation is the number of positions `i` where `p[i] > p[i+1]`.

Given `n` and `k`, output any permutation of length `n` whose decreasing coefficient equals `k`.

### Input
- Two integers `n` and `k` where `1 ≤ n ≤ 10^5` and `0 ≤ k < n`.

### Output
- Any valid permutation of length `n` with decreasing coefficient exactly `k`.

---

## Examples

**Example 1**
```

Input:  5 2
Output: 1 5 2 4 3

```
Explanation: `5 > 2` (1 drop) and `4 > 3` (1 drop) → total = 2.

**Example 2**
```

Input:  3 0
Output: 1 2 3

```
Explanation: No drops → decreasing coefficient = 0.

**Example 3**
```

Input:  3 2
Output: 3 2 1

```
Explanation: `3 > 2` and `2 > 1` → total = 2.

---

## Idea / Approach

1. Start with the sorted permutation `1 2 3 ... n` (decreasing coefficient = 0).
2. Reversing the last `k + 1` elements creates exactly `k` descents among them, while keeping the earlier part increasing.
3. Result: exactly `k` positions where `p[i] > p[i+1]`.

**Why it works:**
- The first `n - k - 1` elements are increasing → no descents there.
- The last `k + 1` elements are in strictly decreasing order → exactly `k` descents.
- Total = `k`.

---

## Pseudocode

```

read n, k
create array p of size n
for i from 0 to n-1:
p[i] = i + 1

reverse(p from index (n - k - 1) to (n - 1))

print p

```

---

## Complexity

- **Time:** `O(n)`
- **Space:** `O(n)`

---