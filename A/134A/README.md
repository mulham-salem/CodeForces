# Problem 134A – Average Numbers

## Overview

You are given an array of positive integers.  
Your task is to find all indices where the current element is equal to the arithmetic mean of all other elements in the array.

The indices are **1-based**.

---

## Idea

For each element:

1. Remove it from the total sum.
2. Compute the sum of the remaining elements.
3. Check whether the current value equals their average.

Instead of recalculating the sum every time, we calculate the total sum once.

### Formula

```text
current_element = (total_sum - current_element) / (n - 1)
```

To avoid floating-point operations:

```text
current_element * (n - 1) = total_sum - current_element
```

---

## Example 1

### Input

```text
5
1 2 3 4 5
```

### Explanation

Total sum:

```text
15
```

Check element `3`:

Remaining sum:

```text
15 - 3 = 12
```

Average of remaining elements:

```text
12 / 4 = 3
```

Since the average equals the current element, index `3` is valid.

### Output

```text
1
3
```

---

## Example 2

### Input

```text
4
50 50 50 50
```

### Explanation

After removing any element:

```text
50 50 50
```

Average:

```text
150 / 3 = 50
```

So every index is valid.

### Output

```text
4
1 2 3 4
```

---

## Pseudocode

```text
read n
read array

totalSum = sum of all elements

for each index i:
    remaining = totalSum - a[i]

    if a[i] * (n - 1) == remaining:
        save index (i + 1)

print number of valid indices
print valid indices
```

---

## Complexity

| Type | Complexity |
|------|------------|
| Time | O(n) |
| Space | O(n) |

---