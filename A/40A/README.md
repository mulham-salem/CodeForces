# Problem 40A – Find Color

## Problem Summary
The magic clock of Berland can be represented as an infinite Cartesian plane with the origin **(0,0)** as its center.  
The plane is colored in alternating **black** and **white** circular regions around the origin.

These regions are separated by circles whose radii are integers:

- Radius = 1
- Radius = 2
- Radius = 3
- ...

Important rules:

- **All points whose distance from the origin is an integer are colored black.**
- Other points lie **between two circles** and their color depends on:
  - The **ring number** (distance from the origin)
  - The **quadrant** where the point lies

Your task is to determine the color (**black** or **white**) of the region that contains the given point.

---

## Key Idea

1. Compute the squared distance from the origin:

```
d² = x² + y²
```

2. If the distance from the origin is an **integer**, the point lies exactly on a circle border.

➡ Border points are always **black**.

3. Otherwise:
   - Determine the **ring index** using `floor(sqrt(d²))`
   - Determine in which **quadrant** the point lies
   - The color alternates depending on the **ring parity** and the **quadrant**

---

## Examples

### Example 1

Input

```
-2 1
```

Distance:

√((-2)² + 1²) = √5 ≈ 2.23

- Not an integer distance → not on a border
- Ring index = `floor(2.23) = 2`
- The point lies in **Quadrant II**

Result:

```
white
```

---

### Example 2

Input

```
2 1
```

Distance:

√(2² + 1²) = √5 ≈ 2.23

- Ring index = `2`
- The point lies in **Quadrant I**

Result:

```
black
```

---

### Example 3

Input

```
4 3
```

Distance:

√(4² + 3²) = √25 = 5

The distance is an **integer**, meaning the point lies on a circle boundary.

Result:

```
black
```

---

## Pseudocode

```
read x, y

distSq = xx + yy r = floor(sqrt(distSq))

if r*r == distSq print "black" stop

if x*y > 0 if r is even print "black" else print "white"

else if x*y < 0 if r is even print "white" else print "black"

else print "black"
```

---

## Complexity


Time Complexity:

```
O(1)
```

Only a few arithmetic operations are required.

---
