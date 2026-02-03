# Problem 327A – Flipping Game

## Problem Description

Iahub writes `n` integers on paper, each being either `0` or `1`.
He is allowed to perform **exactly one move**:

- Choose two indices `i` and `j` (`1 ≤ i ≤ j ≤ n`)
- Flip all values in the range `[i, j]`
- Flipping means: `0 → 1` and `1 → 0`

The goal is to **maximize the number of `1`s** after exactly one flip.

---

## Input

- An integer `n` — the number of elements  
- A sequence of `n` integers (`0` or `1`)

```

n
a1 a2 ... an

```

---

## Output

- Print one integer — the **maximum number of `1`s** that can be obtained after exactly one move.

---

## Key Idea

- Flipping a `0` increases the number of `1`s by **+1**
- Flipping a `1` decreases the number of `1`s by **-1**

So instead of actually flipping, we **simulate the gain/loss** of flipping a segment.

### Transformation

| Original Value | Effect After Flip | Transformed Value |
|---------------|------------------|------------------|
| 0             | +1 one           | +1               |
| 1             | -1 one           | -1               |

After this transformation:
- Each subarray represents the **net gain** if we flip that segment
- The problem becomes finding the **maximum subarray sum**

---

## Approach

1. Count the number of `1`s in the original array.
2. Transform the array:
   - `0 → +1`
   - `1 → -1`
3. Find the **maximum sum of a contiguous subarray** (maximum gain).
4. Add this gain to the original count of `1`s.
5. Special case:
   - If all elements are `1`, any flip will reduce the number of `1`s by at least `1`.

---

## Examples

### Example 1

```

Input:
5
1 0 0 1 0

```

- Original number of `1`s = 2  
- Transformed array: `-1 +1 +1 -1 +1`  
- Maximum subarray sum = 2  

**Result:** `2 + 2 = 4`

---

### Example 2

```

Input:
4
1 1 1 1

```

- Original number of `1`s = 4  
- Any flip reduces the count  

**Result:** `3`

---

## Pseudocode

```

read n
read array

count_ones = number of 1s in array

transform array:
if value == 0 → +1
if value == 1 → -1

current_sum = 0
best_sum = 0

for each value in transformed array:
current_sum = max(value, current_sum + value)
best_sum = max(best_sum, current_sum)

if best_sum == 0:
result = count_ones - 1
else:
result = count_ones + best_sum

print result

```

---

## Notes

- Exactly **one flip is mandatory**
- The maximum subarray sum represents the **best possible flip**
- Time complexity is linear: **O(n)**

---

## Takeaway

This problem is a classic example of converting a problem into a
**maximum subarray sum** problem by modeling gains and losses.