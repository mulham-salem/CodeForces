# Problem 347A – Difference Row

## Problem Summary

You are given `n` integers. You must arrange them in some order `x1, x2, ..., xn` to **maximize** the value:

```

(x1 - x2) + (x2 - x3) + ... + (x(n-1) - xn)

```

Notice this sum **telescopes**:

```

(x1 - x2) + (x2 - x3) + ... + (x(n-1) - xn) = x1 - xn

```

All middle terms cancel out! So the value depends **only** on the first and last elements.

To maximize `x1 - xn`:
- Put the **largest** element first.
- Put the **smallest** element last.

The middle elements can be in any order without affecting the value. To get the **lexicographically smallest** arrangement among all optimal ones, sort the middle `n-2` elements in **ascending** order.

---

## Example

**Input:**
```

5
100 -100 50 0 -50

```

**Sorted array:** `-100, -50, 0, 50, 100`

**Arrangement:**
- First → largest: `100`
- Middle → sorted ascending: `-50, 0, 50`
- Last → smallest: `-100`

**Output:**
```

100 -50 0 50 -100

```

**Value check:**
```

(100 - (-50)) + (-50 - 0) + (0 - 50) + (50 - (-100))
= 150 - 50 - 50 + 150
= 200

```

Also equals `x1 - xn = 100 - (-100) = 200` ✓

---

## Pseudocode

```

READ n
READ array a of size n

SORT a in ascending order

PRINT a[n-1]          // largest element first

FOR i = 1 TO n-2:
	PRINT a[i]   	// middle elements in ascending order
	
PRINT a[0]            // smallest element last

```

---

## Complexity

- **Time:** `O(n log n)` — dominated by sorting
- **Space:** `O(n)` — for storing the array

---

## Key Insight

> The sum telescopes to `x1 - xn`, so only the endpoints matter. Maximize by placing max first and min last; for lexicographic minimality, sort the middle in ascending order.
