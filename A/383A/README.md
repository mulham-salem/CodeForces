# Problem 383A – Milking cows

## Problem Summary

There are `n` cows in a row, each facing either **left (0)** or **right (1)**.

- A cow facing **left** sees all cows with **smaller indices** (to her left).
- A cow facing **right** sees all cows with **larger indices** (to her right).

When a cow is milked, every cow that **sees** it loses 1 unit of milk.
A cow that has already been milked can no longer be scared.

We must milk every cow exactly once, in any order, and minimize the **total milk lost**.

---

## Key Observation

The total loss equals the number of **pairs `(i, j)`** such that:

- `i < j`
- cow `i` faces **right** (`a[i] == 1`)
- cow `j` faces **left** (`a[j] == 0`)

Why? Because cow `i` (facing right) sees cow `j` (to its right). If cow `j` is milked **before** cow `i`, then cow `i` gets scared and loses 1 unit.

It turns out we can always order the milking so that **exactly** these pairs cause a loss — and no others. So the minimum loss is simply the count of such "conflicting" pairs.

---

## Example 1

```

n = 4
a = 0 0 1 0

```

Pairs with `1` before `0`:

- index 3 (`1`) with index 4 (`0`) → 1 pair

**Answer: 1**

Milking order: `3, 4, 2, 1` → only cow 4 gets scared once.

---

## Example 2

```

n = 5
a = 1 0 1 0 1

```

Pairs `(i < j)` with `a[i] = 1`, `a[j] = 0`:

- (1,2), (1,4), (3,4) → 3 pairs

**Answer: 3**

---

## Algorithm

Scan the array from left to right, maintaining a counter `ones` of how many right-facing cows we've seen so far.

- If `a[i] == 1` → increment `ones`.
- If `a[i] == 0` → add `ones` to the answer (each previous right-facing cow forms a conflicting pair with this left-facing cow).

Time complexity: **O(n)**, Memory: **O(1)**.

---

## Pseudocode

```

read n
ones = 0
ans = 0
for i from 1 to n:
	read x
	if x == 1:
		ones = ones + 1
	else:
		ans = ans + ones
print ans

```

---

## Complexity

- **Time:** `O(n)` — a single pass over the array.
- **Space:** `O(1)` — only two counters are used.