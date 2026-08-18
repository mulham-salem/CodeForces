# Problem 249A – Robo-Footballer

## Problem

Robo-Wallace wants to score a goal by making the ball bounce **exactly once** from the right wall and then go directly into the opponent's goal.

The ball has radius `r`, so it must not touch the goal posts or any other wall.

The robot can only kick the ball toward the wall at:

```text
y = yw
```
The ball starts at:
```
(xb, yb)
```
The opponent's goal is on the `OY` axis `(x = 0)` and extends from:
```
y = y1
```
to:
```
y = y2
```
We need to find the x-coordinate xw of a point on the wall where the robot should kick the ball.

If no valid trajectory exists, print `-1`.

---

## Key Idea

The real trajectory is:

`Ball → Wall → Goal`

Using the reflection principle, we can transform the problem into a straight-line trajectory:

`Reflected Ball → Goal`

The wall is no longer part of this imaginary trajectory. It is only used as a reference line where we find the intersection point.

**1. Account for the Ball Radius**

Because the ball has radius r, we move the effective wall inward:
```
yw -= r
```
Similarly, the center of the ball must enter the goal at least r away from the lower goal post:
```
y1 += r
```
So the ball can be treated as a point while still respecting its radius.

**2. Reflect the Ball**

If the effective wall is at y = yw, the ball at yb is reflected to:
```
yb = 2 * yw - yb
```
For example, if:
```
yw = 12
yb = 3
```
the reflected position is:
```
2 * 12 - 3 = 21
```
Now we can imagine a straight line from the reflected ball to the safe point of the goal.

**3. Find the Aiming Point**

The line connects:
```
(xb, yb)
```
to:
```
(0, y1)
```
We need to find where this line reaches:
```
y = yw
```
The required x-coordinate is:
```
xw = xb * (yw - y1) / (yb - y1)
```
This gives the point:
```
(xw, yw)
```
which corresponds to the actual point where the ball hits the wall.

The formula comes from the fact that a straight line changes its x and y coordinates proportionally.

If the total vertical change is:
```
yb - y1
```
and we only move vertically:
```
yw - y1
```
then the fraction of the horizontal distance traveled is:
```
(yw - y1) / (yb - y1)
```
The total horizontal distance is xb, therefore:
```
xw = xb * (yw - y1) / (yb - y1)
```

---

## Checking the Upper Goal Post

Choosing the lower safe point of the goal does not automatically guarantee a valid trajectory.

The line could still pass too close to the upper goal post.

The upper post is:
```
(0, y2)
```
We calculate the shortest distance between this point and the line connecting:
```
(xb, yb)
```
and:
```
(0, y1)
```
The code calculates the squared distance:
```
dist2
```
Instead of calculating:
```
distance
```
we compare squares:
```
dist2 >= r²
```
This is equivalent to:
```
distance >= r
```
If this condition is satisfied, the ball does not touch the upper goal post.

A small EPS value is used to handle floating-point precision errors.

---

## Algorithm

1. Read `y1`, `y2`, `yw`, `xb`, `yb`, and `r`.


2. Move the effective wall inward by `r`:
```
yw -= r
```

3. Reflect the ball across the effective wall:
```
yb = 2 * yw - yb
```

4. Move the lower safe goal position inward by `r`:
```
y1 += r
```

5. Calculate the aiming coordinate:
```
xw = xb * (yw - y1) / (yb - y1)
```

6. Calculate the squared distance from the trajectory line to the upper goal post.


7. If the distance is at least r, output xw.


8. Otherwise, output `-1`.

---

## Input

The input contains six integers:
```
y1 y2 yw xb yb r
```

Where:

| Variable | Meaning |
|----------|---------|
| `y1` | y-coordinate of the lower goal post |
| `y2` | y-coordinate of the upper goal post |
| `yw` | y-coordinate of the wall the robot can aim at |
| `xb` | x-coordinate of the ball |
| `yb` | y-coordinate of the ball |
| `r` | radius of the ball |


## Constraints:

`1 ≤ y1 < y2 < yw ≤ 10⁶`
`1 ≤ xb, yb, r ≤ 10⁶`
`yb + r < yw`
`2r < y2 - y1`

---

## Output

If a valid trajectory exists, print:
```
xw
```
the x-coordinate of the point on the wall where the robot should aim.

The answer is accepted with an absolute error of at most:
```
10⁻⁸
```
If no valid trajectory exists, print:
```
-1
```

---

## Examples

### Example 1

### Input:
```
4 10 13 10 3 1
```
One possible valid answer is:
```
4.3750000000
```
The ball can be aimed at a point with `x = 4.375` on the right wall, bounce once, and then enter the goal without touching the posts.

There can be multiple valid answers.

---

### Example 2

### Input:
```
1 4 6 2 2 1
```
### Output:
```
-1
```
There is no valid trajectory that satisfies all the conditions.

---

### Example 3

### Input:
```
3 10 15 17 9 2
```
One possible valid answer is:
```
11.3333333333
```
Again, other valid aiming points may also exist.

---

## Complexity

The solution uses only a constant number of calculations.

**Time Complexity:**  `O(1)`
**Space Complexity:** `O(1)`

---

## Summary

The main trick is the reflection principle.

Instead of dealing with:
```
Ball → Wall → Goal
```
we reflect the ball and work with:
```
Reflected Ball → Goal
```
This creates one straight line.

We then find where this line crosses the effective wall:
```
(xw, yw)
```
Finally, we check that the trajectory stays at least r away from the upper goal post.

If it does, `xw` is a valid answer; otherwise, the answer is `-1`.

---