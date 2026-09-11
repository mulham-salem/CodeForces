# Problem 286A – Lucky Permutation

## Problem Statement

A permutation `p` of size `n` is a sequence of `n` distinct integers from `1` to `n`.

A permutation is called **lucky** if for every `i` (`1 ≤ i ≤ n`):

```

p[p[i]] = n - i + 1

```

Given `n`, find any lucky permutation, or print `-1` if none exists.

---

## Key Observation

Let `q(i) = n - i + 1` be the **reflection** of `i`.

The condition `p[p[i]] = q(i)` means:

> Applying `p` twice equals the reflection `q`. In other words, `p² = q`.

Since `q` is an involution (`q(q(i)) = i`), we need `p⁴ = identity`.

---

## Existence Condition

A lucky permutation exists **only** when:

```

n % 4 == 0   OR   n % 4 == 1

```

Otherwise (when `n % 4 == 2` or `n % 4 == 3`), print `-1`.

### Why?

Elements must be grouped into **4-cycles** of the form `a → x → b → y → a`, where:
- `b = n - a + 1` (reflection of `a`)
- `y = n - x + 1` (reflection of `x`)

- If `n % 4 == 0`: all `n` elements fit into `n/4` cycles.
- If `n % 4 == 1`: one middle element stays fixed, the rest fit into `(n-1)/4` cycles.
- If `n % 4 == 2` or `3`: leftover elements cannot form complete 4-cycles.

---

## Construction Idea

For each unassigned position `a`:
1. Compute its reflection `b = n - a + 1`.
2. Find the next unassigned position `x` (with `x ≠ b`).
3. Compute `y = n - x + 1`.
4. Assign:
```

p[a] = x
p[x] = b
p[b] = y
p[y] = a

```

Special case: if `n % 4 == 1`, the middle element `m = (n+1)/2` satisfies `p[m] = m`.

---

## Examples

### Example 1: `n = 1`
```

Input:  1
Output: 1

```

### Example 2: `n = 2`
```

Input:  2
Output: -1

```

### Example 3: `n = 4`
```

Input:  4
Output: 2 4 1 3

```

**Verification:**

| i | p[i] | p[p[i]] | n-i+1 |
|---|------|---------|-------|
| 1 | 2    | 4       | 4     |
| 2 | 4    | 3       | 3     |
| 3 | 1    | 2       | 2     |
| 4 | 3    | 1       | 1     |

### Example 4: `n = 5`
```

Input:  5
Output: 2 5 3 1 4

```

**Verification:**

| i | p[i] | p[p[i]] | n-i+1 |
|---|------|---------|-------|
| 1 | 2    | 5       | 5     |
| 2 | 5    | 4       | 4     |
| 3 | 3    | 3       | 3     |
| 4 | 1    | 2       | 2     |
| 5 | 4    | 1       | 1     |

### Example 5: `n = 8`
```

Input:  8
Output: 2 8 4 6 3 5 1 7

```

Cycles formed:
- `1 → 2 → 8 → 7 → 1`
- `3 → 4 → 6 → 5 → 3`

---

## Pseudocode

```

FUNCTION solve(n):
	IF n % 4 == 2 OR n % 4 == 3:
	PRINT -1
	RETURN

	p = array of size n+1 initialized to 0

	IF n % 4 == 1:
		m = (n + 1) / 2
		p[m] = m

	FOR a FROM 1 TO n:
		IF p[a] != 0:
			CONTINUE

		b = n - a + 1
		IF p[b] != 0:
			CONTINUE

		x = a + 1
		WHILE x <= n AND (p[x] != 0 OR x == b):
			x = x + 1

		y = n - x + 1

		p[a] = x
		p[x] = b
		p[b] = y
		p[y] = a

	PRINT p[1..n]
```

---

## Complexity

| Metric | Value |
|--------|-------|
| **Time**   | `O(n)`  |
| **Space**  | `O(n)`  |

---

## Summary Table

| Condition       | Result                          |
|-----------------|---------------------------------|
| `n % 4 == 0`    | `n/4` cycles of 4 elements      |
| `n % 4 == 1`    | 1 fixed middle + `(n-1)/4` cycles |
| `n % 4 == 2`    | No solution → `-1`              |
| `n % 4 == 3`    | No solution → `-1`              |

---