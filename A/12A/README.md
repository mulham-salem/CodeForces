# Problem 12A – Super Agent

## 🧠 Problem Summary

You are given a 3×3 digital keyboard.  
Each cell contains either:

- `X` → the button was pressed  
- `.` → the button was not pressed  

The password is considered **valid** if the pressed buttons form a shape that is **centrally symmetric** with respect to the center cell of the grid.

Your task is to determine whether the given 3×3 matrix is centrally symmetric.

---

## 🔄 What is Central Symmetry?

A matrix is centrally symmetric if it looks exactly the same after rotating it **180 degrees**.

For a 3×3 matrix, each cell `(i, j)` must be equal to:

```

(2 - i, 2 - j)

```

The center cell `(1,1)` maps to itself.

---

## 📌 Required Symmetric Pairs

The following positions must match:

| Position | Must Equal |
|----------|------------|
| (0,0) | (2,2) |
| (0,1) | (2,1) |
| (0,2) | (2,0) |
| (1,0) | (1,2) |
| (1,1) | itself |

If **all pairs match**, print `YES`.  
If **any pair differs**, print `NO`.

---

## ✅ Example 1

Input:
```

XX.
...
.XX

```

Check pairs:

- (0,0) = X and (2,2) = X ✔
- (0,1) = X and (2,1) = X ✔
- (0,2) = . and (2,0) = . ✔
- (1,0) = . and (1,2) = . ✔

All symmetric → **YES**

---

## ❌ Example 2

Input:
```

X.X
X..
...

```

Check first pair:

- (0,0) = X  
- (2,2) = .  

Mismatch → **NO**

---

## 💡 Approach

We compare every cell `(i, j)` with its centrally symmetric counterpart `(2 - i, 2 - j)`.

If all comparisons match, the matrix is centrally symmetric.

---

## 🧾 Pseudocode

```

read 3x3 matrix

for i from 0 to 2:
for j from 0 to 2:
if matrix[i][j] != matrix[2 - i][2 - j]:
print "NO"
stop

print "YES"

```

---

## ⏱ Complexity

Time Complexity: O(1)  
(Only 9 cells are checked)

Space Complexity: O(1)