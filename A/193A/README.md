# Problem 193A – Cutting Figure

## Problem Summary

You are given an `n × m` grid where some cells are painted.

- `#` represents a painted cell.
- `.` represents an empty cell.

The set of all painted cells is initially **connected**.

Your task is to find the minimum number of painted cells that need to be removed so that the remaining painted cells become **disconnected**.

A group of cells is connected if every two cells can reach each other using only moves in four directions:

- Up
- Down
- Left
- Right

If it is impossible to make the figure disconnected, print `-1`.

---

## Key Observation

The answer can only be one of three values:

- `-1` → Impossible.
- `1` → Removing one cell is enough.
- `2` → Removing any single cell is not enough, but two cells are always enough if a solution exists.

Therefore, we only need to test whether removing one painted cell can disconnect the figure.

---

## Algorithm

1. Count the number of painted cells.

2. If the number of painted cells is less than `3`:
   - Print `-1`.
   - Stop.

3. Try removing every painted cell one by one:

   - Temporarily remove the cell.
   - Run DFS/BFS from any remaining painted cell.
   - Count how many painted cells can be reached.
   - If the number of reached cells is smaller than the remaining number of painted cells:
     - The figure became disconnected.
     - The answer is `1`.

4. If no single cell can disconnect the figure:
   - The answer is `2`.

---

## Pseudocode

```text
Count all painted cells (#)

If total painted cells < 3:
    print -1
    stop

For each painted cell:

    Remove this cell temporarily

    Reset visited array

    Find any remaining painted cell

    Run DFS/BFS from that cell

    Count visited painted cells

    If visited cells != remaining painted cells:
        print 1
        stop

    Restore the removed cell

print 2
```

---

## Examples

### Example 1

#### Input
```
5 4
####
#..#
#..#
#..#
####
```
#### Explanation

The figure is a hollow rectangle.

Removing one cell is not enough to break the connection, but removing two suitable cells makes the shape disconnected.

#### Output
```
2
```

---

### Example 2

#### Input
```
5 5
#####
#...#
#####
#...#
#####
```
#### Explanation

The painted rows are connected through the sides.

No single cell can disconnect the figure, but deleting two cells separates the shape into multiple parts.

#### Output
```
2
```

---

## Complexity Analysis

Let `N = n × m` be the number of cells.

For each painted cell, we run a DFS/BFS over the grid.

**Time Complexity**: `O((n × m)²)`

**Space Complexity**: `O(n × m)`

The constraints are small enough for this approach.

---