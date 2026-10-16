# Problem 334A – Candy Bags

## Problem Summary

Gerald has `n` younger brothers (where `n` is even). He bought `n²` candy bags containing `1, 2, 3, ..., n²` candies respectively (one bag for each amount).

He must distribute **n bags to each brother** so that **every brother gets the same total number of candies**.

### Input
- A single even integer `n` (2 ≤ n ≤ 100).

### Output
- Print `n` lines, each containing `n` distinct integers from `1` to `n²`.
- Each brother (line) must receive exactly the same total sum of candies.
- Any valid ordering is accepted.

---

## Key Idea

The total number of candies is:

```

1 + 2 + 3 + ... + n² = n²(n² + 1) / 2

```

Since there are `n` brothers, each brother must get:

```

n(n² + 1) / 2

```

A simple and elegant construction: **pair the smallest remaining number with the largest remaining number**.

- Pair `1` with `n²`
- Pair `2` with `n² − 1`
- Pair `3` with `n² − 2`
- and so on...

Each pair sums to `n² + 1`. Since each brother receives `n/2` such pairs, each brother's total is:

```

(n/2) × (n² + 1) = n(n² + 1) / 2

```

which matches the required value. ✅

---

## Example

### Input
```

2

```

### Output
```

1 4
2 3

```

**Explanation:**
- Brother 1 gets bags with `1` and `4` candies → total = 5.
- Brother 2 gets bags with `2` and `3` candies → total = 5.

Both brothers have the same total. ✅

---

### Another Example (n = 4)

Bags contain: `1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16`

Each brother must get `4` bags summing to `34`.

One valid distribution:

```

1  16  2  15
3  14  4  13
5  12  6  11
7  10  8   9

```

Check: `1 + 16 + 2 + 15 = 34` ✅ and similarly for all rows.

---

## Pseudocode

```

READ n
left  = 1
right = n * n

FOR i = 1 TO n:
	FOR j = 1 TO n / 2:
		PRINT left, right
		left  = left + 1
		right = right - 1
	PRINT newline
END

```

---

## Complexity

- **Time:** O(n²) — we print exactly `n²` numbers.
- **Space:** O(1) — only two counter variables are used.

---

## Notes

- `n` is guaranteed to be even, so `n²` is always even and pairing works perfectly.
- The order inside each line doesn't matter — any permutation is accepted.
- The solution is guaranteed to exist for all valid inputs.
