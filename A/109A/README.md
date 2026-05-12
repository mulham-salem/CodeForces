# Problem 109A – Lucky Sum of Digits

## Problem Summary

A lucky number is a number that contains only the digits `4` and `7`.

Given an integer `n`, find the smallest lucky number whose digits sum equals `n`.

If it is impossible to construct such a number, print `-1`.

---

## Examples

### Example 1

Input:
```text
11
```

Output:
```text
47
```

Explanation:

```text
4 + 7 = 11
```

`47` is the smallest possible lucky number.

---

### Example 2

Input:
```text
10
```

Output:
```text
-1
```

Explanation:

There is no combination of digits `4` and `7` whose sum equals `10`.

---

## Idea

Each digit contributes:

- `4` adds `4`
- `7` adds `7`

We try different counts of digit `7`, then check if the remaining value can be formed using digit `4`.

Among all valid answers, we choose the one with:

1. Minimum total digits
2. More `4`s at the beginning (to make the number smaller)

---

## Pseudocode

```
read n

best solution = not found

for every possible number of sevens:
    remaining = n - (sevens * 7)

    if remaining is divisible by 4:
        fours = remaining / 4

        choose the solution with minimum total digits

if no solution exists:
    print -1
else:
    print all 4's first
    print all 7's after them
```

---

## Complexity

- Time Complexity: `O(n)`
- Space Complexity: `O(1)`

---