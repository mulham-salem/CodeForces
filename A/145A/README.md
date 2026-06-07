# Problem 145A – Lucky Conversion

## Overview

You are given two strings `a` and `b` of equal length, consisting only of the lucky digits `4` and `7`.

You can perform two types of operations on string `a`:

1. Replace a digit with its opposite (`4 ↔ 7`).
2. Swap any two digits.

The task is to find the minimum number of operations required to transform `a` into `b`.

---

## Key Idea

There are only two possible mismatch types:

- `4` in `a` and `7` in `b`
- `7` in `a` and `4` in `b`

A single swap can fix one mismatch of each type simultaneously.

Therefore:

- Use as many swaps as possible.
- Any remaining unmatched positions must be fixed using replacements.

The answer becomes the larger count among the two mismatch types.

---

## Example 1

### Input

```text
47
74
```

### Explanation

Mismatches:

```text
4 → 7
7 → 4
```

One swap fixes both positions.

### Output

```text
1
```

---

## Example 2

### Input

```text
774
744
```

### Explanation

Only one position differs:

```text
7 → 4
```

One replacement is enough.

### Output

```text
1
```

---

## Example 3

### Input

```text
777
444
```

### Explanation

All positions must be changed:

```text
7 → 4
7 → 4
7 → 4
```

Three replacements are required.

### Output

```text
3
```

---

## Pseudocode

```text
read a, b

count47 = 0
count74 = 0

for each position i:
    if a[i] = 4 and b[i] = 7:
        count47++

    else if a[i] = 7 and b[i] = 4:
        count74++

answer = max(count47, count74)

print answer
```

---

## Complexity Analysis

- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

---