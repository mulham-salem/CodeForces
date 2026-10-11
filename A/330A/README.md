# Problem 330A – Cakeminator

## Problem Summary

You are given an `r × c` cake grid. Each cell is either:
- `'.'` → a normal cake cell
- `'S'` → a cake cell with an evil strawberry

The Cakeminator can eat **an entire row** or **an entire column** in one move, but only if that row/column contains **no `'S'`** and has at least one uneaten cake cell.

Find the **maximum number of cake cells** he can eat.

---

## Key Idea

- Any row with no `'S'` can be fully eaten.
- Any column with no `'S'` can be fully eaten.
- Cells that belong to both a safe row and a safe column should **not be counted twice**.

So:
1. Mark all cells in safe rows as eaten.
2. Mark all cells in safe columns as eaten.
3. Count how many cells are marked.

---

## Example

**Input:**
```

3 4
S...
....
..S.

```

**Grid:**
```

S . . .
. . . .
. . S .

```

- Row 1 (index 1): safe → eat all 4 cells.
- Row 2 (index 2): has `S` → skip.
- Row 0: has `S` → skip.
- Column 0: has `S` → skip.
- Column 1: safe → eat 3 cells (but 1 already eaten).
- Column 2: has `S` → skip.
- Column 3: safe → eat 3 cells (but 1 already eaten).

**Eaten cells:**
```

. X X X
X X X X
X X . X

```

Total = **8**

**Output:**
```

8

```

---

## Pseudocode
```

read r, c
read grid

eaten = 2D array of false

for each row i:
	if row i has no 'S':
		mark all cells in row i as eaten

for each column j:
	if column j has no 'S':
		mark all cells in column j as eaten

ans = count of eaten cells
print ans

```

---

## Complexity
- Time: `O(r × c)`
- Space: `O(r × c)`

---