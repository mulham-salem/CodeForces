# Problem 445A – DZY Loves Chessboard

## Problem Overview
You are given an `n × m` chessboard.

- Cells marked with `-` are **broken** and must remain unchanged.
- Cells marked with `.` must be colored either:
  - `B` (Black)
  - `W` (White)

### Constraint
Any two **adjacent cells** (up, down, left, right) must have **different colors**.

---

## Key Observation
A chessboard naturally alternates colors.

If we index rows and columns starting from `0`, then for any cell `(i, j)`:

- If `(i + j)` is **even**, color the cell `B`
- If `(i + j)` is **odd**, color the cell `W`

This guarantees that:
- Every adjacent cell has a different color
- No additional neighbor checks are required

The colors can also be swapped (`W` for even, `B` for odd) and the solution will still be valid.

---

## Why This Works
Moving to any adjacent cell always changes either the row or the column by `1`, which flips the parity of `(i + j)`:

- Even → Odd
- Odd → Even

Therefore, adjacent cells will always receive opposite colors.

---

## Example

### Input
```

3 4
....
.-..
....

```

### Output
```

BWBW
W-BW
BWBW

```

- The `-` cell remains unchanged
- All adjacent non-broken cells have different colors

---

## Pseudocode
```

read n, m
read the board

for each row i from 0 to n - 1:
for each column j from 0 to m - 1:
if board[i][j] is '-':
continue
else:
if (i + j) is even:
board[i][j] = 'B'
else:
board[i][j] = 'W'

print the board

```

---

## Summary
- The problem reduces to coloring a chessboard pattern
- Parity of `(row + column)` determines the color
- Broken cells are skipped
- Time complexity: **O(n × m)**
- Simple, clean, and guaranteed to satisfy the constraints
