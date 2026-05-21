# Problem 121A – Lucky Sum

## Overview

A **lucky number** is a positive integer that contains only the digits:

- `4`
- `7`

Examples:

```text
4
7
44
47
74
77
```

For every number `x`:

```text
next(x) = the smallest lucky number greater than or equal to x
```

The task is to calculate:

```text
next(l) + next(l + 1) + ... + next(r)
```

---

## Example

### Input

```text
2 7
```

### Explanation

| x | next(x) |
|---|---|
| 2 | 4 |
| 3 | 4 |
| 4 | 4 |
| 5 | 7 |
| 6 | 7 |
| 7 | 7 |

### Sum

```text
4 + 4 + 4 + 7 + 7 + 7 = 33
```

---

## Key Observation

Many consecutive numbers share the same `next(x)` value.

Example:

| Range | next(x) |
|---|---|
| 2 → 4 | 4 |
| 5 → 7 | 7 |
| 8 → 44 | 44 |

Instead of processing numbers one by one, we process whole ranges together.

---

## Idea

1. Generate all lucky numbers.
2. Sort them.
3. For each lucky number:
   - determine how many values use it as `next(x)`
   - add its contribution directly to the answer.

This makes the solution efficient.

---

## Pseudocode

```text
generate all lucky numbers
sort lucky numbers

current = l
sum = 0

for each lucky number x:

    if x < current:
        continue

    end = min(r, x)

    count = end - current + 1

    sum += count * x

    current = end + 1

    if current > r:
        break

print sum
```

---

## Complexity

| Operation | Complexity |
|---|---|
| Generate lucky numbers | Small (~2000 numbers) |
| Main loop | O(number of lucky numbers) |

Efficient enough for:

```text
1 ≤ l ≤ r ≤ 10^9
```

---