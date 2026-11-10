# Problem 357A – Group of Students

## Problem Summary

A university wants to split students into two groups: **beginners** and **intermediate**.  
Each student has a score from `1` to `m`. We are given:

- `c[i]` = number of students who scored `i` points (for `i = 1..m`)
- `x` = minimum allowed group size
- `y` = maximum allowed group size

We must choose a passing rate `k` (`1 ≤ k ≤ m`) such that:

- Students with score **less than `k`** → beginner group
- Students with score **at least `k`** → intermediate group
- **Both** group sizes must be between `x` and `y` (inclusive)

If multiple `k` values work, print any one. If none work, print `0`.

---

## Examples

### Example 1
```

Input:
5
3 4 3 2 1
6 8

Output:
3

```
Explanation:  
With `k = 3`:
- Beginner (scores 1,2) = `3 + 4 = 7` ✅ (between 6 and 8)
- Intermediate (scores 3,4,5) = `3 + 2 + 1 = 6` ✅ (between 6 and 8)

---

### Example 2
```

Input:
5
0 3 3 4 2
3 10

Output:
4

```
Explanation:  
With `k = 4`:
- Beginner (scores 1,2,3) = `0 + 3 + 3 = 6` ✅
- Intermediate (scores 4,5) = `4 + 2 = 6` ✅

Another valid answer is `k = 3`:
- Beginner = `0 + 3 = 3` ✅
- Intermediate = `3 + 4 + 2 = 9` ✅

---

### Example 3
```

Input:
2
2 5
3 6

Output:
0

```
Explanation:  
Possible splits:
- `k = 1`: beginner = 0 ❌ (too small)
- `k = 2`: beginner = 2 ❌ (too small), intermediate = 5 ✅
- `k = 3`: beginner = 7 ❌ (too big)

No valid `k` exists → output `0`.

---

## Approach (Pseudocode)

```

read m
read c[1..m]
read x, y

beginner = 0
intermediate = sum(c[1..m])

for k from 2 to m:            // k is the passing rate
	beginner     += c[k-1]
	intermediate -= c[k-1]

	if x <= beginner <= y and x <= intermediate <= y:
		print k
		exit
	
print 0

```

---

**Key idea:**  
Move the "cut point" `k` from left to right. Each step moves one score-group from the intermediate side to the beginner side. Check both sizes against `[x, y]` at every step.

---

**Complexity:** `O(m)` time, `O(m)` space.
