# Problem 303A – Lucky Permutation Triple

## Problem Summary

You are given an integer `n`. You must find three permutations `a`, `b`, and `c` of length `n` (each containing integers from `0` to `n-1` exactly once) such that for every index `i`:

$$
(a_i + b_i) \bmod n = c_i
$$

If no such triple exists, print `-1`.

---

## Key Observation

A Lucky Permutation Triple exists **only when `n` is odd**.

Why? If we sum all elements of `a`, `b`, and `c`, each equals:

$$
0 + 1 + 2 + \dots + (n-1) = \frac{n(n-1)}{2}
$$

Since `(a_i + b_i) mod n = c_i`, summing over all `i` gives:

$$
\sum a_i + \sum b_i \equiv \sum c_i \pmod{n}
$$

$$
2 \cdot \frac{n(n-1)}{2} \equiv \frac{n(n-1)}{2} \pmod{n}
$$

This simplifies to requiring:

$$
\frac{n(n-1)}{2} \equiv 0 \pmod{n}
$$

Which only holds when `n` is **odd**. For even `n`, the answer is always `-1`.

---

## Construction for Odd `n`

A simple valid construction is:

| Permutation | Value at index `i` |
|-------------|--------------------|
| `a[i]`      | `i`                |
| `b[i]`      | `i`                |
| `c[i]`      | `(2 * i) mod n`    |

Since `n` is odd, multiplication by `2` is a bijection modulo `n`, so `c` is also a valid permutation.

---

## Examples

### Example 1:

**Input:**
```

5

```

**Output:**
```

0 1 2 3 4
0 1 2 3 4
0 2 4 1 3

```

Verification:

| i | a[i] | b[i] | (a[i]+b[i]) mod 5 | c[i] |
|---|------|------|-------------------|------|
| 0 | 0    | 0    | 0                 | 0    |
| 1 | 1    | 1    | 2                 | 2    |
| 2 | 2    | 2    | 4                 | 4    |
| 3 | 3    | 3    | 1                 | 1    |
| 4 | 4    | 4    | 3                 | 3    |

---

### Example 2:

**Input:**
```

2

```

**Output:**
```

-1

```

---

## Pseudocode

```

READ n

IF n is even:
	PRINT -1
	EXIT

FOR i from 0 to n-1:
	PRINT i
	PRINT newline

FOR i from 0 to n-1:
	PRINT i
	PRINT newline

FOR i from 0 to n-1:
	PRINT (2 * i) mod n
	PRINT newline

```

---

## Complexity

| Type  | Value  |
|-------|--------|
| Time  | `O(n)` |
| Space | `O(1)` |

---