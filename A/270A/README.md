# Problem 270A – Fancy Fence

## Problem Statement

Emuskald wants to build a fence around his farm in the shape of a **regular polygon**. He has a fence-building robot that can only create corners at a **single fixed angle** `a` (measured in degrees).

The question is: **Can the robot build the desired fence?**  
In other words, does there exist a regular polygon whose **interior angle** equals exactly `a`?

---

## Input

- The first line contains an integer `t` (`0 < t < 180`) — the number of test cases.
- Each of the next `t` lines contains a single integer `a` (`0 < a < 180`) — the angle the robot can make.

---

## Output

For each test case, print:
- `"YES"` if there exists a regular polygon with interior angle `a`.
- `"NO"` otherwise.

---

## Examples

| Input | Output |
|-------|--------|
| 3     |        |
| 30    | NO     |
| 60    | YES    |
| 90    | YES    |

**Explanation:**
- `30°` → No regular polygon has this interior angle.
- `60°` → Equilateral triangle (3 sides).
- `90°` → Square (4 sides).

---

## Key Formula

For a regular polygon with `n` sides (`n ≥ 3`), the interior angle is:

$$
\text{angle} = \frac{(n-2) \times 180}{n}
$$

Rearranging to solve for `n`:

$$
n = \frac{360}{180 - a}
$$

For the polygon to exist:
- `n` must be an **integer** (since you can't have a fraction of a side).
- `n` will automatically be `≥ 3` for any `0 < a < 180`.

---

## Solution Approach (Pseudo-code)

```

Read t
For each test case:
Read a
If 360 is divisible by (180 - a):
Print "YES"
Else:
Print "NO"

```

---

## Complexity

- **Time:** `O(t)` per test case.
- **Space:** `O(1)`.

---

## Note

The problem only cares about **interior angles** (the angles inside the polygon), not exterior angles.

---