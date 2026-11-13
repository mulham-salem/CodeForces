# Problem 359A – Table

## Problem Summary

Simon has an `n × m` table. Some cells are **good** (value `1`), and it's guaranteed that **no good cell is a corner**. Initially all cells are colorless. In one move, Simon picks any good cell `(x1, y1)` and any corner `(x2, y2)`, then colors the entire rectangle between them (inclusive).

The goal is to color **all** cells. Find the **minimum number of operations**.

---

## Key Observation

- If there exists a good cell on the **border** of the table (first row, last row, first column, or last column), then **2 operations** are enough: one rectangle covering the top-left side and one covering the bottom-right side (or any pair of opposite corners).
- Otherwise, all good cells are strictly inside the table. In that case, **4 operations** are needed — one for each corner.

### Why?

- With **2 operations**, you can only reach cells that lie in the union of two corner-rectangles. If a good cell is on an edge, choosing the two corners on the opposite side covers the whole table.
- If all good cells are interior, no single pair of corners can cover everything, so you need all **4 corners**.

---

## Examples

### Example 1
```

3 3
0 0 0
0 1 0
0 0 0

```
The only good cell is `(2,2)` — interior. Answer: **4**.

---

### Example 2
```

4 3
0 0 0
0 0 1
1 0 0
0 0 0

```
Good cells: `(2,3)` (right edge) and `(3,1)` (left edge) — both on the border. Answer: **2**.

---

## Algorithm (Pseudocode)

```

read n, m
answer = 4

for i from 1 to n:
	for j from 1 to m:
		read x
		if x == 1 and (i == 1 or i == n or j == 1 or j == m):
			answer = 2

print answer

```

---

**Time Complexity:** `O(n·m)` — we only scan the grid once.
**Space Complexity:** `O(1)` — no extra storage needed.
