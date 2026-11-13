# Problem 358A – Dima and Continuous Line

## Problem Summary

Dima has `n` distinct points on the x-axis. He connects them **in the given order**: point 1 → point 2 → point 3 → … → point n, using **semicircles above the x-axis**, where each semicircle's diameter is the segment between two consecutive points.

We need to determine if any two of these semicircles **intersect each other** (self-intersection of the resulting line).

---

## Input

- First line: integer `n` (1 ≤ n ≤ 10³) — number of points.
- Second line: `n` distinct integers `x₁, x₂, …, xₙ` (−10⁶ ≤ xᵢ ≤ 10⁶) — coordinates of the points (not necessarily sorted).

---

## Output

- Print `"yes"` if the line has self-intersections.
- Print `"no"` otherwise.

---

## Examples

**Example 1**

Input:
```

4
0 10 5 15

```

Output:
```

yes

```

Explanation: Semicircles (0,10), (10,5), (5,15) — the first and third cross, so the line self-intersects.

---

**Example 2**

Input:
```

4
0 15 5 10

```

Output:
```

no

```

Explanation: Semicircles (0,15), (15,5), (5,10) — no two of them cross, so the line is intersection-free.

---

## Key Idea

Two semicircles with diameters `[a,b]` and `[c,d]` (where `a < b`, `c < d`) intersect **if and only if** exactly one endpoint of the second segment lies strictly inside the first segment:

```

a < c < b < d   or   c < a < d < b

```

We check this condition for every pair of **non-adjacent** semicircles (since adjacent ones share an endpoint and don't count as self-intersection).

---

## Pseudocode

```

READ n
READ array x[0..n-1]

FOR i FROM 0 TO n-2:
	a = MIN(x[i], x[i+1])
	b = MAX(x[i], x[i+1])

	FOR j FROM i+2 TO n-2:
		c = MIN(x[j], x[j+1])
		d = MAX(x[j], x[j+1])

		IF (a < c AND c < b AND b < d) OR
		   (c < a AND a < d AND d < b):
			PRINT "yes"
			EXIT
		
PRINT "no"

```

---

## Time Complexity

- **Time:** `O(n²)` — two nested loops over the `n-1` semicircles, checking each pair once. With `n ≤ 10³`, this is at most ~10⁶ operations, well within the 2-second limit.
- **Space:** `O(n)` — for storing the coordinate array.
