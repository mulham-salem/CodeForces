# Problem 259A – Little Elephant and Chess

## Problem Summary

We are given an `8 × 8` board containing `W` (white) and `B` (black) cells.

A valid chessboard must:
- Have different colors in every pair of side-adjacent cells.
- Have `W` in the upper-left cell.

For each row, we can perform any number of cyclic right shifts independently.

The goal is to determine whether it is possible to transform the given board into a valid chessboard.

---

## Key Idea

A row can be transformed into a valid alternating row using cyclic shifts only if its cells are already alternating in a circular manner.

Therefore, for every row, we only need to check that every cell differs from its next cell, including the last cell and the first cell.

If this condition holds for all rows, the rows can be shifted independently to match the required chessboard pattern.

The number of shifts does not matter because we only need to determine whether a valid board is possible.

---

## Examples

### Example 1

### Input:

```text
WBWBWBWB
BWBWBWBW
BWBWBWBW
BWBWBWBW
WBWBWBWB
WBWBWBWB
BWBWBWBW
WBWBWBWB
```
### Output:

```
YES
```

Each row is circularly alternating, so the rows can be shifted to form a valid chessboard.

---

### Example 2

### Input:
```
WBWBWBWB
WBWBWBWB
BBWBWWWB
BWBWBWBW
BWBWBWBW
BWBWBWWW
BWBWBWBW
BWBWBWBW
```

### Output:
```
NO
```

Some rows contain adjacent cells with the same color, so no amount of cyclic shifting can turn them into an alternating row.

---

## Pseudocode
```
FOR each of the 8 rows:
    FOR each position j from 0 to 7:
        next = (j + 1) mod 8

        IF row[j] == row[next]:
            PRINT "NO"
            STOP

PRINT "YES"
```

---

## Complexity

**Time:** `O(8 × 8) → O(1)`

**Space:** `O(1)`

---