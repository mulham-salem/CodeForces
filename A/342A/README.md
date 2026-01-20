# Problem 342A – Xenia and Divisors

## Problem Description

Xenia has a sequence of `n` positive integers, where `n` is divisible by 3 and every number is between `1` and `7`.
She wants to split the sequence into exactly `n / 3` groups, each group containing **three numbers** `(a, b, c)` such that:

- `a < b < c`
- `a` divides `b`
- `b` divides `c`
- Every element is used **exactly once**

If such a partition is possible, print the groups.
Otherwise, print `-1`.

---

## Key Observation

Because all numbers are in the range `1..7`, there are **only a few valid triplets** that can satisfy the conditions.

The **only possible valid groups** are:

- `(1, 2, 4)`
- `(1, 2, 6)`
- `(1, 3, 6)`

Any other combination violates either the order or divisibility rules.

---

## Strategy

1. Count how many times each number from `1` to `7` appears.
2. Build groups using only the valid triplets.
3. Always form the **most restrictive groups first** to avoid blocking numbers that have fewer options.
4. After forming all possible groups, check if the total number of groups equals `n / 3`.

If not, the answer is `-1`.

---

## When Is the Answer `-1`?

- If at least one number cannot be placed into any valid group.
- If after forming all possible groups, some numbers remain unused.
- If the total number of formed groups is **not equal to `n / 3`**.

This condition comes directly from the requirement that **every element must belong to exactly one group of three**.

---

## Examples

### Example 1 (Impossible)

**Input**
```

6
1 1 1 2 2 2

```

**Explanation**
- There is no `4`, `6`, or `3`
- No valid triplet can be formed

**Output**
```

-1

```

---

### Example 2 (Possible)

**Input**
```

6
2 2 1 1 4 6

```

**Explanation**
- Possible groups:
  - `(1, 2, 4)`
  - `(1, 2, 6)`
- Total groups = `2 = n / 3`

**Output**
```

1 2 4
1 2 6

````

---

## Pseudocode

```pseudo
read n
read the n numbers

count occurrences of each number from 1 to 7

result = empty list of groups

# Step 1: form (1, 3, 6)
g = min(count[1], count[3], count[6])
add g copies of (1, 3, 6) to result
decrease count[1], count[3], count[6] by g

# Step 2: form (1, 2, 4)
g = min(count[1], count[2], count[4])
add g copies of (1, 2, 4) to result
decrease count[1], count[2], count[4] by g

# Step 3: form (1, 2, 6)
g = min(count[1], count[2], count[6])
add g copies of (1, 2, 6) to result
decrease count[1], count[2], count[6] by g

if size(result) != n / 3:
    print -1
else:
    print all groups in result
````

---

## Final Insight

This problem is **not about brute force**.
It relies on recognizing that:

* The value range is very small.
* Valid combinations are extremely limited.
* Correct grouping order is crucial.

Once these insights are clear, the implementation becomes straightforward.