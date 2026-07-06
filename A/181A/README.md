# Problem 181A – Series of Crimes

## Problem Summary

You are given an `n × m` grid representing a city map.

The grid contains exactly **three cells marked with `*`**. These three cells represent three vertices of a rectangle whose sides are parallel to the grid.

Your task is to find the coordinates of the **missing fourth vertex** of the rectangle.

---

## Input

- The first line contains two integers `n` and `m`:
  - `n` → number of rows
  - `m` → number of columns

- The next `n` lines contain `m` characters:
  - `*` → a robbed district
  - `.` → an empty district

It is guaranteed that:
- There are exactly three `*` characters.
- A valid fourth vertex always exists.

---

## Output

Print two integers:

- The row number of the missing vertex.
- The column number of the missing vertex.

Rows and columns are **1-indexed**.

---

## Approach

A rectangle has:
- Two equal row coordinates.
- Two equal column coordinates.

Among the three given points:
- The row that appears only once is the missing row.
- The column that appears only once is the missing column.

The intersection of these two values gives the fourth vertex.

---

## Example 1

### Input
```text
3 2
.*
..
**
```

### Explanation
#### Grid
```
. *
. .
* *
```
The star positions are:
```
(1,2)
(3,1)
(3,2)
```
Rows:
```
1, 3, 3
```
The unique row is 1.

Columns:
```
2, 1, 2
```
The unique column is 1.

Therefore, the missing vertex is:
```
(1,1)
```
### Output
```
1 1
```

---

## Example 2

### Input
```
3 3
*.*
*..
...
```

### Explanation
#### Grid
```
* . *
* . .
. . .
```
The star positions are:
```
(1,1)
(1,3)
(2,1)
```
Rows:
```
1, 1, 2
```
The unique row is 2.

Columns:
```
1, 3, 1
```
The unique column is 3.

Therefore, the missing vertex is:
```
(2,3)
```
### Output
```
2 3
```

---

## Pseudocode
```
Read n and m

Create arrays to count rows and columns

For every cell in the grid:
    If the cell contains '*':
        Increase the count of its row
        Increase the count of its column

Find the row with count = 1
Find the column with count = 1

Print that row and column
```

---

## Complexity Analysis

Time Complexity: `O(n × m)`

Space Complexity: `O(n + m)`

---