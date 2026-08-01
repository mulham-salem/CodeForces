# Problem 216A – Tiling with Hexagons

## Idea

The hexagon has side lengths:

$$
a, b, c, a, b, c
$$

(opposite sides have equal lengths).

Instead of counting the hexagonal tiles directly, transform the figure into a **parallelogram**.

### Number of rows

The parallelogram has:

$$
a + b - 1
$$

rows.

The `-1` appears because the corner tile is shared by both sides.

### Number of columns

Similarly, it has:

$$
a + c - 1
$$

columns.

So the total number of tiles in the parallelogram is:

$$
(a + b - 1) × (a + c - 1)
$$

However, this parallelogram contains an extra triangular region that is **not** part of the original hexagon.

The number of tiles inside this extra region is:

$$
a × (a - 1)
$$

Therefore, subtract these tiles.

---

## Formula

$$
Answer = (a + b - 1) × (a + c - 1) - a × (a - 1)
$$

---

## Example

### Input

```text
2 3 4
```

Parallelogram:

```text
Rows    = 2 + 3 - 1 = 4
Columns = 2 + 4 - 1 = 5

Tiles = 4 × 5 = 20
```

Extra region:

```text
2 × (2 - 1) = 2
```

Final answer:

```text
20 - 2 = 18
```

---

## Algorithm

1. Read `a`, `b`, and `c`.
2. Compute the number of rows: `a + b - 1`.
3. Compute the number of columns: `a + c - 1`.
4. Compute the parallelogram area.
5. Subtract the extra region `a × (a - 1)`.
6. Print the result.

---

## Pseudocode

```text
read a, b, c

rows = a + b - 1
cols = a + c - 1

answer = rows * cols - a * (a - 1)

print answer
```

---

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---