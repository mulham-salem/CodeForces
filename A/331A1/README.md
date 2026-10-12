# Problem 331A1 – Oh Sweet Beaverette

## Problem Summary

Given a sequence of `n` integers representing tree appeal values, choose a contiguous segment (by cutting some trees) such that:

1. The **sum of remaining trees is maximized**.
2. The **first and last trees of the remaining belt have equal appeal**.
3. At least **two trees remain**.

Trees can only be cut from the **outside** of the chosen segment or from **inside** if they have **negative appeal** (since removing negative values increases the sum).

---

## Key Idea

We want to pick two indices `i < j` with `a[i] == a[j]`. The belt will be the segment `[i, j]`. Inside this segment:

- Keep **all positive or zero values**.
- Cut **all negative values**.

So the total sum for a pair `(i, j)` is:

```

sum = a[i] + a[j] + sum of all positive values strictly between i and j

```

We maximize this sum over all valid pairs.

To do this efficiently, we use a **prefix sum of positive contributions**:

```

pref[k] = sum of max(0, a[t]) for t < k

```

Then for a pair `(i, j)`:

```

sum = a[i] + a[j] + (pref[j] - pref[i+1])

```

---

## Example

### Example 1

**Input:**
```

5
1 2 3 1 2

```

Pick `i = 0` (value 1) and `j = 3` (value 1). Between them: `2, 3` — both positive.

Sum = `1 + 1 + 2 + 3 = 7`? Wait, actual output is `8`. Let's check pair `(0, 3)`: `1 + 2 + 3 + 1 = 7`.

Better pair: `i = 1` (value 2) and `j = 4` (value 2). Between: `3, 1`.

Sum = `2 + 2 + 3 + 1 = 8`. Yes.

Cut: only tree 1 (index 0, value 1) is removed.

**Output:**
```

8 1
1

```

---

### Example 2

**Input:**
```

5
1 -2 3 1 -2

```

Pick `i = 0` (value 1) and `j = 3` (value 1). Between: `-2, 3`.

Keep `3`, cut `-2`.

Sum = `1 + 1 + 3 = 5`.

Cut trees: index 2 (value -2) and index 5 (value -2).

**Output:**
```

5 2
2 5

```

---

## Pseudocode

```

read n
read array a[0..n-1]

pref[0] = 0
for i in 0..n-1:
	pref[i+1] = pref[i] + max(0, a[i])

bestSum = -infinity
bestLeft = 0
bestRight = 1

for i in 0..n-1:
	for j in i+1..n-1:
		if a[i] == a[j]:
			sum = a[i] + a[j] + pref[j] - pref[i+1]
		if sum > bestSum:
			bestSum = sum
			bestLeft = i
			bestRight = j

cut = []
for k in 0..n-1:
	if k < bestLeft or k > bestRight:
		cut.append(k+1)
	else if k > bestLeft and k < bestRight and a[k] < 0:
		cut.append(k+1)

print bestSum, len(cut)
print cut

```

## Complexity

- **A1 (n ≤ 100):** O(n²) brute force — passes easily.
- **A2 (n ≤ 3·10⁵):** Need to group equal values and use prefix sums efficiently — O(n log n) or O(n) with hash maps.

---