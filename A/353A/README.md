# Problem 353A – Domino

## Problem Summary

You have `n` domino pieces. Each domino has two numbers (top and bottom), both between 1 and 6.

You want the **sum of all top halves** and the **sum of all bottom halves** to both be **even**.

You may rotate any domino (swap its top and bottom), and each rotation costs **1 second**. Find the minimum number of rotations needed, or `-1` if it's impossible.

---

## Key Observation

- If both sums are already even → answer is `0`.
- If both sums are odd → you can fix it by rotating **one** domino whose halves have **different parity** (i.e., one even, one odd). Such a swap changes both sums' parity. If no such domino exists → `-1`.
- If one sum is even and the other is odd → impossible, because rotating a domino always flips the parity of **both** sums together, so they can never become both even. → `-1`.

---

## Examples

**Example 1**
```

2
4 2
6 4

```
Top sum = 10 (even), bottom sum = 6 (even) → already valid → output `0`.

---

**Example 2**
```

1
2 3

```
Top sum = 2 (even), bottom sum = 3 (odd) → one even, one odd → impossible → output `-1`.

---

**Example 3**
```

3
1 4
2 3
4 4

```
Top sum = 7 (odd), bottom sum = 11 (odd). Domino `(1,4)` and `(2,3)` have mixed parity → rotate one → output `1`.

---

## Pseudocode

```

read n
topSum = 0
bottomSum = 0
canSwap = false

for i in 1..n:
read x, y
topSum += x
bottomSum += y
if (x + y) is odd:
canSwap = true

if topSum is even and bottomSum is even:
print 0
else if topSum is odd and bottomSum is odd and canSwap:
print 1
else:
print -1

```

---

## Complexity

- **Time Complexity:** `O(n)` — we iterate over the dominoes exactly once, performing constant-time work per domino.
- **Space Complexity:** `O(1)` — only a few integer and boolean variables are used, no arrays or extra data structures.