# Problem 336A – Vasily the Bear and Triangle

## 📌 Problem Summary

Vasily has a favorite rectangle with one vertex at the origin `(0,0)` and the opposite vertex at `(x, y)`, with sides parallel to the axes.

He wants to find two integer points `A = (x₁, y₁)` and `C = (x₂, y₂)` such that:

- `x₁ < x₂`
- The triangle `ABC` (with `B = (0,0)`) is a **right isosceles triangle** with the right angle at `B`.
- The entire rectangle lies **inside or on the border** of the triangle.
- The **area of the triangle is as small as possible**.

> It is guaranteed that the answer is unique.

---

## 💡 Key Idea

Since the triangle is right isosceles at the origin, its two equal legs must lie along the coordinate axes (or their extensions). The hypotenuse lies on the line:

```

|x| + |y| = d

```

To contain the rectangle, the point `(x, y)` must satisfy `|x| + |y| ≤ d`. The smallest possible area comes from the smallest `d`, so we pick:

```

d = |x| + |y|

```

Then the two points `A` and `C` are the intercepts of this line with the axes, chosen so that `x₁ < x₂`.

---

## 🧭 Points by Quadrant

| Quadrant | Sign of x, y | A | C |
|----------|--------------|---|---|
| I   | x > 0, y > 0 | (0, d)  | (d, 0)  |
| II  | x < 0, y > 0 | (-d, 0) | (0, d)  |
| III | x < 0, y < 0 | (-d, 0) | (0, -d) |
| IV  | x > 0, y < 0 | (0, -d) | (d, 0)  |

where `d = |x| + |y|`.

---

## 🔍 Examples

### Example 1
**Input:**
```

10 5

```
**Output:**
```

0 15 15 0

```
`d = 10 + 5 = 15`. The rectangle's far corner `(10,5)` lies exactly on the hypotenuse `x + y = 15`.

---

### Example 2
**Input:**
```

-10 5

```
**Output:**
```

-15 0 0 15

```
`d = 10 + 5 = 15`. The far corner `(-10,5)` lies exactly on the hypotenuse `-x + y = 15`.

---

## 🧩 Pseudocode

```

read x, y
d ← |x| + |y|

if x > 0 and y > 0:
	print 0, d, d, 0
else if x < 0 and y > 0:
	print -d, 0, 0, d
else if x < 0 and y < 0:
	print -d, 0, 0, -d
else:  // x > 0 and y < 0
	print 0, -d, d, 0

```

---

## ⏱️ Complexity

- **Time:** `O(1)`
- **Space:** `O(1)`

---

## ✅ Notes

- The answer is always unique.
- The corner `(x, y)` always lies **on the hypotenuse** of the minimal triangle.
- Both `A` and `C` always have one coordinate equal to `0`, since they lie on the axes.
