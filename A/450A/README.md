# Problem 450A – Jzzhu and Children

## Problem Description
There are `n` children standing in a line.
Each child `i` needs at least `a[i]` candies.

Jzzhu gives candies using the following rules:

1. Give `m` candies to the first child in the line.
2. If the child still needs more candies, they go to the end of the line.
3. Otherwise, the child leaves the line (goes home).
4. Repeat until the line is empty.

Children leave the line one by one.
The task is to determine **which child leaves last**.

---

## Key Observation
Each child receives exactly `m` candies per turn.

So, the only thing that matters is:
> **How many turns does each child need?**

This is calculated using:

```

turns = ceil(a[i] / m)

```

The child who needs the **maximum number of turns** will leave last.

If multiple children need the same maximum number of turns,
the one with the **largest index** leaves last
(because they start later in the line).

---

## What is Required?
1. For each child, calculate how many turns they need.
2. Track the maximum number of turns.
3. Output the index of the child with the maximum turns.
4. If there is a tie, choose the child with the higher index.

---

## Example 1

### Input
```

5 2
1 3 1 4 2

```

### Explanation

| Child | Candies Needed | Turns = ceil(a / m) |
|------|---------------|---------------------|
| 1 | 1 | 1 |
| 2 | 3 | 2 |
| 3 | 1 | 1 |
| 4 | 4 | 2 |
| 5 | 2 | 1 |

- Maximum turns = 2
- Children with 2 turns: **2 and 4**
- Child **4** has the larger index

### Output
```

4

```

---

## Example 2

### Input
```

6 4
1 1 2 2 3 3

```

### Explanation

| Child | Candies Needed | Turns |
|------|---------------|-------|
| 1 | 1 | 1 |
| 2 | 1 | 1 |
| 3 | 2 | 1 |
| 4 | 2 | 1 |
| 5 | 3 | 1 |
| 6 | 3 | 1 |

- All children need the same number of turns
- The child with the largest index leaves last

### Output
```

6

```

---

## Important Formula
To compute `ceil(a / m)` without floating-point numbers:

```

(a + m - 1) / m

```

---

## Summary
- Each child needs `ceil(a[i] / m)` turns.
- The child with the maximum number of turns leaves last.
- If multiple children tie, choose the one with the largest index.
- No simulation or queue is required.
- A single loop is enough.

---