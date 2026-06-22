# Problem 168A – Wizards and Demonstration

## Overview

A city has `n` citizens, and `x` of them are wizards who will definitely attend a demonstration.

The city administration will only react if the number of participants is at least `y%` of the city's population. To increase attendance, the wizards can create clone puppets that are counted as participants.

Your task is to determine the **minimum number of clones** needed so that the demonstration reaches the required percentage.

---

## Input

Three integers:

- `n` — total number of citizens.
- `x` — number of wizards attending the demonstration.
- `y` — required percentage of the population.

---

## Output

Print a single integer — the minimum number of clones that must be created.

---

## Example 1

### Input

```text
10 1 14
```

### Output

```text
1
```

### Explanation

At least `14%` of `10` citizens are needed:

```text
14% of 10 = 1.4
```

Since participants must be an integer, at least `2` participants are required.

There is already `1` wizard attending, so `1` clone is needed.

---

## Example 2

### Input

```text
20 10 50
```

### Output

```text
0
```

### Explanation

`50%` of `20` is `10`.

The city already has `10` wizards attending, so no clones are required.

---

## Example 3

### Input

```text
1000 352 146
```

### Output

```text
1108
```

### Explanation

The demonstration must contain at least `1460` participants.

Since only `352` wizards attend, the number of required clones is:

```text
1460 - 352 = 1108
```

---

## Idea

1. Calculate the minimum number of participants required to satisfy `y%` of `n`.
2. Compare it with the number of wizards already attending.
3. If the requirement is larger, create enough clones to cover the difference.
4. Otherwise, no clones are needed.

---

## Pseudocode

```text
read n, x, y

required = ceil(n * y / 100)

if required <= x
    print 0
else
    print required - x
```

---

## Complexity Analysis

- **Time Complexity:** `O(1)`
- **Space Complexity:** `O(1)`

---