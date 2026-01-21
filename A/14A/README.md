# Problem 14A – Letter

## 📝 Problem Summary
Bob has a rectangular grid of size `n × m` consisting of:
- `'*'` → shaded cells  
- `'.'` → empty cells  

Bob wants to **cut out the cheapest possible rectangle** that contains **all shaded cells (`*`)**.
The rectangle:
- Must include **every `*`**
- Must have sides **parallel to the grid**
- Can include empty cells if needed

The task is to **output that minimum rectangle**, not its cost.

It is guaranteed that **at least one cell is shaded**.

---

## 💡 Key Idea
To get the minimum rectangle containing all `*`, we need to find the **extreme boundaries** of the shaded cells:

- Topmost row containing `*`
- Bottommost row containing `*`
- Leftmost column containing `*`
- Rightmost column containing `*`

Once these four boundaries are known, we simply print the subgrid defined by them.

---

## 🔍 Approach
1. Initialize:
   - `min_row` to a very large value
   - `max_row` to a very small value
   - `min_col` to a very large value
   - `max_col` to a very small value
2. Traverse the entire grid:
   - For each `*`, update the four boundaries
3. Print the rectangle formed by:
   - Rows from `min_row` to `max_row`
   - Columns from `min_col` to `max_col`

---

## ✏️ Pseudocode
```

read n, m
read the grid

min_row = n, min_col = m
max_row = -1, max_col = -1

for each cell (i, j) in the grid:
if grid[i][j] == '*':
min_row = min(min_row, i)
max_row = max(max_row, i)
min_col = min(min_col, j)
max_col = max(max_col, j)

for i from min_row to max_row:
for j from min_col to max_col:
print grid[i][j] without space
print new line

```

---

## 🧪 Example

### Input
```

3 3

---

*.*

---

```

### Output
```

---

*.*

---

```

---

## ⏱️ Complexity
- **Time Complexity:** `O(n × m)`
- **Space Complexity:** `O(n × m)` (for storing the grid)

---

## ✅ Notes
- Do **not** rely on the first or last `*` found — this can fail in tricky cases.
- Using minimum and maximum row/column indices guarantees correctness.
- This solution always produces the **minimum-cost rectangle**.

---

✨ Suitable for competitive programming and clean enough for a GitHub README.
