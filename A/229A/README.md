# 229A — Shifts

## Problem

You are given a table with `n` rows and `m` columns. Each cell contains either `0` or `1`.

In one move, you can choose any row and cyclically shift it by one position:

- One position to the left.
- One position to the right.

The goal is to make **at least one column consist entirely of `1`s** using the minimum possible number of moves.

If it is impossible, print `-1`.

---

## Key Idea

We can choose any column as the **target column**.

For each row, we need to find the minimum number of cyclic shifts required to move some `1` in that row to the target column.

We use two arrays:

- `cost[j]` — minimum shifts needed for the **current row** to put a `1` in column `j`.
- `answer[j]` — total shifts needed for **all rows** to make column `j` contain only `1`s.

For every row, we calculate its `cost` array and add it to `answer`.

---

## Calculating `cost`

```text
Initially, all positions are set to infinity:

cost = [INF, INF, INF, ...]

For every position containing 1:

cost[j] = 0

because no shift is needed if the 1 is already in column j.

Left to Right

We propagate distances from the left:

for j = 1 to m - 1:
    cost[j] = min(cost[j], cost[j - 1] + 1)

If a position on the left can be reached in x moves, the next position can be reached in x + 1 moves.

Right to Left

We do the same from the right:

for j = m - 2 down to 0:
    cost[j] = min(cost[j], cost[j + 1] + 1)

After these two passes, cost[j] contains the minimum distance to a 1 when the row is treated as a normal line.
```

---

## Handling the Circular Row

The rows are cyclic, so the closest `1` can also be reached by crossing the boundary between the last and first columns.

**We find:**
$$
firstOne — position of the first 1
$$

$$
lastOne — position of the last 1
$$

For every column col, there are two possible wrap-around paths.

**The distances are:**
$$
col + m - lastOne
$$

**and**

$$
firstOne + m - col
$$

**Therefore:**
$$
wrapDistance = min(
    col + m - lastOne,
    firstOne + m - col
)
$$

**Then update:**
$$
cost[col] = min(cost[col], wrapDistance)
$$

`This ensures that cost represents the true cyclic distance.`


---

## Combining All Rows

cost belongs only to the current row.

answer accumulates the costs of all rows.

**For every column:**

$$
answer[col] += cost[col]
$$

**For example:**

`Row 1:`
```
cost = [2, 0, 1]

answer = [2, 0, 1]
```

For the next row:

`Row 2:`
```
cost = [1, 2, 0]

answer = [3, 2, 1]
```

**Therefore:**

$$
answer[j]
$$

**represents the total number of shifts required to make column j contain only 1s.**

**The final answer is:**

$$
min(answer)
$$

---

## Impossible Case

If any row contains no `1`, it is impossible to create an all-1 column.

Shifting a row cannot create a `1` if the row contains only `zeros`.

Therefore, if a row has no `1`:
```
print -1
```

---

## Pseudocode

```
Read n, m
Read the table

answer[0 ... m - 1] = 0

For each row i:

    cost[0 ... m - 1] = INF

    For each column j:
        If table[i][j] == '1':
            cost[j] = 0

    // Left to Right
    For j from 1 to m - 1:
        cost[j] = min(cost[j], cost[j - 1] + 1)

    // Right to Left
    For j from m - 2 down to 0:
        cost[j] = min(cost[j], cost[j + 1] + 1)

    Find firstOne
    Find lastOne

    If no '1' exists:
        print -1
        stop

    // Handle circular distance
    For each column col:

        wrapDistance = min(
            col + m - lastOne,
            firstOne + m - col
        )

        cost[col] = min(cost[col], wrapDistance)

    // Add current row's cost
    For each column col:
        answer[col] += cost[col]

Print the minimum value in answer
```

---

## Complexity

For each row, we make a constant number of passes over the m columns.

**Therefore:**
$$
O(n \times m)
$$

**Memory usage:**

$$
O(m)
$$

With:

`n ≤ 100`

`m ≤ 10000`


the solution is efficient enough for the given limits.

---