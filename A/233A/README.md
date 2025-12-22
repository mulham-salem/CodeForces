# Problem 233A – Perfect Permutation

## Requirement

You are given a single integer `n`, representing the size of a permutation.

A permutation `p1, p2, ..., pn` of numbers from `1` to `n` is called **perfect** if for every index `i` (1 ≤ i ≤ n):

- `p[p[i]] = i`
- `p[i] ≠ i`

**Goal:** Print **any perfect permutation** of size `n`.  
If no such permutation exists, print `-1`.

---

## Input

- One integer: `n`
  - `1 ≤ n ≤ 100`
  - `n` is the size of the permutation

---

## Output

- If a perfect permutation does not exist, print `-1`
- Otherwise, print `n` distinct integers `p1, p2, ..., pn`

---

## Examples

### Example 1

**Input**
```

1

```

**Output**
```

-1

```

**Explanation**
```

With only one element, it must stay in its position.
This violates p[i] ≠ i, so no perfect permutation exists.

```

---

### Example 2

**Input**
```

2

```

**Output**
```

2 1

```

**Explanation**
```

1 and 2 are swapped:
p[1] = 2 → p[2] = 1
Both conditions are satisfied.

```

---

### Example 3

**Input**
```

4

```

**Output**
```

2 1 4 3

```

**Explanation**
```

The permutation consists of swapped pairs:
(1 ↔ 2), (3 ↔ 4)

For each i:

* p[p[i]] = i
* p[i] ≠ i

```

---

## Solution Idea

1. The condition `p[p[i]] = i` means elements must work in **pairs**.
2. The condition `p[i] ≠ i` means no element can stay in its original position.
3. Therefore, the permutation must consist only of **swapped pairs (cycles of length 2)**.
4. If `n` is **odd**, one element will remain unpaired → no solution.
5. If `n` is **even**, swap every two consecutive numbers.

---

## Construction Rule

For even `n`, build the permutation as:

```

(1 ↔ 2), (3 ↔ 4), (5 ↔ 6), ...

```

---

## Complexity

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---
