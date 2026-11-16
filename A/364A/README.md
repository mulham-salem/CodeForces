# Problem 364A – Matrix

## Problem Summary

You are given an integer `a` and a string `s` of decimal digits.

Define a matrix `b` where `b[i][j] = s[i] * s[j]` (1-indexed).  
A rectangle in this matrix is defined by four integers `(x, y, z, t)` with `x ≤ y` and `z ≤ t`.  
The rectangle contains all cells `(i, j)` such that `x ≤ i ≤ y` and `z ≤ j ≤ t`.

You must count how many rectangles have the **sum of all their elements equal to `a`**.

---

## Key Observation

For a rectangle defined by row range `[x, y]` and column range `[z, t]`, the sum is:

$$
[
\sum_{i=x}^{y} \sum_{j=z}^{t} s_i \cdot s_j = \left( \sum_{i=x}^{y} s_i \right) \cdot \left( \sum_{j=z}^{t} s_j \right)
]
$$

So the problem reduces to:

1. Compute the frequency of every possible **substring sum** of `s` (contiguous subarray sum).
2. Count pairs of substring sums `(p, q)` such that `p * q = a`.

---

## Special Case: `a = 0`

If `a = 0`, then at least one of the two sums must be `0`.

Let `Z` = number of substrings with sum `0`, and `T` = total number of substrings = `n(n+1)/2`.

The answer is:

$$
[
2 \cdot Z \cdot T - Z \cdot Z
]
$$

This counts all pairs where the first sum is `0` or the second sum is `0`, subtracting the double-counted case where both are `0`.

---

## Example 1

**Input:**
```

10
12345

```

Substring sums and their frequencies are computed. Then we count pairs `(p, q)` with `p * q = 10`.

The valid pairs give a total of **6** rectangles.

**Output:** `6`

## Example 2

**Input:**
```

16
439873893693495623498263984765

```

**Output:** `40`

---

## Pseudocode

```

read a
read s
n = length(s)

maxSum = 9 * n
freq = array of size maxSum+1 initialized to 0

// Count all substring sums
for i from 0 to n-1:
	sum = 0
	for j from i to n-1:
		sum += digit(s[j])
		freq[sum] += 1

total = n * (n + 1) / 2

if a == 0:
	zero = freq[0]
	answer = 2 * zero * total - zero * zero
else:
	answer = 0
	for x from 1 to maxSum:
		if a % x == 0:
			y = a / x
		if y <= maxSum:
			answer += freq[x] * freq[y]

print answer

```

---

## Complexity

- **Time:** `O(n²)` — we enumerate all substrings to compute sums.
- **Space:** `O(n)` — frequency array of size at most `9n + 1`.

With `n ≤ 4000`, this is fast enough.
