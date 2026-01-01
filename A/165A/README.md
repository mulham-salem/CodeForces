# Problem 165A – Supercentral Point

## Requirement
You are given:

- An integer **n** — the number of points.
- **n** points on a 2D plane, each defined by two integers **(x, y)**.

A point is called **Supercentral** if there exists:
- at least one point **to the left** of it (same y, smaller x)
- at least one point **to the right** of it (same y, larger x)
- at least one point **above** it (same x, larger y)
- at least one point **below** it (same x, smaller y)

Your task is to count how many points are **Supercentral**.

---

## Input
- Integer **n**
- Next **n** lines: two integers **x y** representing a point

---

## Output
- One integer — the number of Supercentral points

---

## Examples

### Example 1
**Input**
```

5
0 0
1 0
-1 0
0 1
0 -1

```

**Output**
```

1

```

**Explanation**

For point **(0, 0)**:
- Left  → (-1, 0)
- Right → (1, 0)
- Up    → (0, 1)
- Down  → (0, -1)

All four directions exist → **Supercentral**

No other point satisfies all four conditions.

---

### Example 2
**Input**
```

4
0 0
1 0
0 1
0 -1

```

**Output**
```

0

```

**Explanation**

Point **(0, 0)**:
- Right → (1, 0)
- Up    → (0, 1)
- Down  → (0, -1)
- Left  → ❌ missing

So it is **not** Supercentral.

---

## Solution Idea
For each point:
1. Check all other points.
2. Determine whether there is:
   - a point on the same horizontal line to the left
   - a point on the same horizontal line to the right
   - a point on the same vertical line above
   - a point on the same vertical line below
3. If all four exist, count this point as Supercentral.

---

## Important Notes
- Distance between points does **not** matter.
- Points do **not** need to be adjacent.
- Only direction and alignment on the same axis matter.

---

## Complexity
- **Time Complexity:** O(n²)
- **Space Complexity:** O(1)

---

## Key Insight
A point is Supercentral if and only if it is surrounded by other points from **all four cardinal directions** along the same axes.

