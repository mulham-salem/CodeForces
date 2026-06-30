# Problem 177A1 – Good Matrix Elements

## Problem Summary

You are given an **odd-sized** square matrix (`n × n`).

A matrix element is considered **good** if it belongs to at least one of the following:

- The **main diagonal**.
- The **secondary diagonal**.
- The **middle row**.
- The **middle column**.

Your task is to calculate the **sum of all good elements**, counting each element **only once**, even if it belongs to multiple categories.

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

### Output
```text
45
```

---

### Input
```text
5
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
1 1 1 1 1
```

### Output
```text
17
```

Only **17 unique positions** are good, and each contains `1`.

---

## Idea

Traverse every element in the matrix.

For each position `(i, j)`, check whether it is:

- On the main diagonal (`i == j`)
- On the secondary diagonal (`i + j == n - 1`)
- In the middle row (`i == n / 2`)
- In the middle column (`j == n / 2`)

If **any** condition is true, add its value to the answer.

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

- **Time:** `O(n²)`
- **Space:** `O(1)`

---