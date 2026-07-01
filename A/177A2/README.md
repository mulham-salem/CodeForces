# Problem 177A2 – Good Matrix Elements

## Overview
You are given an **odd-sized** square matrix `n × n`.

Your task is to calculate the **sum of all "good" elements**.

An element is considered **good** if it belongs to **at least one** of the following:
- The main diagonal.
- The secondary diagonal.
- The middle row.
- The middle column.

> **Note:** If an element belongs to multiple groups (such as the center element), it should be counted **only once**.

---

## Example

### Input
```text
3
1 2 3
4 5 6
7 8 9
```

### Good Elements
```text
1 2 3
4 5 6
7 8 9
```

All elements are good, so:

```text
Sum = 45
```

---

### Another Example

For a `5 × 5` matrix:

```text
X . X . X
. X X X .
X X X X X
. X X X .
X . X . X
```

`X` represents the good elements.

---

## Idea

Traverse every element in the matrix.

For each position `(i, j)`, check whether it belongs to:
- the main diagonal,
- the secondary diagonal,
- the middle row,
- or the middle column.

If any condition is true, add its value to the answer.

---

## Pseudocode

```text
read n
middle = n / 2
sum = 0

for each row i
    for each column j
        read value

        if (i == j) OR
           (i + j == n - 1) OR
           (i == middle) OR
           (j == middle)

            sum += value

print sum
```

---

## Complexity

- **Time Complexity:** `O(n²)`
- **Space Complexity:** `O(1)`

---