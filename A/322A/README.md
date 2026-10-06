# Problem 322A – Ciel and Dancing

## Problem Summary

There are `n` boys and `m` girls in a dancing room. During each song, exactly one boy and one girl dance together. The special rule is:

- Either the boy must be dancing for the first time, **or** the girl must be dancing for the first time.

We want to schedule as many songs as possible and output the maximum number of songs `k`, followed by the pairs `(boy, girl)` in chronological order.

**Constraints:** `1 ≤ n, m ≤ 100`

---

## Key Idea

Each dance (except the first) must introduce at least one new person. Since there are `n + m` people in total, the maximum number of dances is:

```

k = n + m - 1

```

**Strategy:**
1. Let boy `1` dance with every girl `1..m` → `m` dances (each girl dances for the first time).
2. Then let girl `1` dance with every remaining boy `2..n` → `n - 1` dances (each boy dances for the first time).

Total = `m + (n - 1) = n + m - 1`.

---

## Examples

### Example 1
**Input:**
```

2 1

```
**Output:**
```

2
1 1
2 1

```
**Explanation:** Boy 1 dances with girl 1 (both new), then boy 2 dances with girl 1 (boy 2 is new).

---

### Example 2
**Input:**
```

2 2

```
**Output:**
```

3
1 1
1 2
2 2

```
**Explanation:** Boy 1 dances with girl 1, then boy 1 with girl 2 (girl 2 is new), then boy 2 with girl 2 (boy 2 is new). Total = 3.

---

### Example 3
**Input:**
```

3 1

```
**Output:**
```

3
1 1
2 1
3 1

```

---

### Example 4
**Input:**
```

1 3

```
**Output:**
```

3
1 1
1 2
1 3

```

---

## Pseudocode

```

READ n, m
PRINT n + m - 1

FOR j = 1 TO m:
	PRINT 1, j

FOR i = 2 TO n:
	PRINT i, 1

```

---

## Complexity

- **Time:** O(n + m)
- **Space:** O(1)

---