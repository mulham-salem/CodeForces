# Problem 256A – Almost Arithmetical Progression

## Problem Summary

Given an array `b`, find the longest subsequence that forms an **almost arithmetical progression**.

Such a sequence has the form:

```text
A, B, A, B, A, B, ...
```
where `A` and `B` are two integer values.

The selected elements do not have to be adjacent in the original array, but their indices must remain in increasing order.

---

## Example 1
```
b = [3, 5]
```
The whole array is valid:
```
3, 5
```
**Answer:**
```
2
```

---

## Example 2
```
b = [10, 20, 10, 30]
```
We can choose:
```
10, 20, 10
```
The values alternate between `10` and `20`.

**Answer:**
```
3
```

---

## Example 3
```
b = [1, 5, 2, 5, 1]
```
A valid subsequence is:
```
1, 5, 1
```
or:
```
5, 2, 5
```
The longest valid subsequence has length `3`.

---

## Approach

Since a valid sequence always alternates between two values:
```
A → B → A → B → ...
```
we can use Dynamic Programming.

**Define:**
```
dp[i][x]
```
as the longest valid subsequence that:

ends at index `i`

has value `x` as the previous value

For every pair of indices `i < j`:

If `dp[i][b[j]]` is `0`, no previous sequence can be extended, so start a new sequence of length `2`.

Otherwise, extend the existing sequence by `b[j]`.

Update the state for index `j`.

Because the values of b can be as large as `10^6`, coordinate compression is used to replace each distinct value with a small index.

---

## Pseudocode
```
Read n and array b

Coordinate-compress all values in b

Create dp[n][number of distinct values], initially 0
answer = 1

For i from 0 to n - 1:
    For j from i + 1 to n - 1:

        If dp[i][b[j]] == 0:
            currentLength = 2
        Else:
            currentLength = dp[i][b[j]] + 1

        dp[j][b[i]] =
            max(dp[j][b[i]], currentLength)

        answer =
            max(answer, currentLength)

Print answer
```
---

## Complexity

**Time:** `O(n²)`

**Memory:** `O(n²)`

With `n ≤ 4000`, this approach is efficient enough for the given limits.

---