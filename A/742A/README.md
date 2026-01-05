# Problem 742A – Arpa and a research in Mexican wave

## Problem Summary
Arpa is researching a mathematical pattern.
He is given a number n and needs to compute:

The last digit of the number:
1378^n

Your task:

Determine the last digit of 1378 raised to the power n.

---

## Key Idea
The last digit of powers of 1378 follows a repeating cycle.

Powers of 1378:
1378^1 → last digit = 8
1378^2 → last digit = 4
1378^3 → last digit = 2
1378^4 → last digit = 6

The pattern repeats every 4 powers:
8, 4, 2, 6

Special case:
If n = 0, the result is 1.

---

## Example 1

Input
1

Explanation
1378^1 ends with 8.

Output
8

---

## Example 2

Input
2

Explanation
1378^2 ends with 4.

Output
4

---

## Example 3

Input
0

Explanation
Any number to the power 0 equals 1.

Output
1

---

## Pseudocode
read n

if n == 0:
    print 1
else:
    cycle = [8, 4, 2, 6]
    index = (n - 1) mod 4
    print cycle[index]

---

## Final Notes
The cycle length is 4.
Time complexity is O(1).
No large numbers are needed.
Works for very large values of n.