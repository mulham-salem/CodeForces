# Problem 263A – Beautiful Matrix

## Requirement

You are given a **5 × 5 matrix** that contains only `0`s and exactly **one `1`**.

In one move, you are allowed to:
- Swap two **adjacent rows**, or
- Swap two **adjacent columns**

Your goal is to move the `1` to the **center of the matrix**.

The center position is `(3, 3)` using **1-based indexing**.

---

## Input

- Five lines
- Each line contains five integers (`0` or `1`)
- Exactly one of them is `1`

---

## Output

- One integer — the **minimum number of moves** required to bring the `1` to the center

---

## Examples

### Example 1

**Input**
```

0 0 0 0 0
0 0 0 0 0
0 0 1 0 0
0 0 0 0 0
0 0 0 0 0

```

**Output**
```

0

```

**Explanation**
```

The number 1 is already in the center (3,3).
No moves are needed.

```

---

### Example 2

**Input**
```

0 0 0 0 0
0 0 0 0 0
1 0 0 0 0
0 0 0 0 0
0 0 0 0 0

```

**Output**
```

2

```

**Explanation**
```

Current position of 1: (3,1)

Moves needed:

* Move right → column 2
* Move right → column 3

Total moves = 2

```

---

## Solution Idea

1. Find the position `(row, column)` of the number `1`.
2. The target position is always `(3, 3)`.
3. Each row or column swap moves the `1` by exactly **one step**.
4. The minimum number of moves is the **Manhattan distance** to the center.

---

## Distance Formula

```

moves = |row - 3| + |column - 3|

```

---

## Important Notes

- Matrix size is fixed (5 × 5).
- Only one `1` exists.
- No simulation of swaps is required.
- This problem tests understanding of grid movement.

---

## Complexity

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---

## Key Insight

Swapping rows and columns is equivalent to moving the `1`
up, down, left, or right.
The shortest path is always the Manhattan distance.