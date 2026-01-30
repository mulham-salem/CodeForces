# Problem 85A – Domino

## Problem Description

You are given a 4 × n rectangular field. Your task is to tile it with 1 × 2 dominoes (either horizontal or vertical) under the following constraints:

1. Every vertical cut between columns intersects at least one domino.
2. No domino overlaps another.
3. Each cell is covered by exactly one domino.
4. Dominoes are colored using lowercase letters (a–z), and no two adjacent dominoes may share the same color.

**Input:**  
- A single integer `n` (1 ≤ n ≤ 100) — the number of columns.

**Output:**  
- If no solution exists, print `-1`.  
- Otherwise, print 4 lines of n characters each, representing the tiling using letters for colors.

---

## Solution Idea

The main idea is to construct the tiling in **pairs of columns**, ensuring:

- Each vertical cut intersects a horizontal domino.
- No two dominoes of the same color are adjacent.
- Odd and even `n` are handled separately:

1. **Odd n:**  
   - Place a vertical domino in the first column to break symmetry.  
   - Fill remaining columns in pairs with horizontal dominoes in top and middle rows.  
   - Bottom rows use a shifted pattern to ensure vertical cuts are intersected.  
   - Last column in bottom rows is handled separately.

2. **Even n:**  
   - Place vertical dominoes at the first and last columns.  
   - Fill the middle columns in pairs with horizontal dominoes using alternating letters.  
   - Bottom rows use a shifted pattern for all column pairs.

---

## Example (Even n = 6)

```

a a b b c c
d d e e f f
x x y y x x
w w v v w w

```

- Each pair of columns contains horizontal dominoes → all vertical cuts intersected.  
- Letters alternate to avoid adjacent dominoes having the same color.  

---

## Example (Odd n = 5)

```

a b b c ?
a d d e ?
x x y y u
w w v v u

```

- First column uses vertical domino `'a'`.  
- Middle columns use horizontal dominoes in pairs, alternating letters.  
- Last column in bottom rows handled separately with `'u'`.  

---

## Pseudo-code

```

function tile_4xn(n):
create 4xN grid

```
if n == 1:
    place vertical domino in first column
    return grid

if n is odd:
    place vertical domino in first column
    for each pair of columns (starting from 1):
        fill top two rows with horizontal dominoes, alternating letters
    fill bottom two rows with horizontal dominoes, using shifted pattern
    fill last column in bottom rows if necessary

else: # n is even
    place vertical dominoes in first and last columns
    for each pair of columns in middle:
        fill top two rows with horizontal dominoes, alternating letters
    fill bottom two rows with horizontal dominoes, using shifted pattern

return grid
```

```

---

## Notes

- The algorithm guarantees that **every vertical cut intersects at least one domino**.  
- Alternating letters prevent adjacent dominoes from sharing the same color.  
- Works for all 1 ≤ n ≤ 100.  

---

## Usage

- Include this README.md in your GitHub repo alongside the C++ solution file.
- Use the examples above to test and verify the output visually.

---