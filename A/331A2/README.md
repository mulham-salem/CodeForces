# Problem 331A2 – Oh Sweet Beaverette

## Problem Summary

You are given a sequence of `n` integers representing the esthetic appeal of trees. You must choose a contiguous subarray (keep some trees, cut the rest) such that:

1. The **sum of kept trees** is **maximized**.
2. The **first and last kept trees** have the **same value**.
3. At least **two trees** remain.

Trees that are **not** part of the chosen subarray are cut down. Additionally, any **negative-value tree strictly inside** the chosen subarray should also be cut (since it only reduces the sum).

> **Note:** The first and last trees of the subarray are always kept, even if their value is negative.

Output the maximum sum, the number of cut trees, and their indices (1-based).

---

## Key Idea

For each pair of indices `(i, j)` with `i < j` and `a[i] == a[j]`, the sum is:

```

sum = a[i] + a[j] + (sum of all positive elements strictly between i and j)

```

We want to maximize this over all valid pairs.

### Optimization

Naively checking all pairs is `O(n²)` — too slow for `n ≤ 3·10⁵`.

Instead:

- Precompute prefix sums of **positive values only**:
```

pref[k] = sum of max(0, a[t]) for t < k

```
- For a fixed right endpoint `j`, the sum becomes:
```

sum = 2 * a[j] + pref[j] - pref[i+1]

```
- To maximize for a given `a[j]`, we want the **smallest** `pref[i+1]` among all previous indices `i` with the same value.

So we maintain a hash map:
```

best[value] = { minimum pref[i+1], index i }

```

For each `j`:
- If `a[j]` was seen before, compute candidate sum.
- Update the global best.
- Then update `best[a[j]]` with `pref[j+1]` if it's smaller.

This gives **O(n)** time.

---

## Example 1

**Input:**
```

5
1 2 3 1 2

```

**Pairs with equal values:**
- `(1, 4)` → values `1` and `1` → sum = `1 + 1 + (2+3) = 7`
- `(2, 5)` → values `2` and `2` → sum = `2 + 2 + (3+1) = 8` ✅

**Best:** keep trees `2..5` → sum = `8`, cut tree `1`.

**Output:**
```

8 1
1

```

---

## Example 2

**Input:**
```

5
1 -2 3 1 -2

```

**Pairs with equal values:**
- `(1, 4)` → `1 + 1 + 3 = 5` ✅
- `(2, 5)` → `-2 + -2 + (3+1) = 0`

**Best:** keep trees `1..4`, but tree `2` is negative inside → cut it. Also cut tree `5` (outside).

**Output:**
```

5 2
2 5

```

---

## Algorithm Steps

1. Read `n` and array `a`.
2. Build `pref` where `pref[k] = sum of max(0, a[i]) for i < k`.
3. Use a hash map `best[value] = { minPref, index }`.
4. Iterate `j` from `0` to `n-1`:
   - If `a[j]` in map, compute:
     ```
     sum = 2 * a[j] + pref[j] - best[a[j]].minPref
     ```
   - Update global best if larger.
   - Update map entry for `a[j]` with `pref[j+1]` if smaller.
5. Collect cut trees:
   - Outside `[left, right]`
   - Inside but negative
6. Print sum, count, and indices.

---

## Complexity

| Step | Time | Space |
|------|------|-------|
| Prefix sums | O(n) | O(n) |
| Hash map scan | O(n) | O(n) |
| Collect cuts | O(n) | O(n) |
| **Total** | **O(n)** | **O(n)** |

---

## Pseudocode

```

READ n
READ array a[0..n-1]

pref[0] = 0
FOR i FROM 0 TO n-1:
	pref[i+1] = pref[i] + MAX(0, a[i])

bestSum = -INFINITY
left = 0
right = 1

best = empty hash map   // value -> (minPref, index)

FOR j FROM 0 TO n-1:
	IF a[j] EXISTS IN best:
		(minPref, idx) = best[a[j]]
		sum = 2 * a[j] + pref[j] - minPref
	IF sum > bestSum:
		bestSum = sum
		left = idx
		right = j

	currentPref = pref[j+1]
	IF a[j] NOT IN best OR currentPref < best[a[j]].minPref:
		best[a[j]] = (currentPref, j)
	
cut = empty list

FOR k FROM 0 TO n-1:
	IF k < left OR k > right:
		cut.APPEND(k+1)
	ELSE IF k > left AND k < right AND a[k] < 0:
		cut.APPEND(k+1)

PRINT bestSum, LENGTH(cut)
PRINT cut elements separated by space

```

---

## Notes

- The hash map stores the **minimum prefix sum** seen so far for each value, which minimizes the subtracted part of the formula.
- Negative values strictly inside the chosen range are excluded from the kept trees (cut).
- The first and last trees are always kept, even if negative.
- If multiple optimal solutions exist, any is accepted.
