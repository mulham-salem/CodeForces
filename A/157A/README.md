# Problem 157A – Game Outcome

## Overview

You are given an `n × n` board where each cell contains an integer.

For every cell:

- Compute the sum of all numbers in its **row**.
- Compute the sum of all numbers in its **column**.

A cell is considered **winning** if:

```text
Column Sum > Row Sum
```

Your task is to count how many winning cells exist on the board.

---

## Key Idea

Instead of recalculating row and column sums for every cell, first:

1. Compute the sum of each row.
2. Compute the sum of each column.

Then iterate through all cells and check whether the column sum is greater than the row sum corresponding to that cell.

This avoids redundant calculations and keeps the solution simple.

---

## Example 1

### Input

```text
1
1
```

### Row Sums

| Row | Sum |
|------|------|
| 1 | 1 |

### Column Sums

| Column | Sum |
|---------|------|
| 1 | 1 |

Since:

```text
1 > 1
```

is false, there are no winning cells.

### Output

```text
0
```

---

## Example 2

### Input

```text
2
1 2
3 4
```

### Row Sums

| Row | Sum |
|------|------|
| 1 | 3 |
| 2 | 7 |

### Column Sums

| Column | Sum |
|---------|------|
| 1 | 4 |
| 2 | 6 |

Checking each cell:

| Cell | Row Sum | Column Sum | Winning |
|------|----------|------------|----------|
| (1,1) | 3 | 4 | Yes |
| (1,2) | 3 | 6 | Yes |
| (2,1) | 7 | 4 | No |
| (2,2) | 7 | 6 | No |

### Output

```text
2
```

---

## Pseudocode

```text
read n

read the board

compute sum of every row
compute sum of every column

answer = 0

for each cell (i, j):
    if columnSum[j] > rowSum[i]:
        answer++

print answer
```

---

## Complexity Analysis

| Operation | Complexity |
|------------|------------|
| Computing row sums | O(n²) |
| Computing column sums | O(n²) |
| Checking all cells | O(n²) |
| Total | O(n²) |

Since `n ≤ 30`, this solution easily fits within the limits.

---