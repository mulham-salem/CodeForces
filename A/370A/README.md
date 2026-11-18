# Problem 370A – Rook, Bishop and King

## Problem Summary

Given two squares on an 8×8 chessboard, find the minimum number of moves needed for:
- **Rook** – moves any number of squares horizontally or vertically
- **Bishop** – moves any number of squares diagonally
- **King** – moves one square in any direction

Print the three answers in that order. If a piece cannot reach the target, print `0` for it.

---

## Approach

Let `dr = |r1 - r2|` and `dc = |c1 - c2|`.

---

### Rook
- **1 move** if the two squares share the same row or column.
- **2 moves** otherwise (go to the intersection of the target's row/column).
- Always reachable, so never `0`.

### Bishop
- **1 move** if `dr == dc` (on the same diagonal).
- **2 moves** if `(r1 + c1) % 2 == (r2 + c2) % 2` — same color square, so reachable in 2 diagonal moves.
- **0** otherwise (different color squares — impossible).

### King
- The king moves like a Chebyshev distance: minimum moves = `max(dr, dc)`.
- Always reachable.

---

## Examples

**Input:**
```

4 3 1 6

```
**Output:**
```

2 1 3

```

**Input:**
```

5 5 5 6

```
**Output:**
```

1 0 1

```

### Explanation of Example 1
- Rook: different row and column → **2 moves**
- Bishop: `dr = 3`, `dc = 3` → same diagonal → **1 move**
- King: `max(3, 3) = 3` → **3 moves**

### Explanation of Example 2
- Rook: same row → **1 move**
- Bishop: `dr = 0`, `dc = 1` → not same diagonal; colors differ (`10` vs `11` odd/even) → **0**
- King: `max(0, 1) = 1` → **1 move**

---

## Pseudocode

```

read r1, c1, r2, c2

dr = abs(r1 - r2)
dc = abs(c1 - c2)

# Rook

if r1 == r2 or c1 == c2:
	rook = 1
else:
	rook = 2

# Bishop

if dr == dc:
	bishop = 1
else if (r1 + c1) % 2 == (r2 + c2) % 2:
	bishop = 2
else:
	bishop = 0

# King

king = max(dr, dc)

print rook, bishop, king

```

---

## Complexity
- **Time:** O(1)
- **Space:** O(1)
