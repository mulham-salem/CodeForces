# Problem 18A – Triangle

## 📌 Problem Description
Given three points with integer coordinates forming a non-degenerate triangle.

Classify the triangle as:

- `RIGHT` → If it is already right-angled.
- `ALMOST` → If it is not right-angled, but by moving one point exactly by distance 1 (to another integer coordinate), it becomes right-angled.
- `NEITHER` → If neither condition is satisfied.

---

## 🧠 Key Idea

### 1. Check if the triangle is right-angled
- Compute squared distances between all pairs of points.
- Sort the three squared side lengths.
- If:

```

smallest² + middle² == largest²

```

Then the triangle is right-angled.

---

### 2. Check for "ALMOST"
If not `RIGHT`:

- Try moving each point.
- For each point, try 4 possible moves:
  - (x+1, y)
  - (x-1, y)
  - (x, y+1)
  - (x, y-1)

- After each move:
  - Recalculate.
  - Check if the triangle becomes right-angled.

If any attempt succeeds → Output `ALMOST`.

---

## ⚙ Pseudocode

```

Read x1, y1, x2, y2, x3, y3

If isRightTriangle(original points):
Print "RIGHT"
Exit

For each point i in {1,2,3}:
For each direction in {up, down, left, right}:
Move point i by 1
If isRightTriangle(new points):
Print "ALMOST"
Exit
Restore point i

Print "NEITHER"

```

---

## 🔎 Time Complexity

- Constant operations
- At most 3 × 4 checks
- Complexity: **O(1)**

---

## 🚀 Example

### Input
```

0 0 2 0 0 1

```

### Output
```

RIGHT

```

---

### Input
```

2 3 4 5 6 6

```

### Output
```

NEITHER

```

---

## 💡 Implementation
(See source code in this repository for the C++ solution.)
