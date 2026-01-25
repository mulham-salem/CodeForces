# Problem 350A – TL

## Problem Summary
Valera wants to set a **Time Limit (TL)** for a programming problem.

He has:
- `n` correct solutions with running times `a1, a2, ..., an`
- `m` wrong solutions with running times `b1, b2, ..., bm`

A solution:
- **passes** if its time `≤ v`
- **passes with extra time** if `2 × time ≤ v`

We must find the **minimum positive integer `v`** such that:

1. `v` is a positive integer  
2. **All correct solutions pass**
3. **At least one correct solution passes with extra time**
4. **All wrong solutions fail**
5. `v` is minimal among all valid values

If no such `v` exists, output `-1`.

---

## Key Observations

### 1. All correct solutions must pass
The time limit must be at least the slowest correct solution:
```

v ≥ max(ai)

```

---

### 2. At least one correct solution must pass with extra time
The easiest candidate is the fastest correct solution:
```

v ≥ 2 × min(ai)

```

---

### 3. All wrong solutions must fail
The time limit must be strictly smaller than the fastest wrong solution:
```

v < min(bi)

```

---

## Valid Range for `v`

Combining all constraints:
```

max(max(ai), 2 × min(ai)) ≤ v < min(bi)

```

Let:
```

L = max(max(ai), 2 × min(ai))
R = min(bi) - 1

```

- If `L ≤ R`, the answer is `L` (minimum valid TL)
- Otherwise, no valid TL exists → output `-1`

---

## Example 1

**Input**
```

Correct: [4, 5, 2]
Wrong:   [8, 9, 6, 10]

```

**Computation**
```

max(ai) = 5
min(ai) = 2  →  2 × 2 = 4
min(bi) = 6

L = max(5, 4) = 5
R = 6 - 1 = 5

```

**Result**
```

v = 5

```

---

## Example 2

**Input**
```

Correct: [3, 4, 5]
Wrong:   [6]

```

**Computation**
```

max(ai) = 5
min(ai) = 3  →  2 × 3 = 6
min(bi) = 6

L = 6
R = 5

```

**Result**
```

No valid v → -1

```

---

## Pseudocode

```

read n, m
read array A (correct solutions)
read array B (wrong solutions)

maxA = maximum value in A
minA = minimum value in A
minB = minimum value in B

L = max(maxA, 2 * minA)
R = minB - 1

if L <= R:
output L
else:
output -1

```

---

## Complexity
- Time Complexity: `O(n + m)`
- Space Complexity: `O(1)` (excluding input storage)

---

## Notes
- The problem is **constraint-based**, not brute force.
- `v` is **calculated directly**, never incremented or tested iteratively.
- If the valid range is empty, the answer is immediately `-1`.

---