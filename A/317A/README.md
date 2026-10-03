# Problem 317A – Perfect Pair

## Problem Statement

A pair of integers is called **m-perfect** if at least one of the two numbers is greater than or equal to `m`.

You start with two integers `x` and `y` on a blackboard. In one operation, you may erase one of them and replace it with the sum of both numbers `(x + y)`.

Find the **minimum number of operations** needed to make the pair m-perfect, or output `-1` if it is impossible.

---

## Approach

The solution handles three main cases:

1. **Already perfect:** If `x >= m` or `y >= m`, the answer is `0`.

2. **Impossible case:** If both `x <= 0` and `y <= 0`, we can never produce a positive value (since sums of two non-positive numbers stay non-positive), so the answer is `-1`.

3. **General simulation:** Otherwise, we repeatedly grow the smaller number by adding the larger number to it. Special care is taken when one of the numbers is non-positive — in that case, we jump directly to the first value `> 0` using a division, avoiding slow step-by-step simulation.

The key idea: **always add the larger number to the smaller one** (or vice versa) to maximize growth. This produces Fibonacci-like growth, so the loop runs at most ~90 iterations for values up to `10^18`.

---

## Examples

### Example 1
```

Input:  1 2 5
Output: 2

```
Sequence: `(1, 2) → (3, 2) → (5, 2)`

---

### Example 2
```

Input:  -1 4 15
Output: 4

```
Sequence: `(-1, 4) → (3, 4) → (7, 4) → (11, 4) → (15, 4)`

---

### Example 3
```

Input:  0 -1 5
Output: -1

```
Both numbers are non-positive, so we can never reach `5`.

---

## Pseudocode

```

READ x, y, m

IF x >= m OR y >= m:
	PRINT 0
	EXIT

IF x <= 0 AND y <= 0:
	PRINT -1
	EXIT

ans = 0

WHILE x < m AND y < m:
	IF x <= 0:
		k = (-x) / y + 1
		x = x + k * y
		ans = ans + k
	ELSE IF y <= 0:
		k = (-y) / x + 1
		y = y + k * x
		ans = ans + k
	ELSE IF x < y:
		x = x + y
		ans = ans + 1
	ELSE:
		y = y + x
		ans = ans + 1

PRINT ans

```

---

## Complexity

- **Time:** `O(log m)` — the loop grows values Fibonacci-style.
- **Space:** `O(1)`.

---