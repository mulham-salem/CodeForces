# Problem 154A – Hometask

## Overview
You are given a string `s` consisting of lowercase English letters.  
Some pairs of letters are **forbidden**, meaning they cannot appear next to each other in the final string (in any order).

You are allowed to delete characters from the string. After deletions, remaining characters shift and become adjacent.

The goal is to find the **minimum number of deletions** needed so that no forbidden adjacent pair appears.

---

## Key Idea
We process the string from left to right and maintain a dynamic programming state:

- `last` = the last character kept in the resulting string
- We decide for each character:
  - **Delete it**
  - **Keep it (only if it does not create a forbidden adjacent pair with `last`)**

Since each letter can only conflict with at most one other letter, we only need to track the last kept character.

We use DP to try all valid transitions and always keep the best (minimum deletions).

---

## State Definition
Let:

- `dp[last]` = minimum deletions after processing some prefix of the string,
  where `last` is the last kept character
- `last = 26` means "no character has been kept yet"

---

## Transitions (Idea)

For each character `cur`, we try:

### 1. Delete current character
We increase deletions by 1 and keep the same `last`.

### 2. Keep current character
We can keep it only if:
- no previous character exists (`last = 26`), OR
- `(last, cur)` is NOT a forbidden pair

If valid, `cur` becomes the new `last`.

We always keep the minimum cost among all possibilities.

---

## Why DP Works
At any point, different previous choices may lead to the same `last` state with different costs.  
We always keep the smallest cost using `min`, ensuring optimal results.

---

## Example

### Input

ababa 1 ab

### Explanation
Forbidden pair: `(a, b)`

We cannot have `a` next to `b`, so we must remove characters.

Optimal strategy removes two `b` characters.

### Output

2

---

## Example 2

### Input

codeforces 2 do cs

### Explanation
Forbidden pairs:
- `(d, o)`
- `(c, s)`

We remove only one character to break all violations.

### Output

1

---

## Complexity
- Time Complexity: `O(26 × n)`
- Space Complexity: `O(26)`

---