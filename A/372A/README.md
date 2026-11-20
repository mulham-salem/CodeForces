# Problem 372A – Counting Kangaroos is Fun

## Problem Summary

You are given `n` kangaroos, each with a size. A kangaroo can hold at most **one** other kangaroo in its pocket, but only if its size is **at least twice** the size of the kangaroo it holds. A kangaroo that is held cannot hold any other kangaroo.

A held kangaroo becomes **invisible**. Find the **minimum number of visible kangaroos** possible.

---

## Approach

The key idea is to **pair as many kangaroos as possible** such that the larger one is at least twice the smaller one, while respecting the "one holder / one held" rule.

1. **Sort** the sizes in ascending order.
2. Split the array into two halves:
   - The **first half** (`0` to `n/2 - 1`) are candidates to be **held** (small kangaroos).
   - The **second half** (`(n+1)/2` to `n-1`) are candidates to be **holders** (large kangaroos).
3. Use a **two-pointer** technique:
   - Pointer `i` starts at the beginning of the small half.
   - Pointer `j` starts at the beginning of the large half.
   - If `a[j] >= 2 * a[i]`, we can hide `a[i]` inside `a[j]` → increment `hidden`, move both pointers.
   - Otherwise, the current large kangaroo is too small → try the next larger one (`j++`).
4. The answer is `n - hidden`.

> Why split at the middle? Because at most `n/2` kangaroos can be hidden (each hidden one needs a distinct holder, and a holder cannot itself be hidden).

---

## Constraints

- `1 ≤ n ≤ 5·10^5`
- `1 ≤ s_i ≤ 10^5`

---

## Example 1

**Input:**
```

8
2 5 7 6 9 8 4 2

```

Sorted: `2 2 4 5 6 7 8 9`

| i | j | a[i] | a[j] | 2*a[i] | Can hide? | hidden |
|---|---|------|------|--------|-----------|--------|
| 0 | 4 | 2    | 6    | 4      | ✅        | 1      |
| 1 | 5 | 2    | 7    | 4      | ✅        | 2      |
| 2 | 6 | 4    | 8    | 8      | ✅        | 3      |
| 3 | 7 | 5    | 9    | 10     | ❌        | 3      |

**Result:** `8 - 3 = 5` ✅

---

## Example 2

**Input:**
```

8
9 1 6 2 6 5 8 3

```

Sorted: `1 2 3 5 6 6 8 9`

Pairs found: `(1→6)`, `(2→6)`, `(3→8)` → hidden = 3

**Result:** `8 - 3 = 5` ✅

---

## Pseudocode

```

read n
read array a of size n
sort a

i = 0
j = (n + 1) / 2
hidden = 0

while i < n/2 and j < n:
	if a[j] >= 2 * a[i]:
		hidden += 1
		i += 1
		j += 1
	else:
		j += 1

print n - hidden

```

---

## Complexity

- **Time:** `O(n log n)` due to sorting, then `O(n)` for the two-pointer scan.
- **Space:** `O(n)` for storing the array.