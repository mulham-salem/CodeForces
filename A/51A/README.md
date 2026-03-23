# Problem 51A – Cheaterius's Problem

## Problem Description

Cheaterius, a famous astrologist and magician in Berland, makes amulets from glued domino pairs forming 2×2 squares. Each square contains numbers (dots) from 1 to 6.

Two amulets are considered similar if one can be rotated (90°, 180°, 270°) to match the other exactly. Flipping is not allowed.

Your task is to find the number of piles of similar amulets on Cheaterius' desk.

---

## Input

First line: integer n (1 ≤ n ≤ 1000) — number of amulets.

Next lines: description of each amulet in 2 lines (2 numbers per line).

A line containing "**" separates each pair of amulets.


### Example 1

```
4
31
23
**
31
23
**
13
32
**
32
13
```

## Output

Print a single integer: the number of piles (distinct amulet groups).


### Example 1

```
1
```

### Explanation

Each 2×2 amulet has 4 possible rotations.

All four amulets in the example are rotations of each other → only 1 pile.

---

### Example 2

```
4
51
26
**
54
35
**
25
61
**
45
53
```

Here, there are 2 distinct piles → output is 

```
2
```
---

## Pseudocode

```
initialize set S   // stores canonical forms of amulets

for each amulet:
    read 2x2 matrix

    generate all 4 rotations of the matrix
    convert each rotation to a string
    pick the smallest string (canonical form)
    insert canonical form into set S

answer = size of S
print answer
```

---

## Notes

Only one orientation of each amulet is provided in input; the program generates all rotations internally.

Using the canonical form ensures all rotations are recognized as the same amulet.

A set automatically filters duplicates → counts distinct piles.

---