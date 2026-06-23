# Problem 169A – Chores

## Overview

Petya and Vasya need to divide `n` chores based on an integer threshold `x`.

- Chores with complexity greater than `x` are assigned to **Petya**.
- Chores with complexity less than or equal to `x` are assigned to **Vasya**.

Petya must receive exactly `a` chores, and Vasya must receive exactly `b` chores (`a + b = n`).

Your task is to determine how many integer values of `x` satisfy this requirement.

---

## Input

- `n` — total number of chores.
- `a` — number of chores assigned to Petya.
- `b` — number of chores assigned to Vasya.
- Array `h` containing the complexity of each chore.

---

## Output

Print the number of valid integer values of `x`.

---

## Example 1

### Input

```text
5 2 3
6 2 3 100 1
```

### Output

```text
3
```

### Explanation

After sorting:

```text
1 2 3 6 100
```

The valid values of `x` are:

```text
3, 4, 5
```

---

## Example 2

### Input

```text
7 3 4
1 1 9 1 1 1 1
```

### Output

```text
0
```

### Explanation

No integer value of `x` can split the chores into exactly 4 for Vasya and 3 for Petya.

---

## Idea

Sort the array of complexities.

Since Vasya must receive exactly `b` chores, he gets the first `b` smallest values after sorting. The split occurs between:

- The last chore assigned to Vasya.
- The first chore assigned to Petya.

Count how many integer values can lie between these two boundary values.

---

## Pseudocode

```text
read n, a, b
read h

sort(h)

answer = h[b] - h[b - 1]

print answer
```

---

## Complexity Analysis

| Complexity | Value |
|------------|--------|
| Time | O(n log n) |
| Memory | O(1) extra |

---