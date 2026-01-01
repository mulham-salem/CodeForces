# Problem 405A – Gravity Flip

## Requirement
You are given:

- An integer **n** — the number of columns.
- An array of **n** integers, where each integer represents the number of cubes in a column.

Initially, gravity pulls the cubes **downwards**.
Then gravity is flipped to the **right**.

Your task is to output the new configuration of columns after gravity is flipped.

---

## Input
- Integer **n**
- **n** integers — the heights of the columns

---

## Output
- **n** integers — the column heights after the gravity flip

---

## Examples

### Example 1
**Input**
```

4
3 2 1 2

```

**Output**
```

1 2 2 3

```

**Explanation**

Initial columns:
```

█ █ █
█ █
█
█ █

```

After gravity flips to the right, cubes slide to the right,
so columns are reordered by height in **non-decreasing order**.

---

### Example 2
**Input**
```

3
4 3 1

```

**Output**
```

1 3 4

```

**Explanation**

All cubes move to the rightmost side.
Shorter columns end up on the left, taller ones on the right.

---

## Key Observation
Flipping gravity to the right does **not** change the number of cubes —
it only changes **their horizontal positions**.

This results in the columns being sorted by height.

---

## Solution Idea
1. Read the array of column heights.
2. Sort the array in **ascending order**.
3. Output the sorted array.

---

## Important Notes
- The physical simulation is not required.
- Only the final column heights matter.
- Sorting is sufficient to solve the problem.

---

## Complexity
- **Time Complexity:** O(n log n)
- **Space Complexity:** O(1) or O(n) depending on sorting method

---

## Key Insight
After gravity flips to the right, the columns will always appear in
**sorted order from left to right**.

