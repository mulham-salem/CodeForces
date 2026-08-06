# Problem 227A - Where do I Turn?

## Idea

The hero is currently standing at point **B** after traveling from **A** to **B**, so his current direction is the vector:

$$
\overrightarrow{AB}
$$

He now wants to continue toward point **C**, whose direction is given by:

$$
\overrightarrow{BC}
$$

The problem guarantees that only one of the following situations can happen:

- The hero continues straight.
- The hero turns **90° left**.
- The hero turns **90° right**.

Therefore, we only need to determine the relative direction between the two vectors.

---

## Observation

Construct the two vectors:

$$
\overrightarrow{AB} = (x_B-x_A,\; y_B-y_A)
$$

$$
\overrightarrow{BC} = (x_C-x_B,\; y_C-y_B)
$$

To know whether the second vector is to the left or to the right of the first one, compute their **2D Cross Product**.

---

## Cross Product

The cross product of two vectors is

$$
cross = AB_x \times BC_y - AB_y \times BC_x
$$

Its sign determines the answer:

- **cross > 0** → Turn **LEFT**
- **cross < 0** → Turn **RIGHT**
- **cross = 0** → Continue **TOWARDS**

The problem guarantees that these are the only possible cases.

---

## Algorithm

1. Read points **A**, **B**, and **C**.
2. Compute vector **AB**.
3. Compute vector **BC**.
4. Compute their cross product.
5. Print:
   - `"LEFT"` if the cross product is positive.
   - `"RIGHT"` if it is negative.
   - `"TOWARDS"` otherwise.

---

## Pseudocode

```text
Read A, B, C

AB = B - A
BC = C - B

cross = AB.x * BC.y - AB.y * BC.x

if cross > 0
    print "LEFT"
else if cross < 0
    print "RIGHT"
else
    print "TOWARDS"
```

---

## Correctness Proof

We compute the direction of the hero using vector **AB** and the desired direction using vector **BC**.

The sign of the 2D cross product indicates the rotation from **AB** to **BC**:

- If the cross product is positive, the rotation is counterclockwise, so the hero turns **LEFT**.
- If the cross product is negative, the rotation is clockwise, so the hero turns **RIGHT**.
- If the cross product is zero, both vectors are collinear, so the hero continues **TOWARDS**.

Thus, the algorithm always prints the correct direction.

---

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---