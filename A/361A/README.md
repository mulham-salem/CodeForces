# Problem 361A – Levko and Table

## Problem Statement

Levko loves tables of size **n × n**. A table is called *beautiful* if the sum of elements in **every row** and **every column** equals **k**.

Given `n` and `k`, print any such table. All elements must not exceed `1000` in absolute value.

**Input:** Two integers `n` and `k` (1 ≤ n ≤ 100, 1 ≤ k ≤ 1000).

**Output:** Any n × n beautiful table.

---

## Examples

**Example 1:**
```

Input:  2 4
Output:
1 3
3 1

```
Row sums: 1+3=4, 3+1=4 ✓
Column sums: 1+3=4, 3+1=4 ✓

**Example 2:**
```

Input:  4 7
Output:
2 1 0 4
4 0 2 1
1 3 3 0
0 3 2 2

```
Every row and column sums to 7 ✓

---

## Idea / Approach

The simplest construction: place `k` on the **main diagonal** and `0` everywhere else.

- Each row contains exactly one `k` and the rest are zeros → row sum = `k` ✓
- Each column contains exactly one `k` and the rest are zeros → column sum = `k` ✓
- All values are either `0` or `k` (≤ 1000) ✓

**Example (n=3, k=5):**
```

5 0 0
0 5 0
0 0 5

```

---

## Pseudocode

```

READ n, k

FOR i FROM 0 TO n-1:
	FOR j FROM 0 TO n-1:
		IF i == j:
			PRINT k
		ELSE:
			PRINT 0
	PRINT newline

```

---

## Complexity

- **Time:** O(n²) — we fill n² cells
- **Space:** O(1) — no extra storage needed

---

## Notes

- Any valid table is accepted (special judge).
- The diagonal construction is the simplest and always valid.
- Values are bounded by `k ≤ 1000`, satisfying the absolute value constraint.