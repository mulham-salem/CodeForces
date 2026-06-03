# Problem 135A – Replacement

## Overview
You are given an array of integers.  
You must replace **exactly one element** with another integer different from it, then sort the array in non-decreasing order.

The goal is to determine the minimum possible values of the array after the replacement and sorting.

---

## Key Idea
To make the array as small as possible after sorting:

- Replace the largest element with `1`.
- However, if all elements are already `1`, we must change one of them to `2` because replacing a number with itself is not allowed.

After the modification, sort the array again.

---

## Input
- The first line contains an integer `n` — the size of the array.
- The second line contains `n` integers.

### Constraints

| Constraint | Value |
|---|---|
| `1 ≤ n ≤ 10^5` | |
| `1 ≤ ai ≤ 10^9` | |

---

## Output
Print the resulting array after performing exactly one replacement and sorting it.

---

## Example 1

### Input
```text
5
2 3 4 5 6
```

### Output
```text
1 2 3 4 5
```

### Explanation
Replace `6` with `1`, then sort the array.

---

## Example 2

### Input
```text
5
1 2 3 4 5
```

### Output
```text
1 1 2 3 4
```

### Explanation
Replace the largest element `5` with `1`.

---

## Example 3

### Input
```text
3
1 1 1
```

### Output
```text
1 1 2
```

### Explanation
All elements are already `1`, so one of them must become `2`.

---

## Pseudocode

```text
read n
read array

sort array

if largest element == 1
    change last element to 2
else
    change last element to 1

sort array

print array
```

---

## Complexity Analysis

| Operation | Complexity |
|---|---|
| Sorting | `O(n log n)` |
| Final Output | `O(n)` |

Overall complexity: `O(n log n)`

---