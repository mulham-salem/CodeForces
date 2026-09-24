# Problem 305A – Strange Addition

## Problem Summary

Vasya can only add two integers `(a, b)` if, for every decimal place, **at least one** of the numbers has digit `0` in that position.

For example:
- `505 + 50` is allowed ✅ (units: 5 & 0, tens: 0 & 5, hundreds: 5 & 0)
- `1 + 4` is **not** allowed ❌ (units: 1 & 4 — both non-zero)

Given a set of `k` distinct non-negative integers (each between `0` and `100`), find the **maximum number** of integers we can choose such that **any pair** from the chosen set can be summed by Vasya.

---

## Key Insight

Represent each number by a **3-bit mask** indicating which decimal positions have a **non-zero digit**:

| Position | Bit value |
|----------|-----------|
| Units    | `1` (001) |
| Tens     | `2` (010) |
| Hundreds | `4` (100) |

Two numbers can be summed **iff their masks are disjoint** (`mask_a & mask_b == 0`).

Since `0` has mask `0`, it's compatible with everything.

---

### Maximum Size

- We can take **all** numbers with mask `0` (which is only `0` itself, since the set has distinct values).
- For every other mask, we can take **at most one** number.
- All chosen non-zero masks must be **pairwise disjoint**.

Since there are only `3` positions, the answer is at most `4`:
`{0, units-only, tens-only, hundreds-only}`.

But we may also combine multi-bit masks (e.g., `11` has mask `3`), as long as they don't overlap.

---

### Algorithm

1. Compute the mask for each number.
2. Group numbers by mask into 8 buckets.
3. Try all `2^8 = 256` subsets of masks.
4. A subset is valid if all its masks are pairwise disjoint.
5. Count: `numbers[0].size()` + (one number from each chosen non-zero mask).
6. Output the best subset.

---

## Example 1

**Input:**
```

4
100 10 1 0

```

**Masks:**
- `0`   → `000`
- `1`   → `001`
- `10`  → `010`
- `100` → `100`

**Best subset:** all four masks → size `4`
**Output:**
```

4
0 1 10 100

```

---

## Example 2

**Input:**
```

3
2 70 3

```

**Masks:**
- `2`  → `001`
- `3`  → `001`
- `70` → `010`

**Best subset:** masks `{001, 010}` → size `2`
**Output:**
```

2
2 70

```

> Note: `2` and `3` share the same mask, so only one of them can be picked.

---

## Pseudocode

```

function getMask(x):
	mask = 0
	if x % 10 != 0:        mask |= 1
	if (x/10) % 10 != 0:   mask |= 2
	if (x/100) % 10 != 0:  mask |= 4
	return mask

main:
read k
buckets = array of 8 empty lists
for each input number x:
	buckets[getMask(x)].append(x)

	bestCount = 0
	bestSet   = 0

	for subset in 0 .. 255:
		valid = true
		for i in 0..7:
			if subset has bit i:
				for j in i+1..7:
					if subset has bit j and (i & j) != 0:
						valid = false
		if not valid: continue

		total = len(buckets[0])
		for mask in 1..7:
			if subset has bit mask and buckets[mask] not empty:
				total += 1

		if total > bestCount:
			bestCount = total
			bestSet   = subset

print bestCount
print all numbers in buckets[0]
for mask in 1..7:
    if bestSet has bit mask:
        print buckets[mask][0]
```

---

## Complexity

- **Time:** `O(2^8 · 8^2 + k)` ≈ constant — extremely fast.
- **Space:** `O(k)` for storing the numbers.

---

## Notes

- Since `d_i ≤ 100`, only 3 decimal positions matter (units, tens, hundreds).
- Numbers are distinct, so bucket `0` contains at most one element (the number `0`).
- Any valid answer has size at most `4`.

---