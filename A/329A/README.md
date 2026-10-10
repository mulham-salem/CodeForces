# Problem 329A – Purification

## Problem Summary

You are given an `n × n` grid where each cell is either:

- `.` → a normal cell (can be chosen to cast the spell on)
- `E` → an "extra evil" cell (cannot be chosen, but can still be purified if its row or column is covered)

Casting a "Purification" spell on cell `(r, c)` purifies **the entire row `r`** and **the entire column `c`**.

You must purify **all `n × n` cells** using the **minimum number of spells**, and you cannot cast the spell on any `E` cell.

If it's impossible, print `-1`.

---

## Key Observation

Since a single spell purifies one full row **and** one full column, the minimum number of spells needed is exactly `n`, because:

- `n` spells are always enough if a valid selection exists.
- Fewer than `n` spells cannot cover all `n` rows (or all `n` columns).

So the answer is either `-1` or exactly `n` moves.

There are only **two valid strategies**:

1. **Row-based strategy:** Pick exactly one `.` cell from each row.
   → This covers all rows directly, and the chosen columns must cover every column too.

2. **Column-based strategy:** Pick exactly one `.` cell from each column.
   → This covers all columns directly, and the chosen rows must cover every row too.

If either strategy works, print its `n` moves. Otherwise, print `-1`.

---

## Why It Works

- If we pick one cell per row: every row is purified. The union of chosen columns must also equal all `n` columns, otherwise some column would never be purified.
- The same logic applies symmetrically for columns.
- If neither strategy is possible, no valid answer exists.

---

## Example 1

```

3
.E.
E.E
.E.

```

**Row strategy:**

- Row 1 → (1,1) ✅
- Row 2 → (2,2) ✅
- Row 3 → (3,3) ✅

Columns chosen: 1, 2, 3 → all covered.

**Output:**

```

1 1
2 2
3 3

```

---

## Example 2

```

3
EEE
E..
E.E

```

- Row 1 has no `.` → row strategy fails.
- Column 1 has no `.` → column strategy fails.

**Output:**

```

-1

```

---

## Example 3

```

5
EE.EE
E.EE.
E...E
.EE.E
EE.EE

```

Row strategy fails (some row has no `.`), but column strategy succeeds.

**Output:**

```

3 3
1 3
2 2
4 4
5 3

```

---

## Pseudocode

```

read n
read grid[n][n]

# Try row-based strategy

ans = []
for i in 0..n-1:
	for j in 0..n-1:
		if grid[i][j] == '.':
			ans.push((i+1, j+1))
			break
	if no '.' found in row i:
		ans = null
		break

if ans is not null:
	print ans
	exit

# Try column-based strategy

ans = []
for j in 0..n-1:
	for i in 0..n-1:
		if grid[i][j] == '.':
			ans.push((i+1, j+1))
			break
	if no '.' found in column j:
		ans = null
		break

if ans is not null:
	print ans
else:
	print -1

```

---

## Time Complexity

**Time:** `O(n²)` — each strategy scans the grid once in the worst case.  
**Space:** `O(n)` — for storing the answer list (plus `O(n²)` for the input grid itself).

---