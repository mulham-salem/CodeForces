# Problem 301A – Yaroslav and Sequence

## Problem Statement

Yaroslav has an array of `2·n - 1` integers. In one operation, he can change the sign of **exactly n** elements (multiply each by `-1`).

What is the **maximum possible sum** of the array after performing any number of operations?

---

### Input
- First line: integer `n` `(2 ≤ n ≤ 100)`
- Second line: `2·n - 1` integers (absolute value ≤ 1000)

---

### Output
- A single integer — the maximum achievable sum.

---

## Examples

### Example 1
```

Input:
2
50 50 50

Output:
150

```

---

### Example 2
```

Input:
2
-1 -100 -1

Output:
100

```

---

## Key Insight

Let:
- `sum` = sum of absolute values of all elements
- `neg` = count of negative elements
- `minAbs` = minimum absolute value among all elements

The answer depends on **two parities**: `n` and `neg`.

| Condition | Answer | Why |
|-----------|--------|-----|
| `n` is odd | `sum` | Any sign configuration is reachable |
| `n` is even AND `neg` is even | `sum` | All elements can be made positive |
| `n` is even AND `neg` is odd | `sum - 2 * minAbs` | One negative element is forced; pick the smallest |

---

## Explanation of the Three Cases

### Case 1: `n` is odd
Each operation flips **n** elements (odd count). The total array size is `2n - 1`, also odd. Over GF(2), the operation matrix is invertible, so **any** sign pattern can be reached — including all-positive.

### Case 2: `n` is even, `neg` is even
Each operation flips an **even** number of elements, so the parity of `neg` is **invariant**. Since `neg` starts even, we can drive it to `0` → all positive.

### Case 3: `n` is even, `neg` is odd
Parity of `neg` is invariant and starts odd, so **at least one negative** must remain. To minimize loss, make the element with the **smallest absolute value** the leftover negative.

Loss = `minAbs` (instead of `+minAbs`) → subtract `2 * minAbs`.

---

## Pseudocode

```

READ n
size ← 2 * n - 1

sum        ← 0
negCount   ← 0
minAbs     ← +∞

FOR i FROM 1 TO size:
	READ x
	sum      ← sum + ABS(x)
	minAbs   ← MIN(minAbs, ABS(x))
	IF x < 0:
		negCount ← negCount + 1

IF n MOD 2 == 1:
	PRINT sum
ELSE IF negCount MOD 2 == 0:
	PRINT sum
ELSE:
	PRINT sum - 2 * minAbs

```

---

## Complexity

- **Time:** `O(n)` — single pass over the array
- **Memory:** `O(1)` — only counters and running sum

---