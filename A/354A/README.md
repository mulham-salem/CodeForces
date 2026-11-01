# Problem 354A – Vasya and Robot

## Problem Summary

Vasya has `n` items in a row, each with a weight `w[i]`. A robot with two arms must collect all items. It can:

- Take the **leftmost** item using the left hand: costs `w[i] * l`. If the **previous action was also left**, an extra `Ql` is added.
- Take the **rightmost** item using the right hand: costs `w[j] * r`. If the **previous action was also right**, an extra `Qr` is added.

The goal is to find the **minimum total energy** spent to collect all items.

---

## Key Idea

If the robot takes `k` items from the left and `n - k` items from the right (for some `0 ≤ k ≤ n`):

- The base cost is always: `(sum of first k weights) * l + (sum of last n-k weights) * r`
- Extra penalties only occur when **one hand is used more than once in a row beyond the alternation limit**:
  - If `k > (n - k) + 1`, the left hand was used `k - (n - k) - 1` extra times consecutively → add `(k - (n-k) - 1) * Ql`
  - If `n - k > k + 1`, the right hand was used `(n - k) - k - 1` extra times → add `((n-k) - k - 1) * Qr`

We try **every possible split point `k`** and take the minimum.

---

## Example 1

```

n=3, l=4, r=4, Ql=19, Qr=1
w = [42, 3, 99]

```

Try all splits:

| k (left) | right | base cost | extra | total |
|----------|-------|-----------|-------|-------|
| 0 | 3 | 0*4 + 144*4 = 576 | (3-0-1)*1 = 2 | 578 |
| 1 | 2 | 42*4 + 102*4 = 576 | 0 | **576** |
| 2 | 1 | 45*4 + 99*4 = 576 | 0 | **576** |
| 3 | 0 | 144*4 + 0 = 576 | (3-0-1)*19 = 38 | 614 |

**Answer: 576**

---

## Example 2

```

n=4, l=7, r=2, Ql=3, Qr=9
w = [1, 2, 3, 4]

```

Best split is `k = 1` (one from left, three from right):

- Base: `1*7 + (2+3+4)*2 = 7 + 18 = 25`
- Right count (3) > left count (1) + 1 → extra `(3 - 1 - 1) * 9 = 9`
- Total: `25 + 9 = 34`

**Answer: 34**

---

## Pseudocode

```

read n, l, r, Ql, Qr
read weights[1..n]
total = sum(weights)

leftWeight = 0
answer = INF

for k from 0 to n:
	rightWeight = total - leftWeight
	leftCount  = k
	rightCount = n - k

	energy = leftWeight * l + rightWeight * r

	if leftCount > rightCount + 1:
		energy += (leftCount - rightCount - 1) * Ql

	if rightCount > leftCount + 1:
		energy += (rightCount - leftCount - 1) * Qr

	answer = min(answer, energy)

	if k < n:
		leftWeight += weights[k + 1]   // 1-indexed
	
print answer

```

---

## Complexity

- **Time:** `O(n)` — single pass over all split points.
- **Space:** `O(n)` — to store weights (or `O(1)` extra beyond input).

---

## Notes

- The extra penalty only applies **once per "run" of consecutive same-hand actions**, not per item — the formula above handles this correctly.
- Even if `l == r`, the optimal split may differ because of `Ql` and `Qr`.