# Problem 215A – Bicycle Chain

## Problem Summary
Vasya’s bicycle has:
- `n` front stars (pedal axle) with teeth counts `a1 < a2 < ... < an`
- `m` rear stars (wheel axle) with teeth counts `b1 < b2 < ... < bm`

For every pair `(i, j)`:
- A **gear ratio** is defined as:

```

ratio = b[j] / a[i]

```

Only gears with **integer ratios** are valid.

### Goal
Among all gears with integer ratios:
1. Find the **maximum gear ratio**
2. Count how many gears achieve this maximum ratio

---

## Key Observation
A gear ratio is an integer **if and only if**:

```

b[j] % a[i] == 0

```

Because:
```

ratio = b[j] / a[i]

```

---

## Solution Approach
- Try all possible pairs `(i, j)`
- For each pair:
  - Check if the ratio is an integer
  - Compute the ratio
  - Track the maximum ratio found
  - Count how many times this maximum ratio appears

Constraints are small (`n, m ≤ 50`), so a **brute-force** solution is sufficient.

---

## Example 1

```

a = [4, 5]
b = [12, 13, 15]

```

Valid integer ratios:

| a | b  | ratio |
|---|----|-------|
| 4 | 12 | 3 |
| 5 | 15 | 3 |

- Maximum ratio = `3`
- Number of gears with this ratio = `2`

**Output:**
```

2

```

---

## Example 2

```

a = [1, 2, 3, 4]
b = [10, 11, 12, 13, 14]

```

Valid integer ratios:

| a | b  | ratio |
|---|----|-------|
| 1 | 10 | 10 |
| 2 | 10 | 5 |
| 3 | 12 | 4 |
| 4 | 12 | 3 |

- Maximum ratio = `10`
- Appears once

**Output:**
```

1

```

---

## Algorithm
1. Initialize:
   - `maxRatio = 0`
   - `count = 0`
2. For each `a[i]` and `b[j]`:
   - If `b[j] % a[i] == 0`
     - `ratio = b[j] / a[i]`
     - Update `maxRatio` and `count`
3. Print `count`

---

## Complexity Analysis
- Time Complexity: **O(n × m)**
- Space Complexity: **O(1)**

---

## Final Notes
- The gear ratio is defined as `b[j] / a[i]` (rear over front)
- Only integer ratios are considered
- We only count gears with the **maximum** integer ratio