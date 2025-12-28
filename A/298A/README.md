# Problem 298A – Snow Footprints

## Requirement

You are given a string representing footprints in the snow.

The string consists of the following characters:

- `'L'` – a footprint made while moving to the left
- `'R'` – a footprint made while moving to the right
- `'.'` – no footprint

The footprints belong to **one person only** who walked in a straight line.

---

**Goal:**  
Determine the **starting position** and the **ending position** of the person.

Positions are **1-based indices**.

---

## Input

- One string `s` consisting of characters `'L'`, `'R'`, and `'.'`

---

## Output

- Two integers:
  - Starting position
  - Ending position

---

## Examples

### Example 1

**Input**

```

..RRR..

```

**Output**

```

3 6

```

**Explanation**

```

The person moved to the right.
First footprint at position 3
Last footprint at position 6

```

---

### Example 2

**Input**

```

..LLL..

```

**Output**

```

6 3

```

**Explanation**

```

The person moved to the left.
First footprint at position 6
Last footprint at position 3

```

---

## Solution Idea

1. Find the **first occurrence** of either `'L'` or `'R'`.
2. Find the **last occurrence** of either `'L'` or `'R'`.
3. Determine the direction:
   - If the first footprint is `'R'`, the person walked to the right.
   - If the first footprint is `'L'`, the person walked to the left.
4. Based on the direction, compute start and end positions.

---

## Explanation

- For movement to the right (`'R'`):
  - Start = index of first `'R'`
  - End = index of last `'R'` + 1

- For movement to the left (`'L'`):
  - Start = index of last `'L'`
  - End = index of first `'L'` - 1

All indices are printed using **1-based indexing**.

---

## Formula

```

If direction == 'R':
start = first_R
end   = last_R + 1

If direction == 'L':
start = last_L
end   = first_L - 1

```

---

## Implementation Notes

- The string contains footprints of only one direction.
- Convert from 0-based indexing to 1-based indexing when printing.
- Time complexity is `O(n)`.