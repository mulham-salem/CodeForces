# Problem 33A – What is for dinner?

## Problem Summary

Valerie the shark has **n teeth** arranged in **m rows**.  
Each tooth belongs to a specific row and has a **residual viability `c`**, meaning it can be used to eat at most `c` crucians.

When Valerie eats **one crucian**, she uses **exactly one row of teeth**, and **all teeth in that row lose 1 viability**.

If the viability of **any tooth becomes negative**, Valerie must visit the dentist again, which she wants to avoid.

Valerie has **k crucians** available for dinner.

Your task is to determine the **maximum number of crucians Valerie can eat** without any tooth’s viability becoming negative.

---

## Key Observation

If a row is used `x` times:

- Every tooth in that row loses `x` viability.
- Therefore, `x` cannot exceed the **smallest viability** among the teeth in that row.

So for each row:

```
maximum_usage_of_row = minimum_viability_in_that_row
```

The total number of crucians Valerie can eat is the **sum of these limits for all rows**.

However, she also **cannot eat more than `k` crucians**, since that is the amount available.

Therefore:

```
answer = min(k, sum_of_row_limits)
```

---

## Example

### Input

```
4 3 18
2 3
1 2
3 6
2 3
```

### Interpretation

- `n = 4` teeth
- `m = 3` rows
- `k = 18` crucians

Each line describes a tooth:

| Tooth | Row | Viability |
|------|-----|-----------|
| 1 | 2 | 3 |
| 2 | 1 | 2 |
| 3 | 3 | 6 |
| 4 | 2 | 3 |

### Grouping by rows

Row 1:
```
[2]
```
Minimum = **2**

Row 2:
```
[3, 3]
```
Minimum = **3**

Row 3:
```
[6]
```
Minimum = **6**

### Total possible usage

```
2 + 3 + 6 = 11
```

Since `k = 18`:

```
answer = min(18, 11) = 11
```

So Valerie can eat **11 crucians**.

---

## Algorithm

1. Read `n`, `m`, and `k`.
2. Track the **minimum viability for each row**.
3. For every tooth:
   - Update the minimum viability of its row.
4. Sum the minimum values of all rows.
5. The result is:

```
min(k, sum_of_row_minimums)
```

---

## Pseudocode

```
read n, m, k

create array rowMin of size m
initialize all values to a very large number

for i from 1 to n:
    read r, c
    rowMin[r] = min(rowMin[r], c)

sum = 0

for each row from 1 to m:
    sum += rowMin[row]

answer = min(sum, k)

print answer
```

---

## Time Complexity

```
O(n + m)
```

- We process each tooth once.
- Then sum the rows once.

This easily satisfies the constraints (`n ≤ 1000`).
