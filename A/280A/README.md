# Problem 280A – Rectangle Puzzle

## Problem Description

You are given two rectangles on a plane. Both rectangles have their centers at the origin `(0, 0)`. 

- The **first rectangle** has sides parallel to the coordinate axes:
  - Width (parallel to Ox axis) = `w`
  - Height (parallel to Oy axis) = `h`

- The **second rectangle** is obtained by rotating the first rectangle by an angle `α` (in degrees) around the origin.

Your task is to find the **area of the intersection** (the region that belongs to both rectangles).

### Input
- Three integers `w, h, α` where:
  - `1 ≤ w, h ≤ 10^6`
  - `0 ≤ α ≤ 180`

### Output
- A single real number — the area of the intersection.
- The answer is considered correct if absolute or relative error ≤ `10^-6`.

---

## Examples

### Example 1
**Input:**
```

1 1 45

```
**Output:**
```

0.828427125

```

---

### Example 2
**Input:**
```

6 4 30

```
**Output:**
```

19.668384925

```

---

## Solution Approach

### Key Insight
The intersection of two rectangles (both centered at the origin) forms a convex polygon. Instead of deriving complex mathematical formulas for different angle cases, we can use **polygon clipping** to compute the intersection area directly.

### Algorithm Overview

1. **Represent both rectangles as polygons** (lists of vertices in clockwise or counterclockwise order).

2. **Generate the rotated rectangle**:
   - Start with the vertices of the axis-aligned rectangle.
   - Apply a 2D rotation matrix by angle `α` around the origin:
     ```
     x' = x * cos(α) - y * sin(α)
     y' = x * sin(α) + y * cos(α)
     ```

3. **Clip the first rectangle against the second** using the **Sutherland-Hodgman algorithm**:
   - For each edge of the clipping polygon (the rotated rectangle), keep only the points that lie on the "inside" side of that edge.
   - When an edge crosses the clipping boundary, add the intersection point.

4. **Calculate the area** of the resulting clipped polygon using the **shoelace formula**:
```

Area = 0.5 * |Σ(xi * yi+1 - xi+1 * yi)|

```

### Why This Works
- The intersection of two convex polygons is always a convex polygon.
- Sutherland-Hodgman reliably computes this intersection in O(n·m) time, where n and m are the number of vertices (4 each in our case).
- This approach handles all cases (small angles, large angles, and edge cases like `α = 0°` or `α = 90°`) without special-case logic.

---

## Pseudocode

```

function polygon_area(polygon):
	area = 0
	for i from 0 to polygon.size() - 1:
	j = (i + 1) % polygon.size()
	area += polygon[i].x * polygon[j].y
	area -= polygon[j].x * polygon[i].y
	return abs(area) / 2

function intersect_lines(p1, p2, p3, p4):
	// Find intersection point of line segments p1-p2 and p3-p4
	d = (p2.x - p1.x) * (p4.y - p3.y) - (p2.y - p1.y) * (p4.x - p3.x)
	if abs(d) < epsilon:
	return no_intersection
	t = ((p3.x - p1.x) * (p4.y - p3.y) - (p3.y - p1.y) * (p4.x - p3.x)) / d
	return {p1.x + t * (p2.x - p1.x), p1.y + t * (p2.y - p1.y)}

function clip_polygon(polygon, clip_edge_start, clip_edge_end):
	new_polygon = []
	for each edge (current, next) in polygon:
	cross_current = cross_product(clip_edge, current - clip_edge_start)
	cross_next = cross_product(clip_edge, next - clip_edge_start)

    if cross_current >= 0:
        add current to new_polygon
    if (cross_current > 0 and cross_next < 0) or (cross_current < 0 and cross_next > 0):
        add intersection_point of (current, next) and (clip_edge_start, clip_edge_end) to new_polygon

	return new_polygon

function main():
	read w, h, alpha
	alpha = alpha * PI / 180
	// Define axis-aligned rectangle vertices
	rect1 = [(-w/2, -h/2), (w/2, -h/2), (w/2, h/2), (-w/2, h/2)]

	// Create rotated rectangle by applying rotation to rect1
	rect2 = []
	for each point p in rect1:
		x = p.x * cos(alpha) - p.y * sin(alpha)
		y = p.x * sin(alpha) + p.y * cos(alpha)
		rect2.add({x, y})

	// Clip rect1 by rect2 using Sutherland-Hodgman
	polygon = rect1
	for each edge in rect2 (from edge to next_edge):
		polygon = clip_polygon(polygon, edge, next_edge)

	// Compute and print area
	area = polygon_area(polygon)
	print area with 12 decimal places

```

---

## Complexity Analysis

- **Time Complexity**: O(1) — we clip a 4-vertex polygon against another 4-vertex polygon, resulting in at most 8 vertices.
- **Space Complexity**: O(1) — only a few polygon vertices are stored.

---

## Note on Edge Cases

- **α = 0°**: The rectangles overlap completely → answer = `w * h`.
- **α = 90°** (or 180°): The rectangles are perpendicular → answer = `h²` (assuming w ≥ h).
- **α > 90°**: Since rotation is symmetric, reduce α to its acute equivalent (`α = 180° - α`).
- Floating point precision: Use `double` with `eps = 1e-10` for robust geometric comparisons.

---

## References

- [Sutherland-Hodgman Polygon Clipping Algorithm](https://en.wikipedia.org/wiki/Sutherland%E2%80%93Hodgman_algorithm)
- [Shoelace Formula for Polygon Area](https://en.wikipedia.org/wiki/Shoelace_formula)

---