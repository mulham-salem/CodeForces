# Problem 201A – Clear Symmetry

## Problem Description

You are given an integer `x`. Your task is to find the smallest possible size `n` of a square matrix `n × n` that satisfies the following conditions:

- The matrix contains only `0` and `1`.
- The number of `1`s in the matrix is exactly `x` (called the sharpness).
- The matrix is **clear**:
  - No two cells containing `1` share a common side.
- The matrix is **symmetrical**:
  - It remains the same after horizontal reflection.
  - It remains the same after vertical reflection.

You need to output the minimum possible value of `n`.

---

## Key Observations

- Because of symmetry, cells containing `1` must appear in mirrored positions.
- The maximum number of `1`s that can be placed in an `n × n` matrix without touching each other follows a chessboard pattern.
- For odd `n`: 
$$ n = 2k + 1 $$

The maximum possible number of `1`s is:

$$ maxSharpness = k² + (k + 1)² $$

- We increase `n` until this maximum value becomes at least `x`.

---

## Special Case

For `x = 3`:

- A `3 × 3` matrix cannot contain exactly three `1`s while satisfying both:
  - symmetry
  - no adjacent `1`s

Therefore, the answer is:

`n = 5`

---

## Examples

### Example 1

**Input**
```
4
```
A possible matrix:

`1 0 1 0 0 0 1 0 1`

- Number of ones = `4`
- Symmetrical ✅
- No adjacent ones ✅

**Output**
```
3
```
---

### Example 2

**Input**
```
9
```
A `5 × 5` matrix can contain enough symmetric non-adjacent cells.

**Output**
```
5
```
---

## Algorithm

1. Read `x`.
2. If `x = 3`, print `5`.
3. Try odd values of `n` starting from `1`.
4. For each `n`:
   - Calculate `k = n / 2`.
   - Calculate the maximum possible sharpness:

$$ k² + (k + 1)² $$

5. If this value is greater than or equal to `x`, print `n`.

---

## Pseudocode
```
read x

if x == 3: print 5 stop

for n = 1, 3, 5, 7, ...

k = n / 2

maxSharpness = k² + (k + 1)²

if maxSharpness >= x:
    print n
    stop
```
---

## Complexity Analysis

Since `x ≤ 100`, only a few values of `n` are checked.

**Time Complexity:** `O(n)`

**Memory Complexity:** `O(1)`

---