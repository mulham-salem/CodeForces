# Problem 384A – Coder

## Problem Summary

A **Coder** is a chess piece that attacks one square **horizontally or vertically** (like a rook that moves only 1 step). Given an `n × n` chessboard, place the maximum number of Coders so that **no two Coders attack each other**.

### Key Insight

Since a Coder attacks its 4 direct neighbors (up, down, left, right), **no two Coders can be adjacent horizontally or vertically**. This is equivalent to the classic **checkerboard coloring** problem.

If we color the board like a chessboard (alternating black/white cells), then:
- Two cells of the **same color** are **never** horizontally or vertically adjacent.
- Therefore, placing Coders on **all cells of one color** guarantees no attacks.

### Maximum Count

On an `n × n` board, the number of cells with `(i + j) % 2 == 0` is:

$$\left\lceil \frac{n^2}{2} \right\rceil = \frac{n^2 + 1}{2}$$

This is always the maximum possible, since adjacent cells must alternate — so at most one of every two adjacent cells can hold a Coder.

---

## Examples

### Example 1 — `n = 2`

**Output:**
```

2
C.
.C

```
Two Coders placed on the main diagonal — they don't share a row or column adjacency.

### Example 2 — `n = 3`

**Output:**
```

5
C.C
.C.
C.C

```
The corners and center are used. Total = 5 = ⌈9/2⌉.

### Example 3 — `n = 1`

**Output:**
```

1
C

```
Only one cell — a single Coder fits.

---

## Pseudocode

```

READ n
answer ← (n * n + 1) / 2
PRINT answer

FOR i FROM 0 TO n-1:
	FOR j FROM 0 TO n-1:
		IF (i + j) is even:
			PRINT 'C'
		ELSE:
			PRINT '.'
	PRINT newline

```

---

## Complexity

| Metric | Value |
|--------|-------|
| Time   | O(n²) |
| Space  | O(1) extra (output only) |

---

## Notes

- The construction `(i + j) % 2 == 0` places Coders on cells where the row and column indices have the **same parity** (both even or both odd).
- Any valid checkerboard pattern (starting with `.` instead of `C`) also works — the problem accepts **any** correct configuration.
- The answer can never exceed `⌈n²/2⌉` because every 2×1 or 1×2 block can hold at most one Coder.