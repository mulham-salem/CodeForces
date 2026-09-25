# Problem 306A – Candies

## Problem Summary

Polycarpus has `n` candies and `m` friends, where `n ≥ m`. He wants to distribute **all** candies among his friends as fairly as possible.

The goal is to minimize the difference between the **maximum** number of candies given to any friend and the **minimum** number given to any friend.

In other words, we want the distribution to be as equal as possible.

---

## Key Idea

To make the distribution as fair as possible:

1. Divide `n` by `m`:
   - `base = n / m` → the minimum number of candies each friend can get.
   - `remainder = n % m` → the number of friends who will get one extra candy.

2. Give `base + 1` candies to `remainder` friends.
3. Give `base` candies to the remaining `m - remainder` friends.

This guarantees:
- All candies are distributed.
- The maximum difference between any two friends is at most `1`.
- Every friend gets a positive number of candies (since `n ≥ m`, so `base ≥ 1`).

---

## Examples

### Example 1
**Input:**
```

12 3

```
**Output:**
```

4 4 4

```
**Explanation:**
- `base = 12 / 3 = 4`
- `remainder = 12 % 3 = 0`
- All friends get 4 candies.

---

### Example 2
**Input:**
```

15 4

```
**Output:**
```

3 4 4 4

```
**Explanation:**
- `base = 15 / 4 = 3`
- `remainder = 15 % 4 = 3`
- 3 friends get `3 + 1 = 4` candies.
- 1 friend gets `3` candies.

---

### Example 3
**Input:**
```

18 7

```
**Output:**
```

2 2 2 3 3 3 3

```
**Explanation:**
- `base = 18 / 7 = 2`
- `remainder = 18 % 7 = 4`
- 4 friends get `2 + 1 = 3` candies.
- 3 friends get `2` candies.

---

## Pseudocode

```

READ n, m

base = n / m
remainder = n % m

FOR i = 1 TO m:
	IF remainder > 0:
		PRINT base + 1
		remainder = remainder - 1
	ELSE:
		PRINT base
END FOR

```

---

## Complexity

- **Time Complexity:** `O(m)` — we loop once over all friends.
- **Space Complexity:** `O(1)` — only a few integer variables are used.

---