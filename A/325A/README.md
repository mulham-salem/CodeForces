# Problem 325A – Square and Rectangles

## Problem Description

You are given **n** rectangles (1 ≤ n ≤ 5). Each rectangle has sides parallel to the axes and integer corner coordinates. The rectangles may touch each other but **do not overlap** (no interior point belongs to more than one rectangle).

Determine whether the union of all rectangles forms exactly a **square** (i.e., the set of points inside or on the border of at least one rectangle equals the set of points inside or on the border of some square).

---

### Input
- First line: integer `n`
- Next `n` lines: `x1 y1 x2 y2` — left, bottom, right, top edges of each rectangle
- Constraints: `0 ≤ x1 < x2 ≤ 31400`, `0 ≤ y1 < y2 ≤ 31400`

---

### Output
Print `"YES"` if the rectangles form a square, otherwise `"NO"`.

---

## Examples

### Example 1
**Input:**
```

5
0 0 2 3
0 3 3 5
2 0 5 2
3 2 5 5
2 2 3 3

```
**Output:**
```

YES

```
These 5 rectangles tile a 5×5 square perfectly.

---

### Example 2
**Input:**
```

4
0 0 2 3
0 3 3 5
2 0 5 2
3 2 5 5

```
**Output:**
```

NO

```
The bounding box is 5×5, but the center region (the missing rectangle) leaves a hole, so the shape is not a full square.

---

## Idea / Approach

Since the rectangles do not overlap, the total area of the union equals the **sum of individual areas**.

Let:
- `minX, minY` = smallest coordinates among all rectangles (bottom-left of bounding box)
- `maxX, maxY` = largest coordinates among all rectangles (top-right of bounding box)

The union forms a square **if and only if**:
1. The bounding box is a square: `(maxX - minX) == (maxY - minY)`
2. There are no holes: `totalArea == (maxX - minX) * (maxY - minY)`

If both conditions hold, the union fills the entire bounding box, which is a square.

---

## Pseudocode

```

read n
minX = minY = +infinity
maxX = maxY = -infinity
totalArea = 0

for each rectangle (x1, y1, x2, y2):
	minX = min(minX, x1)
	minY = min(minY, y1)
	maxX = max(maxX, x2)
	maxY = max(maxY, y2)
	totalArea += (x2 - x1) * (y2 - y1)

width  = maxX - minX
height = maxY - minY

if width != height:
	print "NO"
else if totalArea != width * height:
	print "NO"
else:
	print "YES"

```

---

## Complexity
- **Time:** O(n)
- **Space:** O(1)

---