# Problem 93A – Frames

## 🧩 Problem Statement

Folders are arranged sequentially from `1` to `n`, displayed in a grid where each row contains `m` folders.

You are given a segment `[a, b]` and must select **exactly these folders** using the minimum number of rectangular selections.

Each selection is a rectangle aligned with the grid.

---

## 📥 Input

n m a b

| Variable | Meaning |
|----------|--------|
| n        | total number of folders |
| m        | number of folders per row |
| a        | start index |
| b        | end index |

---

## 📤 Output

| Output |
|--------|
| Minimum number of rectangular selections |

---

## 🧠 Key Idea

Each index can be mapped to grid coordinates:

row = (x - 1) / m col = (x - 1) % m

So the problem becomes:
👉 how many rectangles are needed to cover a continuous segment inside a grid.

---

## 🔍 Observations

| Case | Description | Result |
|------|------------|--------|
| Same row | a and b in same row | 1 |
| Full alignment | starts at col 0 and ends at last col | 1 |
| Multi-row segment | spans rows but can merge middle | 2 or 3 |

---

## 📌 Examples

### Example 1

Input: 11 4 3 9

Grid:

1  2  3  4 5  6  7  8 9 10 11

Range:

3 → 9

Selections:

[3 4] [5 6 7 8] [9]

Output:

3

---

### Example 2

Input: 20 5 2 20

Grid:

1  2  3  4  5 6  7  8  9 10 11 12 13 14 15 16 17 18 19 20

Range:

2 → 20

Selections:

[2 3 4 5] [6 → 20]

Output:

2

---

## ⚡ Complexity

| Type | Complexity |
|------|------------|
| Time | O(1) |
| Memory | O(1) |

---

## 🧾 Summary

- Convert indices to grid positions
- Analyze how segment spans rows
- Merge full rows when possible
- Use minimal rectangular splits


---