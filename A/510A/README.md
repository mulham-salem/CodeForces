# Problem 510A – Fox And Snake

## Requirement
You are given:

- Two integers **n** and **m** — the number of rows and columns of a grid.

You must print an **n × m** pattern representing a snake.

The pattern follows these rules:
- Rows with an **odd index** (1-based) are filled entirely with `#`.
- Rows with an **even index** alternate:
  - First even row: `.` repeated (m−1) times, then `#` at the end.
  - Next even row: `#` at the beginning, then `.` repeated (m−1) times.
- This alternating pattern continues for all even rows.

---

## Input
- Two integers **n m**

---

## Output
- Print **n lines**, each containing **m characters**, forming the snake pattern.

---

## Examples

### Example
**Input**
```

3 3

```

**Output**
```

###

..#

###

```

---

### Example 2
**Input**
```

4 5

```

**Output**
```

#####

....#

#####

#....

```

---

## Solution Idea
1. Iterate through rows from `1` to `n`.
2. For odd rows:
   - Print `m` times `#`.
3. For even rows:
   - Alternate between:
     - `m-1` dots and a `#` at the end.
     - `#` followed by `m-1` dots.

---

## Important Notes
- Row numbering is **1-based**.
- The direction of the snake alternates on even rows.
- Output format must be exact.

---

## Complexity
- **Time Complexity:** O(n × m)
- **Space Complexity:** O(1)

---

## Key Insight
Odd rows are always fully filled with `#`.
Even rows place a single `#` that alternates between the **right** and **left** sides,
creating the snake pattern.
